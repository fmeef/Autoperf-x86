/*==========================================================*/
/* Main autoperf entry and exit points                      */
/* TODO add error checking and handlng                      */
/*==========================================================*/
#include <stdlib.h>
#include "mpi.h"
#include "autoperf.h"
#include "sys/ap_sys.h"
#include "proc/ap_proc.h"
#include "hpm/ap_hpm.h"
#include "mpi/ap_mpi.h"
#include "coll/ap_collect.h"

#define STR(s) #s
#define XSTR(s) STR(s)

#define DISABLE_ENV AP_DISABLE
#define DISABLE_SYS_ENV AP_DISABLE_SYS
#define DISABLE_PROC_ENV AP_DISABLE_PROC
#define DISABLE_MPI_ENV AP_DISABLE_MPI
#define DISABLE_HPM_ENV AP_DISABLE_HPM
#define OUTPUT_LOCAL_ENV AP_OUTPUT_LOCAL
#define OUTPUT_SYS_ENV AP_OUTPUT_SYS
#define DEBUG_LEVEl_ENV AP_DEBUG_LEVEL


// variables
static ap_settings_t apSettings;


/*==========================================================*/
/* check environment variables                              */
/*==========================================================*/

static void getEnv(ap_env_t *env) {
  char *ptr;

  env->disable_all_env = 0;
  ptr = getenv(XSTR(DISABLE_ENV));
  if (ptr != NULL) {
    env->disable_all_env = 1;
  }

  env->disable_sys_env = 0;
  ptr = getenv(XSTR(DISABLE_SYS_ENV));
  if (ptr != NULL) {
    env->disable_sys_env = 1;
  }

  env->disable_proc_env = 0;
  ptr = getenv(XSTR(DISABLE_PROC_ENV));
  if (ptr != NULL) {
    env->disable_proc_env = 1;
  }

  env->disable_mpi_env = 0;
  ptr = getenv(XSTR(DISABLE_MPI_ENV));
  if (ptr != NULL) {
    env->disable_mpi_env = 1;
  }

  env->disable_hpm_env = 0;
  ptr = getenv(XSTR(DISABLE_HPM_ENV));
  if (ptr != NULL) {
    env->disable_hpm_env = 1;
  }
  env->output_local_env = 0;
  env->output_local_env_val = 0;
  ptr = getenv(XSTR(OUTPUT_LOCAL_ENV));
  if (ptr != NULL) {
    env->output_local_env = 1;
    env->output_local_env_val = atoi(ptr);
  }

  env->output_sys_env = 0;
  env->output_sys_env_val = 0;
  ptr = getenv(XSTR(OUTPUT_SYS_ENV));
  if (ptr != NULL) {
    env->output_sys_env = 1;
    env->output_sys_env_val = atoi(ptr);
  }

  env->debug_level_env = 0;
  env->debug_level_env_val = 0;
  ptr = getenv(XSTR(DEBUG_LEVEL_ENV));
  if (ptr != NULL) {
    env->debug_level_env = 1;
    env->debug_level_env_val = atoi(ptr);
  }


  return;
}


/*==========================================================*/
/* set configuration flags                                  */
/*==========================================================*/

static void setFlags(ap_env_t *env, ap_flag_t *flags) {

  flags->disable_sys = 0;
  if (env->disable_sys_env != 0) {
    flags->disable_sys = 1;
  }

  flags->disable_proc = 0;
  if(env->disable_proc_env != 0) {
    flags->disable_proc = 1;
  }

  flags->disable_mpi = 0;
  if (env->disable_mpi_env != 0) {
    flags->disable_mpi = 1;
  }

  flags->disable_hpm = 0;
  if (env->disable_hpm_env != 0) {
    flags->disable_hpm = 1;
  }

  //DEBUG
  // flags->disable_hpm = 1;

  flags->output_local = 0;
  if (env->output_local_env != 0) {
    flags->output_local = env->output_local_env_val;
  }

  flags->output_sys = 1;
  if (env->output_sys_env != 0) {
    flags->output_sys = env->output_sys_env_val;
  }

  flags->debug_level = 1;
  if (env->debug_level_env != 0) {
    flags->debug_level = env->debug_level_env_val;
  }

  if (env->disable_all_env != 0) {
    flags->disable_sys = 1;
    flags->disable_proc = 1;
    flags->disable_mpi = 1;
    flags->disable_hpm = 1;
    flags->output_local = 0;
    flags->output_sys = 0;
  }


  return;
}


/*==========================================================*/
/* Function to initialize autoperf data collection          */
/*==========================================================*/
void AP_Init() {

  /*-------------------------------------------------------*/
  /* Wait for debugger to attach to process                */
  /*-------------------------------------------------------*/
  /*
    int i = 0;
    char hostname[256];
    gethostname(hostname, sizeof(hostname));
    printf("PID %d on %s ready for attach\n", getpid(), hostname);
    fflush(stdout);
    while (0 == i)
      sleep(5);
 
  */

  
  /*-------------------------------------------------------*/
  /* Get environment variables and set flags               */
  /*-------------------------------------------------------*/
  printf("[DEBUG] begin AP_Init()\n");
  getEnv(&(apSettings.env));
  setFlags(&(apSettings.env), &(apSettings.flags));
  //printf("[DEBUG] flags set\n");

  /*-------------------------------------------------------*/
  /* Initialize components                                 */
  /*-------------------------------------------------------*/

  AP_Sys_Init(apSettings.flags.disable_sys);
  //printf("[DEBUG] finished AP_Sys_Init()\n");
  AP_Proc_Init(apSettings.flags.disable_proc);
  //printf("[DEBUG] finished AP_Proc_Init()\n");
  AP_HPM_Init(apSettings.flags.disable_hpm);
  //printf("[DEBUG] finished AP_HPM_Init()\n");
  AP_MPI_Init(apSettings.flags.disable_mpi);
  //printf("[DEBUG] finished AP_MPI_Init()\n");

  PMPI_Barrier(MPI_COMM_WORLD);
  //printf("[DEBUG] finished PMPI_Barrier\n");
  AP_HPM_Start();
  //printf("[DEBUG] finished AP_HPM_Start()\n");
  AP_Proc_Start();
  // printf("[DEBUG] finished AP_Proc_start()\n");


  return;
}


/*==========================================================*/
/* Function to finalize autoperf data collection            */
/*==========================================================*/
void AP_Finalize() {

  /*--------------------------------------------------------*/
  /* Stop components                                        */
  /*--------------------------------------------------------*/

  PMPI_Barrier(MPI_COMM_WORLD);

  AP_Proc_Stop();
  AP_HPM_Stop();

  /*--------------------------------------------------------*/
  /* Finalize components                                    */
  /*--------------------------------------------------------*/

  AP_MPI_Finalize();
  AP_HPM_Finalize();
  AP_Proc_Finalize();
  AP_Sys_Finalize();

  /*--------------------------------------------------------*/
  /* Collect and output data                                */
  /*--------------------------------------------------------*/

  AP_CollectAndOutput();


  return;
}


/*==========================================================*/
/* Function returning pointer to settings                   */
/*==========================================================*/
ap_settings_t* AP_getSettings() {


  return &apSettings;
}
