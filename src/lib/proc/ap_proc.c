#include <hwloc.h>
#include "time/ap_time.h"
#include <unistd.h>
#include <errno.h>
#include "proc/ap_proc.h"
#include <sys/sysinfo.h>
#include <linux/version.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <uuid/uuid.h>
// control flag



//job id



// memory information  
uint64_t heapMaxUsed;


//hwloc topology tree
hwloc_topology_t topo;



disabled = 0;

/*==========================================================*/
/* Function to initialize data collection                   */
/*==========================================================*/

int AP_Proc_Init(int disabledArg) {
  // cycle and time variables
  tmpStartCycle = 0;
  tmpStopCycle = 0;
  tmpElapsedCycles = 0;
  tmpElapsedTime = 0.0;
  disabled = 0;
  
  /*-------------------------------------------------------*/
  /* set collection control, return if not collecting data */
  /*-------------------------------------------------------*/
  
  disabled = disabledArg;
  if (disabled != 0) return 0;


  if(-1==hwloc_topology_init(&topo))
    printf("ERR: hwloc topology init failed (%i)\n",__LINE__);
  if(-1==hwloc_topology_load(topo))
    printf("ERR: hwloc topology load failed (%i)\n", __LINE__);;
  
  return 0;
}



/*==========================================================*/
/* Function to start data collection                        */
/*   Starts process timer                                   */
/*==========================================================*/

int AP_Proc_Start() {

  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/
  printf("START!\n");
  if (disabled != 0) return 0;

  /*---------------------*/
  /* Start process timer */
  /*---------------------*/

  APCYCLES(tmpStartCycle);
  APTIME(startWallclock);

  return 0;
}


/*==========================================================*/
/* Function to stop data collection                         */
/*  stops process timer                                     */
/*==========================================================*/

int AP_Proc_Stop() {

  printf("STOP!\n");
  
  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/

  if (disabled != 0) return 0;

  /*--------------------*/
  /* Stop process timer */
  /*--------------------*/

  APCYCLES(tmpStopCycle);
  APTIME(endWallclock);

  return 0;
}


/*==========================================================*/
/* Function to finalize data collection                     */
/*==========================================================*/

int AP_Proc_Finalize() {

  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/

  if (disabled != 0) return 0;


  
  /*--------------------------------*/
  /* Get cores and hardware threads */
  /*--------------------------------*/


  struct sysinfo sinfo;
  int runningprocs;
  if(sysinfo(&sinfo)==0) {
    runningprocs = (int) sinfo.procs;
  }
  else {
    printf("%s ]] ERR: failed to get running procs\n",__LINE__);
    runningprocs = (int) -1;
  }
  numProcessesOnNode = runningprocs;
  processHWThreads = (int) hwloc_get_nbobjs_by_type(topo, HWLOC_OBJ_PU);
  

  /*------------------------*/
  /* Get memory information */
  /*------------------------*/
  
  //Kernel_GetMemorySize(KERNEL_MEMSIZE_HEAPMAX, &heapMaxUsed);


  /* get the heap usage of the process, 0 if kernel does not support (not really) */


  struct rusage us;
  getrusage(RUSAGE_SELF, &us);
  //heapMaxUsed =0;
  heapMaxUsed = us.ru_maxrss;
  return 0;
}



/*==========================================================*/
/* Function to return collected data                        */
/*==========================================================*/

int AP_Proc_GetData(ap_procData_t* data) {

  /*--------------------------------*/
  /* Determine process elapsed time */
  /*--------------------------------*/

  tmpElapsedCycles = tmpStopCycle-tmpStartCycle;
  double tmpElepasedTime =  endWallclock - startWallclock;



  /*get cobalt job id*/
  //const char * tmpid = getenv("COBALT_JOBID");
  //printf("cobalt job id: %d",tmpid);

  
  /*------------*/
  /* Get Job Id */
  /*------------*/
  
  char id[39];
  uuid_generate_time(&jobId);
  uuid_unparse(jobId, id);
  
  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/

  data->disabled = disabled;
  if (disabled != 0) return 0;

  /*-----------------------*/
  /* Copy data into struct */
  /*-----------------------*/

  data->startCycle = tmpStartCycle;
  data->stopCycle = tmpStopCycle;
  data->elapsedCycles = tmpElapsedCycles;
  data->elapsedTime = tmpElapsedTime;
  uuid_copy(data->jobId, jobId);
  data->numProcessesOnNode = numProcessesOnNode;
  data->processHWThreads = processHWThreads;
  data->heapMaxUsed = heapMaxUsed;
  //  data->cobaltId = malloc(8);
  // strcpy(data->cobaltId,tmpid);

  return 0;
}
