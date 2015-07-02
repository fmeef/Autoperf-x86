#include "mpi/ap_mpi.h"


// routine labels
static const char *label[MAX_MPI_IDS] = {
  [COMM_SIZE_ID] =         "MPI_Comm_size",
  [COMM_RANK_ID] =         "MPI_Comm_rank",
  [SEND_ID] =              "MPI_Send",
  [SSEND_ID] =             "MPI_Ssend",
  [RSEND_ID] =             "MPI_Rsend",
  [BSEND_ID] =             "MPI_Bsend",
  [ISEND_ID] =             "MPI_Isend",
  [ISSEND_ID] =            "MPI_Issend",
  [IRSEND_ID] =            "MPI_Irsend",
  [IBSEND_ID] =            "MPI_Ibsend",
  [SEND_INIT_ID] =         "MPI_Send_init",
  [SSEND_INIT_ID] =        "MPI_Ssend_init",
  [RSEND_INIT_ID] =        "MPI_Rsend_init",
  [BSEND_INIT_ID] =        "MPI_Bsend_init",
  [RECV_INIT_ID] =         "MPI_Recv_init",
  [RECV_ID] =              "MPI_Recv",
  [IRECV_ID] =             "MPI_Irecv",
  [SENDRECV_ID] =          "MPI_Sendrecv",
  [SENDRECV_REPLACE_ID] =  "MPI_Sendrecv_replace",
  [BUFFER_ATTACH_ID] =     "MPI_Buffer_attach",
  [BUFFER_DETACH_ID] =     "MPI_Buffer_detach",
  [PROBE_ID] =             "MPI_Probe",
  [IPROBE_ID] =            "MPI_Iprobe",
  [TEST_ID] =              "MPI_Test",
  [TESTANY_ID] =           "MPI_Testany",
  [TESTALL_ID] =           "MPI_Testall",
  [TESTSOME_ID] =          "MPI_Testsome",
  [WAIT_ID] =              "MPI_Wait",
  [WAITANY_ID] =           "MPI_Waitany",
  [WAITALL_ID] =           "MPI_Waitall",
  [WAITSOME_ID] =          "MPI_Waitsome",
  [START_ID] =             "MPI_Start",
  [STARTALL_ID] =          "MPI_Startall",
  [BCAST_ID] =             "MPI_Bcast",
  [BARRIER_ID] =           "MPI_Barrier",
  [GATHER_ID] =            "MPI_Gather",
  [GATHERV_ID] =           "MPI_Gatherv",
  [SCATTER_ID] =           "MPI_Scatter",
  [SCATTERV_ID] =          "MPI_Scatterv",
  [SCAN_ID] =              "MPI_Scan",
  [ALLGATHER_ID] =         "MPI_Allgather",
  [ALLGATHERV_ID] =        "MPI_Allgatherv",
  [REDUCE_ID] =            "MPI_Reduce",
  [ALLREDUCE_ID] =         "MPI_Allreduce",
  [REDUCE_SCATTER_ID] =    "MPI_Reduce_scatter",
  [ALLTOALL_ID] =          "MPI_Alltoall",
  [ALLTOALLV_ID] =         "MPI_Alltoallv",
  [ALLTOALLW_ID] =         "MPI_AlltoallW",
  [EXSCAN_ID] =            "MPI_Exscan",
  [FILE_CLOSE_ID] =                "MPI_File_close",
  [FILE_DELETE_ID] =               "MPI_File_delete",
  [FILE_IREAD_ID] =                "MPI_File_iread",
  [FILE_IREAD_AT_ID] =             "MPI_File_iread_at",
  [FILE_IREAD_SHARED_ID] =         "MPI_File_iread_shared",
  [FILE_IWRITE_ID] =               "MPI_File_iwrite",
  [FILE_IWRITE_AT_ID] =            "MPI_File_iwrite_at",
  [FILE_IWRITE_SHARED_ID] =        "MPI_File_iwrite_shared",
  [FILE_OPEN_ID] =                 "MPI_File_open",
  [FILE_PREALLOCATE_ID] =          "MPI_File_preallocate",
  [FILE_READ_ID] =                 "MPI_File_read",
  [FILE_READ_ALL_ID] =             "MPI_File_read_all",
  [FILE_READ_ALL_BEGIN_ID] =       "MPI_File_read_all_begin",
  [FILE_READ_ALL_END_ID] =         "MPI_File_read_all_end",
  [FILE_READ_AT_ID] =              "MPI_File_read_at",
  [FILE_READ_AT_ALL_ID] =          "MPI_File_read_at_all",
  [FILE_READ_AT_ALL_BEGIN_ID] =    "MPI_File_read_at_all_begin",
  [FILE_READ_AT_ALL_END_ID] =      "MPI_File_read_at_all_end",
  [FILE_READ_ORDERED_ID] =         "MPI_File_read_ordered",
  [FILE_READ_ORDERED_BEGIN_ID] =   "MPI_File_read_ordered_begin",
  [FILE_READ_ORDERED_END_ID] =     "MPI_File_read_ordered_end",
  [FILE_READ_SHARED_ID] =          "MPI_File_read_shared",
  [FILE_SEEK_ID] =                 "MPI_File_seek",
  [FILE_SEEK_SHARED_ID] =          "MPI_File_seek_shared",
  [FILE_SET_VIEW_ID] =             "MPI_File_set_view",
  [FILE_SYNC_ID] =                 "MPI_File_sync",
  [FILE_WRITE_ID] =                "MPI_File_write",
  [FILE_WRITE_ALL_ID] =            "MPI_File_write_all",
  [FILE_WRITE_ALL_BEGIN_ID] =      "MPI_File_write_all_begin",
  [FILE_WRITE_ALL_END_ID] =        "MPI_File_write_all_end",
  [FILE_WRITE_AT_ID] =             "MPI_File_write_at",
  [FILE_WRITE_AT_ALL_ID] =         "MPI_File_write_at_all",
  [FILE_WRITE_AT_ALL_BEGIN_ID] =   "MPI_File_write_at_all_begin",
  [FILE_WRITE_AT_ALL_END_ID] =     "MPI_File_write_at_all_end",
  [FILE_WRITE_ORDERED_ID] =        "MPI_File_write_ordered",
  [FILE_WRITE_ORDERED_BEGIN_ID] =  "MPI_File_write_ordered_begin",
  [FILE_WRITE_ORDERED_END_ID] =    "MPI_File_write_ordered_end",
  [FILE_WRITE_SHARED_ID] =         "MPI_File_write_shared",
};


