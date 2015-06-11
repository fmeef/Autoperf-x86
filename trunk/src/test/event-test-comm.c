#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
//#include <stddef.h>
//#include <math.h>
//#include "bgpm/include/bgpm.h"

//#ifdef MPI
//#include "mpi.h"
//#endif

#ifdef _OPENMP
#include <omp.h>  
#endif

#define FLAGS "hpfns:i:b:t:c:l:e:m:"
#define MAX_EXPECTED 64
#define xstr(s) str(s)
#define str(s) #s

//#include "events.h"

///* External functions */

uint64_t doWork(int its, void *mem1, void *mem2, void *mem3);


///* types */

typedef struct {
  int preExec;
  int baseIts;
  int scaleIts;
  int memBytes;
  int threads;
  int fast;
  int initialize;
  int hwDist;
  int memBlocks;
  char *counters1;
  char *counters2;
  char *expected[MAX_EXPECTED];
} Parameters_t;

//typedef struct {
//  int counter;
//  int baseCount;
//  int perItCount;
//} Expected_t;

//typedef struct {
//  int id;
//  uint64_t count;
//} Counter_t;


/* convertTestToInt */

int convertTextToInt(char *text, int *value) {
  errno = 0;
  char *extra;
  *value = (int) strtol(text, &extra, 10);

  if (errno != 0 || strlen(extra) != 0) {
    return 1;
  }

  return 0;
}


/*
 * Parse arguements:
 * -p : execute doWork() once before starting counters
 * -h : use hardware distributed mode
 * -f : use fast handle controls to start and stop P Unit counters
 * -n : initialize memory buffer
 * -i : base iterations
 * -s : additional iterations scaling with task id
 * -b : number of bytes in memory buffer per thread per block
 * -t : number of threads
 * -c : P counters to use as start:num or cntr1,cntr2,cntr3
 * -l : L2 counters to use as start:num or cntr1,cntr2,cntr3
 * -e : expected values as cntr,base-count,count-per-it
 * -m : memory blocks per thread
*/

int getParameters(int argc, char **argv, Parameters_t *params) {

  char flagString[]= xstr(FLAGS);
  int expectedCount = 0;

  opterr = 0;
  int flag;
  while ((flag = getopt(argc, argv, flagString)) != -1) {
    switch (flag) {
      case 'p': {
        params->preExec = 1;

        break;
      }
      case 'f': {
        params->fast = 1;

        break;
      }
      case 'h': {
        params->hwDist = 1;

        break;
      }
      case 'n': {
        params->initialize = 1;

        break;
      }
      case 'i': {
          int value;
          int returnValue = convertTextToInt(optarg, &value);

          params->baseIts = value;

        break;
      }
      case 's': {
          int value;
          int returnValue = convertTextToInt(optarg, &value);

          params->scaleIts = value;

        break;
      }
      case 'b': {
          int value;
          int returnValue = convertTextToInt(optarg, &value);

          params->memBytes = value;

        break;
      }
      case 't': {
          int value;
          int returnValue = convertTextToInt(optarg, &value);

          params->threads = value;

        break;
      }
      case 'm': {
          int value;
          int returnValue = convertTextToInt(optarg, &value);

          params->memBlocks = value;

        break;
      }
      case 'c': {
        params->counters1 = optarg;

        break;
      }
      case 'l': {
        params->counters2 = optarg;

        break;
      }
      case 'e': {
        if (expectedCount < MAX_EXPECTED) {
          params->expected[expectedCount] = optarg;
          expectedCount++;
        }

        break;
      }
      case '?': {
        if (isprint(optopt)) {
          fprintf(stderr, "Unknown option `-%c'.\n", optopt);
        } else {
          fprintf(stderr,"Unknown option character `\\x%x'.\n", optopt);
        }

        return 1;
        break;
      }
    }
  }

  return 0;
}


/* configEvents */

//void getEvents(char *counters, unsigned int **eventListPtr, unsigned int *listSize) {

//  if (counters == NULL) {
//    *eventListPtr = NULL;
//    listSize = 0;
//    return;
//  }

//  char *colonPtr = strchr(counters, (int) ':'); 
//  char buffer[512];

//  if (colonPtr != NULL) {
//    int value, returnValue;

//    char *numCounters = colonPtr+1;
//    returnValue = convertTextToInt(numCounters, &value);
//    *listSize = (unsigned int) value;  

