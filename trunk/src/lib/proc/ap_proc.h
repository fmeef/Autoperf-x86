#include <stdint.h>
#include "time/ap_time.h"

typedef struct {
  int disabled;
  ap_cycle_t startCycle, stopCycle, elapsedCycles;
  double elapsedTime;
  uint64_t jobId;
  int numProcessesOnNode;
  int processHWThreads;
  uint64_t heapMaxUsed;
} ap_procData_t;

int AP_Proc_Init(int );
int AP_Proc_Start(void);
int AP_Proc_Stop(void);
int AP_Proc_Finalize(void);
int AP_Proc_GetData(ap_procData_t* );
