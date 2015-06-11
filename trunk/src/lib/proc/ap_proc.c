//#include "spi/include/kernel/process.h"
//#include "spi/include/kernel/memory.h"
#include <hwloc.h>
#include "time/ap_time.h"
#include "proc/ap_proc.h"
#include <sys/sysinfo.h>
#include <linux/version.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/resource.h>
// control flag
static int disabled = 0;

// cycle and time variables
static ap_cycle_t startCycle = 0LL;
static ap_cycle_t stopCycle = 0LL;
static ap_cycle_t elapsedCycles = 0LL;
static double elapsedTime = 0;

// job id number
static uint64_t jobId;

// processor information
static int numProcessesOnNode;
static int processHWThreads;

// memory information
static uint64_t heapMaxUsed;


//hwloc topology tree
static hwloc_topology_t topo;



/*==========================================================*/
/* Function to initialize data collection                   */
/*==========================================================*/

int AP_Proc_Init(int disabledArg) {

  /*-------------------------------------------------------*/
  /* set collection control, return if not collecting data */
  /*-------------------------------------------------------*/

  disabled = disabledArg;
  if (disabled != 0) return 0;


  hwloc_topology_init(&topo);
  hwloc_topology_load(topo);
  
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

  if (disabled != 0) return 0;

  /*---------------------*/
  /* Start process timer */
  /*---------------------*/

  APCYCLES(startCycle);


  return 0;
}


/*==========================================================*/
/* Function to stop data collection                         */
/*  stops process timer                                     */
/*==========================================================*/

int AP_Proc_Stop() {

  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/

  if (disabled != 0) return 0;

  /*--------------------*/
  /* Stop process timer */
  /*--------------------*/

  APCYCLES(stopCycle);


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
  /* Determine process elapsed time */
  /*--------------------------------*/

  elapsedCycles = stopCycle-startCycle;
  elapsedTime = APCTCONV(elapsedCycles);

  /*------------*/
  /* Get Job Id */
  /*------------*/

  jobId = getpid(); //not sure if this is right. If we need a unique identifyer it should work. 

  /*--------------------------------*/
  /* Get cores and hardware threads */
  /*--------------------------------*/


  struct sysinfo sinfo;
  int runningprocs;
  if(sysinfo(&sinfo)==0)
    runningprocs = (int) sinfo.procs;
  else
    runningprocs = (int) -1;
  numProcessesOnNode = runningprocs;
  processHWThreads = (int) hwloc_get_nbobjs_by_type(topo, HWLOC_OBJ_PU);

  /*------------------------*/
  /* Get memory information */
  /*------------------------*/
  
  //Kernel_GetMemorySize(KERNEL_MEMSIZE_HEAPMAX, &heapMaxUsed);


  /* get the heap usage of the process, 0 if kernel does not support (not really) */

  getrusage(RUSAGE_SELF, &heapMaxUsed);
  heapMaxUsed =0;

  return 0;
}


/*==========================================================*/
/* Function to return collected data                        */
/*==========================================================*/

int AP_Proc_GetData(ap_procData_t* data) {

  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/

  data->disabled = disabled;
  if (disabled != 0) return 0;

  /*-----------------------*/
  /* Copy data into struct */
  /*-----------------------*/

  data->startCycle = startCycle;
  data->stopCycle = stopCycle;
  data->elapsedCycles = elapsedCycles;
  data->elapsedTime = elapsedTime;
  data->jobId = jobId;
  data->numProcessesOnNode = numProcessesOnNode;
  data->processHWThreads = processHWThreads;
  data->heapMaxUsed = heapMaxUsed;


  return 0;
}