// Flag to control data collection
static int disabled = 0;

// MPI data collected
static ap_mpiInfo_t mpiData[MAX_MPI_IDS];
static int myRank;
static int numRanks;
static double stdMpiTime;
static double mpiIoTime;


/*=========================================================*/
/* Function to initialize mpi performance data collection  */
/*=========================================================*/

int AP_MPI_Init(int disabledArg) {

  disabled = disabledArg;
  if (disabled != 0) return 0;

  /*-----------------------------------------*/
  /* initialize basic MPI event counters     */
  /*-----------------------------------------*/

  myRank = 0;
  numRanks = 1;
  stdMpiTime = 0.0;
  mpiIoTime = 0.0;

  int id;
  for (id=0; id<MAX_MPI_IDS; id++) {
    mpiData[id].callCount = 0LL;
    mpiData[id].totalCycles = (ap_cycle_t) 0;
    mpiData[id].totalBytes = 0.0;
    mpiData[id].totalTime = 0.0;
  }


  return 0;
}


/*==========================================================*/
/* Function to log events                                   */
/*   TODO: make thread safe                                 */
/*==========================================================*/

int AP_MPI_logCall(int id, ap_cycle_t TB1, ap_cycle_t TB2, int src, int dest, ap_bytes_t bytes, MPI_Comm comm) {

   /*---------------------------------------------------*/
   /* return immediately if not logging data            */
   /*---------------------------------------------------*/

   if (disabled != 0) return 0;

   /*---------------------------------------------------*/
   /* Log basic summary information                     */
   /*---------------------------------------------------*/

   mpiData[id].callCount++;
   mpiData[id].totalCycles += TB2-TB1;
   if (bytes >= 0) mpiData[id].totalBytes += (double) bytes;


   return 0;
}


/*==========================================================*/
/* Function to finalize automatic performance collection    */
/*==========================================================*/

int AP_MPI_Finalize() {

  /*--------------------------------------------------------*/
  /* return if autoperf is disabled                         */
  /*--------------------------------------------------------*/

   if (disabled != 0) return 0;

  /*---------------------------------*/
  /* collect general MPI information */
  /*---------------------------------*/

  PMPI_Comm_rank(MPI_COMM_WORLD, &myRank);
  PMPI_Comm_size(MPI_COMM_WORLD, &numRanks);

  /*----------------------------------------------------*/
  /* compute the total communication time for all tasks */
  /*----------------------------------------------------*/

  ap_cycle_t totalCyc = 0LL;

  int id;
  for (id=0; id<MIN_MPI_IO_ID; id++) {
    if (mpiData[id].callCount > 0LL) {
      totalCyc += mpiData[id].totalCycles;
      mpiData[id].totalTime = APCTCONV(mpiData[id].totalCycles);
    }
  }

  stdMpiTime = APCTCONV(totalCyc);

  /*-------------------------------------------*/
  /* compute the total time in MPI-IO routines */
  /*-------------------------------------------*/

  ap_cycle_t mpiIoCyc = 0LL;

  for (id=MIN_MPI_IO_ID; id<MAX_MPI_IDS; id++) {
    if (mpiData[id].callCount > 0LL) {
      mpiIoCyc += mpiData[id].totalCycles;
      mpiData[id].totalTime = APCTCONV(mpiData[id].totalCycles);
    }
  }

  mpiIoTime = APCTCONV(mpiIoCyc);


  return 0;
}


/*=========================================================*/
/* Function to return mpi data                             */
/*=========================================================*/
int AP_MPI_GetData(ap_mpiData_t* data) {

  /*--------------------------------------------------------*/
  /* return if autoperf is disabled                         */
  /*--------------------------------------------------------*/

  data->disabled = disabled;
  if (disabled != 0) return 0;

  /*-----------*/
  /* copy data */
  /*-----------*/

  data->myRank = myRank;
  data->numRanks = numRanks;
  data->stdMpiTime = stdMpiTime;
  data->mpiIoTime = mpiIoTime;

  int id;
  for (id=0; id<MAX_MPI_IDS; id++) {
    data->mpiRoutineData[id].callCount = mpiData[id].callCount;
    data->mpiRoutineData[id].totalCycles = mpiData[id].totalCycles;
    data->mpiRoutineData[id].totalBytes = mpiData[id].totalBytes;
    data->mpiRoutineData[id].totalTime = mpiData[id].totalTime;
  }


  return 0;
}


/*=========================================================*/
/* Function to return mpi function name                    */
/*=========================================================*/
const char* AP_MPI_GetFuncName(int id) {

  static const char emptyString = '\0';

  const char *name;
  if (id < 0 || id > MAX_MPI_IDS-1) {
    name = &emptyString;
  } else  {
    name = label[id];
  }

  return name;
}
