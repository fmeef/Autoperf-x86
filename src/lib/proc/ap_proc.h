#include <stdint.h>
#include "time/ap_time.h"
#include <hwloc.h>
#include <uuid/uuid.h>
typedef struct {
  int disabled;
  ap_cycle_t startCycle, stopCycle, elapsedCycles;
  double elapsedTime;
  uuid_t jobId;
  int numProcessesOnNode;
  int processHWThreads;
  uint64_t heapMaxUsed;
  char * cobaltId;
} ap_procData_t;

// cycle and time variables
ap_cycle_t tmpStartCycle;
ap_cycle_t tmpStopCycle;
ap_cycle_t tmpElapsedCycles;
double tmpElapsedTime;
int disabled;
long long startWallclock;
long long endWallclock;
int numProcessesOnNode;
uuid_t jobId;
int processHWThreads;

int AP_Proc_Init(int );
int AP_Proc_Start(void);
int AP_Proc_Stop(void);
int AP_Proc_Finalize(void);
int AP_Proc_GetData(ap_procData_t* );
