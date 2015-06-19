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


  return 0;
}


/*===============================================================*/
/* Get HPM data                                                  */
/*===============================================================*/
int AP_HPM_GetData(ap_hpmData_t *data) {

  /*-------------------------------*/
  /* Return if not collecting data */
  /*-------------------------------*/
  elapsedCycles = stopCycle - startCycle;
  elapsedTime = APCTCONV(elapsedCycles);

  data->disabled = disabled;
  if (disabled != 0) return 0;

  /*---------------------------------------------------*/
  /* copy data                                         */
  /*---------------------------------------------------*/

  data->startCycle = startCycle;
  data->stopCycle = stopCycle;
  data->elapsedCycles = elapsedCycles;
  data->elapsedTime = elapsedTime;
  int x;
  for(x=0;x<PAPI_NUM_EVENTS;x++) {
    data->ids[x] = pEventList[x];
    data->counts[x] = results[x];
  }
  
  return 0;
}


/*===============================================================*/
/* Return event label for id, null if bad id                     */
/*===============================================================*/
void AP_HPM_GetEventName(int id, char * nameout) {
  int ver = PAPI_library_init(PAPI_VER_CURRENT);
  if(ver != PAPI_VER_CURRENT)
    printf("LIBRARY INIT ERR\n");  
  int retval;
  char name[PAPI_MAX_STR_LEN];
  memcpy(name , nameout,PAPI_MAX_STR_LEN *sizeof( char));
  if((retval =  PAPI_event_code_to_name(id, name)) < PAPI_OK) {
    printf("%s: Failed to convert event code %u to ID\n",PAPI_strerror(retval), id);
    return "ERR";
  }

  memcpy(nameout, name,sizeof( char)* PAPI_MAX_STR_LEN) ;
}