//    int numChars = colonPtr - counters;
//    strncpy(buffer, counters, numChars);
//    buffer[numChars] = '\0';
//    returnValue = convertTextToInt(buffer, &value);

//    *eventListPtr = malloc(sizeof(unsigned int)*(*listSize));

//    for (int i= 0; i < *listSize; i++) {
//      (*eventListPtr)[i] = events[value];
//      value++;
//    }
//  } else {
//    strncpy(buffer, counters, 512);
//    *listSize = 0;
//    for ( char *textVal = strtok(buffer,","); textVal != NULL; textVal = strtok(NULL, ",") ) {
//      (*listSize)++;
//    }

//    *eventListPtr = malloc(sizeof(unsigned int)*(*listSize));

//    strncpy(buffer, counters, 512);
//    int count = 0;
//    for ( char *textVal = strtok(buffer,","); textVal != NULL; textVal = strtok(NULL, ",") ) {
//      int value, returnValue;
//      returnValue = convertTextToInt(textVal, &value);

//      (*eventListPtr)[count] = events[value];
//      count++;
//    }
//  }

//  return;
//}


///* parse expected values */
//
//void getExpectedValues(char *expected[], Expected_t **expectedVals, int *numExpected) {
//
//  *numExpected = 0;
//  while ((expected[*numExpected] != NULL) && (*numExpected < MAX_EXPECTED)) {
//    (*numExpected)++;
//  }
//
//  *expectedVals = malloc(sizeof(Expected_t)*(*numExpected));
//
//  char buffer[512];
//  int i = 0;
//  while ((expected[i] != NULL) && (i < MAX_EXPECTED)) {
//
//    strncpy(buffer, expected[i], 512);
//
//    int value;
//    char *text;
//
//    text = strtok(buffer,",");
//    convertTextToInt(text, &value);
//    (*expectedVals)[i].counter = value;
//
//    text = strtok(NULL, ",");
//    convertTextToInt(text, &value);
//    (*expectedVals)[i].baseCount = value;
//
//    text = strtok(NULL, ",");
//    convertTextToInt(text, &value);
//    (*expectedVals)[i].perItCount = value;
//
//    i++;
//  }
//  
//  return;
//}


