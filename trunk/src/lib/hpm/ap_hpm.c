#include <papi.h>
#include "autoperf.h"
#include "hpm/ap_hpm.h"

static int disabled = 0;

static ap_cycle_t startCycle, stopCycle, elapsedCycles;
static double elapsedTime;


/* ============================================= */
/* OLD COUNTER ARRAYS                            */
/* static uint64_t pCounts[HPM_NUM_P_EVENTS];    */
/* static uint64_t L2Counts[HPM_NUM_L2_EVENTS];  */
/* static uint64_t NWCounts[HPM_NUM_NW_EVENTS];  */
/* static int pIds[HPM_NUM_P_EVENTS];            */
/* static int L2Ids[HPM_NUM_L2_EVENTS];          */
/* static int NWIds[HPM_NUM_NW_EVENTS];          */ 
/* ============================================= */


static long long results[PAPI_NUM_EVENTS];



/*=================================================================*/
/* Initialize the counters                                         */
/*=================================================================*/

int AP_HPM_Init(int disabledArg) {

  /*---------------------------------------------------*/
  /* return immediately if not logging data            */
  /*---------------------------------------------------*/

  disabled = disabledArg;
  if (disabled != 0) return 0;

  /*------------------*/
  /* Get settings     */
  /*------------------*/

  ap_settings_t *settings = AP_getSettings();

  /*--------------------------------------------------*/
  /* Nothing much to init here with PAPI high level   */
  /*--------------------------------------------------*/ 

  return 0;
}


/*===============================================================*/
/* Start hardware performance counters                           */
/*===============================================================*/
int AP_HPM_Start() {

  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/

  if (disabled != 0) return 0;

  /*-------------------------------*/
  /* start counters                */
  /*-------------------------------*/

  int retval;
  if((retval = PAPI_start_counters(pEventList, PAPI_NUM_EVENTS)) < PAPI_OK) {
    disabled=1;
    printf("Starting counters failed: %s\n", PAPI_strerror(retval));
    return 1;
  }


  return 0;
}


/*===============================================================*/
/* Stop hardware performance counters                            */
/*===============================================================*/
int AP_HPM_Stop() {

  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/

  if (disabled != 0) return 0;

  /*-------------------------------*/
  /* record cycle                  */
  /*-------------------------------*/

  APCYCLES(stopCycle);

  /*------------------------------*/
  /* stop counters                */
  /*------------------------------*/
  int retval;
  if((retval = PAPI_stop_counters(results, PAPI_NUM_EVENTS)) < PAPI_OK) {
    disabled = 1;
    printf("Stopping counters failed: %s\n", PAPI_strerror(retval));
    return 1;
  }
  return 0;
}


/*===============================================================*/
/* Finalize counter data collection                              */
/*===============================================================*/
int AP_HPM_Finalize() {

  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/

  if (disabled != 0) return 0;

  /*---------------------------------------------------*/
  /* Read counter data                                 */
  /*---------------------------------------------------*/

  
  elapsedCycles = stopCycle - startCycle;
  elapsedTime = APCTCONV(elapsedCycles);


  return 0;
}


/*===============================================================*/
/* Get HPM data                                                  */
/*===============================================================*/
int AP_HPM_GetData(ap_hpmData_t *data) {

  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/

  data->disabled = disabled;
  if (disabled != 0) return 0;

  /*---------------------------------------------------*/
  /* copy data                                         */
  /*---------------------------------------------------*/

  data->startCycle = startCycle;
  data->stopCycle = stopCycle;
  data->elapsedCycles = elapsedCycles;
  data->elapsedTime = elapsedTime;

  memcpy(data->ids, pEventList, PAPI_NUM_EVENTS);
  memcpy(data->counts, results, PAPI_NUM_EVENTS);
  
  return 0;
}


/*===============================================================*/
/* Return event label for id, null if bad id                     */
/*===============================================================*/
const char* AP_HPM_GetEventName(int id) {

  PAPI_event_info_t evt;
  printf("[DEBUG] event code (for file writing) is %d\n",id);
  printf("we are looking for something close to %d\n", PAPI_L2_DCM);
  PAPI_get_event_info(id, &evt);
  const char *name = evt.short_descr;


  return name;
}
