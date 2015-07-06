/*==========================================================*/
/* module to collect and return system configuration info   */
/*==========================================================*/
#include "ap_config.h"
#include "sys/ap_sys.h"

static int disabled = 0;
static int coresPerNode = 0;
static int hwThreadsPerCore = 0;

/*==========================================================*/
/* Function to initialize component for data collection     */
/*==========================================================*/

int AP_Sys_Init(int disableArg) {

  disabled = disableArg;
  if (disabled != 0) return 1;


  return 0;
}


/*==========================================================*/
/* Function to finalize component data collection           */
/*==========================================================*/

int AP_Sys_Finalize(void) {

  if (disabled != 0) return 1;

  coresPerNode = CORES_PER_NODE;
  hwThreadsPerCore = HW_THREADS_PER_CORE;


  return 0;
}


/*==========================================================*/
/* Function to return collected data                        */
/*==========================================================*/

int AP_Sys_GetData(ap_sysData_t* data) {

  data->disabled = disabled;
  if (disabled != 0) return 1;

  data->coresPerNode = coresPerNode;
  data->hwThreadsPerCore = hwThreadsPerCore;


  return 0;
}