///* main */
//
int main (int argc, char *argv[]) {

//  #ifdef MPI
//    MPI_Init(&argc,&argv);
//  #endif

//  int myRank = 0;
//  int numProcs = 1;
//  #ifdef MPI
//    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
//    MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
//  #endif

  // intialize paramters to default and get parameters from command line

  Parameters_t params;
  params.preExec= 0;
  params.counters1= NULL;
  params.counters2= NULL;
  params.baseIts= 0;
  params.scaleIts= 1;
  params.memBytes= 1024;
  params.threads= 1;
  params.fast= 0;
  params.hwDist= 0;
  params.memBlocks= 1;
  params.initialize= 0;

  for (int i = 0; i < MAX_EXPECTED; i++) {
    params.expected[i] = NULL;
  }

//  if (myRank == 0) printf("Reading parameter-\n");
  getParameters(argc, argv, &params);

//  if (myRank == 0) {
//    printf("  preExec = %d\n", params.preExec);
//    printf("  counters1 = %s\n", params.counters1);
//    printf("  counters2 = %s\n", params.counters2);
//    printf("  baseIts = %d\n", params.baseIts);
//    printf("  scaleIts = %d\n", params.scaleIts);
//    printf("  bytes = %d\n", params.memBytes);
//    printf("  memBlocks = %d\n", params.memBlocks);
//    printf("  threads = %d\n", params.threads);
//    printf("  fast = %d\n", params.fast);
//    printf("  hw dist = %d\n", params.hwDist);
//    printf("  initialize = %d\n", params.initialize);
//
//    for (int i = 0; i < MAX_EXPECTED; i++) {
//      if (params.expected[i] != NULL) {
//        printf("  expected[%d] = %s\n", i, params.expected[i]);
//      }
//    }
//  }

  // Get list of counters to use

//unsigned int *eventList1;
//unsigned int listSize1;
//getEvents(params.counters1, &eventList1, &listSize1);

//  if (myRank == 0) {
//    printf("\nParsed core counters: ");
//    for (int i= 0; i < listSize1; i++) {
//      printf("%d, ", eventList1[i]);
//    }
//    printf("\n");
//  }

//  unsigned int *eventList2;
//  unsigned int listSize2;
//  getEvents(params.counters2, &eventList2, &listSize2);

//  if (myRank == 0) {
//    printf("\nParsed L2 counters: ");
//    for (int i= 0; i < listSize2; i++) {
//      printf("%d, ", eventList2[i]);
//    }
//    printf("\n");
//  }

  // Get list expected values

//  int numExpected = 0;
//  Expected_t *expectedVals;

//  getExpectedValues(params.expected, &expectedVals, &numExpected);

//  if (myRank == 0) {
//    printf("\nParsed expected values:\n");
//    for (int i= 0; i < numExpected; i++) {
//      printf("  expected[%d] = (counter=%d) (base= %d) (iter= %d)\n", i, expectedVals[i].counter, expectedVals[i].baseCount, expectedVals[i].perItCount);
//    }
//    printf("\n");
//  }

  // reserve memory space and align buffer at L2 cache line

  char *buffer1, *buffer2, *buffer3;
  size_t memReq = ((long long) params.memBytes) * ((long long) params.threads) + 128LL;

//  if (myRank == 0) printf("Allocating memory buffer 1 of %lld bytes\n",
//                          (long long) params.memBytes * (long long)params.threads);

  char *tBuffer = malloc(memReq);
  if (tBuffer == NULL) {
    printf("  error with malloc 1\n");
    exit(1);
  }

  if (((long long) tBuffer)%128 != 0) {
    buffer1 = tBuffer + 128 - ((long long) tBuffer)%128;
  } else {
    buffer1 = tBuffer;
  }

  if (params.memBlocks > 1) {
//    if (myRank == 0) printf("Allocating memory buffer 2 of %lld bytes\n",
//                            (long long) params.memBytes * (long long)params.threads);

    tBuffer = malloc(memReq);
    if (tBuffer == NULL) {
      printf("  error with malloc 2\n");
      exit(1);
    }

    if (((long long) tBuffer)%128 != 0) {
      buffer2 = tBuffer + 128 - ((long long) tBuffer)%128;
    } else {
      buffer2 = tBuffer;
    }
  }

  if (params.memBlocks > 2) {
//    if (myRank == 0) printf("Allocating memory buffer 3 of %lld bytes\n",
//                            (long long) params.memBytes * (long long)params.threads);

    tBuffer = malloc(memReq);
    if (tBuffer == NULL) {
      printf("  error with malloc 3\n");
      exit(1);
    }

    if (((long long) tBuffer)%128 != 0) {
      buffer3 = tBuffer + 128 - ((long long) tBuffer)%128;
    } else {
      buffer3 = tBuffer;
    }
  }

  // specify the number of threads if using OpenMP

  #ifdef _OPENMP
    omp_set_num_threads(params.threads);
  #endif

  // initialize and configure bgpm if hw dist

//  int hwDistEvtSet1, hwDistEvtSet2;
//  if (params.hwDist != 0) {
//    if (myRank == 0) printf("Initializing bgpm in HW dist mode-\n");
//
//    int retVal = Bgpm_Init(BGPM_MODE_HWDISTRIB);
//    if (retVal !=0) {
//      printf("  ** Initialization error 1\n");
//      exit(1);
//    }

//    if (myRank == 0) printf("Configuring events-\n");

//    if (listSize1 > 0) {
//      hwDistEvtSet1 = Bgpm_CreateEventSet();
//      if (hwDistEvtSet1 < 0) {
//        printf("  ** event set creation error\n");
//        exit(1);
//      }

//      retVal = Bgpm_AddEventList(hwDistEvtSet1, eventList1, listSize1);
//      if (retVal !=0) {
//        printf("  ** Initialization error 2\n");
//        exit(1);
//      }

//      int numEvents = Bgpm_NumEvents(hwDistEvtSet1);
//      if (numEvents != listSize1) {
//        printf("  ** Initialization error, numEvents != listSize1\n");
//        exit(1);
//      }

//      uint64_t thdMask = Kernel_ThreadMask(Kernel_MyTcoord());

//      retVal = Bgpm_Attach(hwDistEvtSet1, thdMask, 0);
//      if (retVal !=0) {
//        printf("  ** Initialization error 3\n");
//        exit(1);
//      }
//    }

//    if (listSize2 > 0) {
//      hwDistEvtSet2 = Bgpm_CreateEventSet();
//      if (hwDistEvtSet2 < 0) {
//        printf("  ** event set creation error\n");
//        exit(1);
//      }

//      retVal = Bgpm_AddEventList(hwDistEvtSet2, eventList2, listSize2);
//      if (retVal !=0) {
//        printf("  ** Initialization error 2\n");
//        exit(1);
//      }

//      int numEvents = Bgpm_NumEvents(hwDistEvtSet2);
//      if (numEvents != listSize2) {
//        printf("  ** Initialization error, numEvents != listSize2\n");
//        exit(1);
//      }

//      retVal = Bgpm_Apply(hwDistEvtSet2);
//      if (retVal !=0) {
//        printf("  ** Initialization error 3\n");
//        exit(1);
//      }
//    }
//  }

  // allocate array for cycle count and its

  uint64_t *cycles = malloc(sizeof(uint64_t)*(params.threads));
  int *itsList = malloc(sizeof(int)*(params.threads));
  int *hwThdList = malloc(sizeof(int)*(params.threads));
//  Counter_t counts[params.threads][listSize1 + listSize2];

  #pragma omp parallel
  {
    // get thread id

    int threadId = 0;
    int numThreads= 1;
    #ifdef _OPENMP
      threadId = omp_get_thread_num();
      numThreads = omp_get_num_threads();
    #endif

    int hwThdId  = (int) Kernel_ProcessorID();
    hwThdList[threadId] = hwThdId;

    // calculate task number

//    int taskNum = myRank*numThreads + threadId;

    // initialize memory buffers

    char *mem1 = &(buffer1[(long long) params.memBytes * (long long)threadId]);
    if (params.initialize != 0) {
//    #pragma omp master
//    {
//        if (myRank == 0) printf("Initializing memory buffer 1 - \n");
//    }

      for (unsigned int i= 0; i< params.memBytes; i++) {
        mem1[i] = 0x0;
      }
    }

    char *mem2;
    if (params.memBlocks > 1) {
      mem2 = &(buffer2[(long long) params.memBytes * (long long)threadId]);
      if (params.initialize != 0) {
//        #pragma omp master
//        {
//          if (myRank == 0) printf("Initializing memory buffer 2 - \n");
//        }

        for (unsigned int i= 0; i< params.memBytes; i++) {
          mem2[i] = 0x0;
        }
      }
    }

    char *mem3;
    if (params.memBlocks > 2) {
      mem3 = &(buffer3[(long long) params.memBytes * (long long)threadId]);
      if (params.initialize != 0) {
//        #pragma omp master
//        {
//          if (myRank == 0) printf("Initializing memory buffer 3 - \n");
//        }

        for (unsigned int i= 0; i< params.memBytes; i++) {
          mem3[i] = 0x0;
        }
      }
    }

    // determine number of iterations

//    int its = params.baseIts + params.scaleIts*taskNum;
//    itsList[threadId] = its;

    // initialize and configure bgpm if sw dist mode

//    int swDistEvtSet1, swDistEvtSet2;
//    uint64_t mask;
//    if (params.hwDist == 0) {
//      #pragma omp master
//      {
//        if (myRank == 0) printf("Initializing bgpm in SW dist mode-\n");
//      }

//      int retVal = Bgpm_Init(BGPM_MODE_SWDISTRIB);
//      if (retVal !=0) {
//        printf("  ** Initialization error 1\n");
//        exit(1);
//      }

      // configure events

//      #pragma omp master
//      {
//        if (myRank == 0) printf("Configuring events-\n");
//      }

//      if (listSize1 > 0) {
//        swDistEvtSet1 = Bgpm_CreateEventSet();
//        if (swDistEvtSet1 < 0) {
//          printf("  ** event set creation error\n");
//          exit(1);
//        }

//        retVal = Bgpm_AddEventList(swDistEvtSet1, eventList1, listSize1);
//        if (retVal !=0) {
//          printf("  ** Initialization error 2\n");
//          exit(1);
//        }

//        int numEvents = Bgpm_NumEvents(swDistEvtSet1);
//        if (numEvents != listSize1) {
//          printf("  ** Initialization error, numEvents != listSize1\n");
//          exit(1);
//        }

        // apply event set to counters

//        retVal = Bgpm_Apply(swDistEvtSet1);
//        if (retVal !=0) {
//          printf("  ** initialization error 3\n");
//          exit(1);
//        }

      // get fast access handle

//        if (params.fast != 0) {
//          Bgpm_Reset(swDistEvtSet1);

//          Bgpm_Punit_Handles_t pH;
//          retVal = Bgpm_Punit_GetHandles(swDistEvtSet1, &pH);
//          if (retVal != 0) {
//            printf("  ** Bgpm_Punit_GetHandles() error");
//            exit(1);
//          }

//          mask = pH.allCtrMask;
//        }
//      }

//      if (listSize2 > 0) {
//        swDistEvtSet2 = Bgpm_CreateEventSet();
//        if (swDistEvtSet2 < 0) {
//          printf("  ** event set creation error\n");
//          exit(1);
//        }

//        retVal = Bgpm_AddEventList(swDistEvtSet2, eventList2, listSize2);
//        if (retVal !=0) {
//          printf("  ** Initialization error 2\n");
//          exit(1);
//        }

//        int numEvents = Bgpm_NumEvents(swDistEvtSet2);
//        if (numEvents != listSize2) {
//          printf("  ** Initialization error, numEvents != listSize2\n");
//          exit(1);
//        }

//        retVal = Bgpm_Apply(swDistEvtSet2);
//        if (retVal !=0) {
//          printf("  ** Initialization error 3\n");
//          exit(1);
//        }
//      }
//    }

    // call routine once to load into cache

    #pragma omp barrier

//    #pragma omp master
//    {
//      if (myRank == 0) {
//        printf("Starting tests\n");
//        if (params.preExec != 0) {
//          printf("  Preliminary iteration before starting counters\n");
//        }
//      }
//
//      #ifdef MPI
//        MPI_Barrier(MPI_COMM_WORLD);
//      #endif
//    }

    #pragma omp barrier

    if (params.preExec == 1) {
      doWork(its, mem1, mem2, mem3);
    }

    #pragma omp barrier

//    #pragma omp master
//    {
//      #ifdef MPI
//        MPI_Barrier(MPI_COMM_WORLD);
//      #endif
//    }

    #pragma omp barrier

    // Start counting

//    if (params.hwDist != 0) {
//      #pragma omp master
//      {
//        if (listSize2 > 0) Bgpm_Start(hwDistEvtSet2);
//        if (listSize1 > 0) Bgpm_Start(hwDistEvtSet1);
//      }    
//      #pragma omp barrier
//    } else if (params.fast != 0) {
//      if (listSize2 > 0) Bgpm_Start(swDistEvtSet2);
//      if (listSize1 > 0) Bgpm_Punit_Start(mask);
//    } else {
//      if (listSize2 > 0) Bgpm_Start(swDistEvtSet2);
//      if (listSize1 > 0) Bgpm_Start(swDistEvtSet1);
//    }

    // do work

    uint64_t tCyc = doWork(its, mem1, mem2, mem3);

    // Stop counting

//    if (params.hwDist != 0) {
//      #pragma omp barrier
//
//      #pragma omp master
//      {
//        #ifdef MPI
//          MPI_Barrier(MPI_COMM_WORLD);
//        #endif
//  
//        if (listSize1 > 0) Bgpm_Stop(hwDistEvtSet1);
//        if (listSize2 > 0) Bgpm_Stop(hwDistEvtSet2);
//      }

//      #pragma omp barrier
//    } else if (params.fast != 0) {
//      if (listSize1 > 0 ) {
//        Bgpm_Punit_Stop(mask);
//        Upci_Delay(800);
//      }

//      #pragma omp barrier
//      #pragma omp master
//      {
//        #ifdef MPI
//          MPI_Barrier(MPI_COMM_WORLD);
//        #endif
//        if (listSize2 > 0) Bgpm_Stop(swDistEvtSet2);
//      }
//      #pragma omp barrier
//    } else {
//      if (listSize1 > 0) Bgpm_Stop(swDistEvtSet1);

//      #pragma omp barrier
//      #pragma omp master
//      {
//        #ifdef MPI
//          MPI_Barrier(MPI_COMM_WORLD);
//        #endif
//        if (listSize2 > 0) Bgpm_Stop(swDistEvtSet2);
//      }
//      #pragma omp barrier
//    }

    cycles[threadId] = tCyc;

    // Collect counter data if in sw dist mode

//    if (params.hwDist == 0) {
//      for (int i=0; i<listSize1; i++) {
//        uint64_t cnt;
//        int retVal = Bgpm_ReadEvent(swDistEvtSet1, i, &cnt);
//        if (retVal != 0) {
//          printf("  ** Bgpm_ReadEvent error\n");
//          exit(1);
//        }

//        int id = Bgpm_GetEventId(swDistEvtSet1, i);
//        if (id < 1) {
//          printf("  ** Bgpm_GetEventId error\n");
//          exit(1);
//        }

//        counts[threadId][i].id = id;
//        counts[threadId][i].count= cnt;
//      }

//      for (int i=0; i<listSize2; i++) {
//        uint64_t cnt;
//        int retVal = Bgpm_ReadEvent(swDistEvtSet2, i, &cnt);
//        if (retVal != 0) {
//          printf("  ** Bgpm_ReadEvent error\n");
//          exit(1);
//        }

//        int id = Bgpm_GetEventId(swDistEvtSet2, i);
//        if (id < 1) {
//          printf("  ** Bgpm_GetEventId error\n");
//          exit(1);
//        }

//        counts[threadId][listSize1+i].id = id;
//        counts[threadId][listSize1+i].count= cnt;
//      }
//    }
  }

  // collect counter data if in hw dist mode

//  if (params.hwDist != 0) {
//    for(int k = 0; k < params.threads; k++) {

//      uint64_t curThdMask = UPC_APP_HWTID_MASK(hwThdList[k]);

//      for (int i=0; i<listSize1; i++) {
//        uint64_t cnt;
//        int retVal = Bgpm_ReadThreadEvent(hwDistEvtSet1, i, curThdMask, 0, &cnt);
//        if (retVal != 0) {
//          printf("  ** Bgpm_ReadEvent error\n");
//          exit(1);
//        }

//        int id = Bgpm_GetEventId(hwDistEvtSet1, i);
//        if (id < 1) {
//          printf("  ** Bgpm_GetEventId error\n");
//          exit(1);
//        }

//        counts[k][i].id = id;
//        counts[k][i].count= cnt;
//      }

//      for (int i=0; i<listSize2; i++) {
//        uint64_t cnt;
//        int retVal = Bgpm_ReadEvent(hwDistEvtSet2, i, &cnt);
//        if (retVal != 0) {
//          printf("  ** Bgpm_ReadEvent error\n");
//          exit(1);
//        }

//        int id = Bgpm_GetEventId(hwDistEvtSet2, i);
//        if (id < 1) {
//          printf("  ** Bgpm_GetEventId error\n");
//          exit(1);
//        }

//        counts[k][listSize1+i].id = id;
//        counts[k][listSize1+i].count= cnt;
//      }
//    }
//  }

//  // print results

//  if (myRank == 0) printf("\nResults-\n");

//  #ifdef MPI
//    MPI_Barrier(MPI_COMM_WORLD);
//
//    if (myRank !=0) {
//      int flag;
//      MPI_Status status;
//      MPI_Recv(&flag, 1, MPI_INT, myRank-1, 0, MPI_COMM_WORLD, &status);
//    }
//  #endif

//  double relError = 0.0;

//  for(int k = 0; k < params.threads; k++) {

//    printf("(%i-%i)  cycles = %llu\n", myRank, k, cycles[k]);

//    for (int i=0; i < listSize1+listSize2; i++) {

//      uint64_t cnt = counts[k][i].count;
//      int id = counts[k][i].id;

//      uint64_t expVal = 0;
//      if (id == 211) {
//        expVal = cycles[k];
//      } else {
//        for (int j = 0; j < numExpected; j++) {
//          if (expectedVals[j].counter == id) {
//            expVal = itsList[k]*expectedVals[j].perItCount + expectedVals[j].baseCount;
//          }
//        }
//      }

//      int error = (int) cnt-expVal;
//      double taskRelError = fabs((double) error)/((double) expVal);
//      if (taskRelError > relError) {
//        relError = taskRelError;
//      }

//      printf("(%i-%i)  %s = %llu (%llu, %d, %f)\n", myRank, k, Bgpm_GetEventIdLabel(id), cnt,
//             expVal, error, taskRelError);
//    }
//  }

//  #ifdef MPI
//    if (myRank != numProcs-1) {
//      int flag;
//      MPI_Send(&flag, 1, MPI_INT, myRank+1, 0, MPI_COMM_WORLD);
//    }
//  #endif

//  double glblMaxRelError= relError;
//  #ifdef MPI
//    MPI_Reduce(&relError, &glblMaxRelError, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
//  #endif

    int returnCode = 0;
//  if (myRank == 0) {
//    if (glblMaxRelError > 0.01) {
//      returnCode = 1;
//      printf("\n  Test Failed (%f)\n", glblMaxRelError);
//    } else {
//      returnCode = 0;
//      printf("\n  Test Passed (%f)\n", glblMaxRelError);
//    }
//  }

//  #ifdef MPI
//    MPI_Finalize();
//  #endif


  return returnCode;
}
