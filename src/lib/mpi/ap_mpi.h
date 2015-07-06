#include "mpi.h"
#include "time/ap_time.h"

/*==========================================================*/
/* define types                                             */
/*==========================================================*/

#define MAX_MPI_IDS  87
#define NOSRC -1
#define NODEST -1
#define NOBYTES -1

typedef long long ap_bytes_t;

typedef struct {
  long long callCount;
  ap_cycle_t totalCycles;
  double totalBytes;
  double totalTime;
} ap_mpiInfo_t;

typedef struct {
  int disabled;
  int myRank, numRanks;
  double stdMpiTime, mpiIoTime;
  ap_mpiInfo_t mpiRoutineData[MAX_MPI_IDS];
} ap_mpiData_t;

/*==========================================================*/
/* Function prototypes                                      */
/*==========================================================*/

int AP_MPI_Init(int );
int AP_MPI_logCall(int, ap_cycle_t, ap_cycle_t, int, int, ap_bytes_t, MPI_Comm);
int AP_MPI_Finalize(void);
int AP_MPI_GetData(ap_mpiData_t *);
const char* AP_MPI_GetFuncName(int);

/*----------------------------------------------------------*/
/*    integer IDs for MPI functions                         */
/*----------------------------------------------------------*/


#define COMM_SIZE_ID                   0
#define COMM_RANK_ID                   1
#define SEND_ID                        2
#define SSEND_ID                       3 
#define RSEND_ID                       4 
#define BSEND_ID                       5
#define ISEND_ID                       6
#define ISSEND_ID                      7
#define IRSEND_ID                      8
#define IBSEND_ID                      9
#define SEND_INIT_ID                  10
#define SSEND_INIT_ID                 11
#define RSEND_INIT_ID                 12
#define BSEND_INIT_ID                 13
#define RECV_INIT_ID                  14
#define RECV_ID                       15
#define IRECV_ID                      16
#define SENDRECV_ID                   17
#define SENDRECV_REPLACE_ID           18
#define BUFFER_ATTACH_ID              19
#define BUFFER_DETACH_ID              20
#define PROBE_ID                      21
#define IPROBE_ID                     22
#define TEST_ID                       23
#define TESTANY_ID                    24
#define TESTALL_ID                    25
#define TESTSOME_ID                   26
#define WAIT_ID                       27
#define WAITANY_ID                    28
#define WAITALL_ID                    29
#define WAITSOME_ID                   30
#define START_ID                      31
#define STARTALL_ID                   32
#define BCAST_ID                      33
#define BARRIER_ID                    34
#define GATHER_ID                     35
#define GATHERV_ID                    36
#define SCATTER_ID                    37
#define SCATTERV_ID                   38
#define SCAN_ID                       39
#define ALLGATHER_ID                  40
#define ALLGATHERV_ID                 41
#define REDUCE_ID                     42
#define ALLREDUCE_ID                  43
#define REDUCE_SCATTER_ID             44
#define ALLTOALL_ID                   45
#define ALLTOALLV_ID                  46
#define ALLTOALLW_ID                  47
#define EXSCAN_ID                     48

#define MIN_MPI_IO_ID                 49

#define FILE_CLOSE_ID                 49
#define FILE_DELETE_ID                50
#define FILE_IREAD_ID                 51
#define FILE_IREAD_AT_ID              52
#define FILE_IREAD_SHARED_ID          53
#define FILE_IWRITE_ID                54
#define FILE_IWRITE_AT_ID             55
#define FILE_IWRITE_SHARED_ID         56
#define FILE_OPEN_ID                  57
#define FILE_PREALLOCATE_ID           58
#define FILE_READ_ID                  59
#define FILE_READ_ALL_ID              60
#define FILE_READ_ALL_BEGIN_ID        61
#define FILE_READ_ALL_END_ID          62
#define FILE_READ_AT_ID               63
#define FILE_READ_AT_ALL_ID           64
#define FILE_READ_AT_ALL_BEGIN_ID     65
#define FILE_READ_AT_ALL_END_ID       66
#define FILE_READ_ORDERED_ID          67
#define FILE_READ_ORDERED_BEGIN_ID    68
#define FILE_READ_ORDERED_END_ID      69
#define FILE_READ_SHARED_ID           70
#define FILE_SEEK_ID                  71
#define FILE_SEEK_SHARED_ID           72
#define FILE_SET_VIEW_ID              73
#define FILE_SYNC_ID                  74
#define FILE_WRITE_ID                 75
#define FILE_WRITE_ALL_ID             76
#define FILE_WRITE_ALL_BEGIN_ID       77
#define FILE_WRITE_ALL_END_ID         78
#define FILE_WRITE_AT_ID              79
#define FILE_WRITE_AT_ALL_ID          80
#define FILE_WRITE_AT_ALL_BEGIN_ID    81
#define FILE_WRITE_AT_ALL_END_ID      82
#define FILE_WRITE_ORDERED_ID         83
#define FILE_WRITE_ORDERED_BEGIN_ID   84
#define FILE_WRITE_ORDERED_END_ID     85
#define FILE_WRITE_SHARED_ID          86
