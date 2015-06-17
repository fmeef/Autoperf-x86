#include <time.h>
#include "coll/util.h"

/*========================================================================*/
/* Open output file                                                       */
/*========================================================================*/
FILE * AP_openOutputFile(char *dirRoot, int ymdSubDir, uint64_t jobid, int myRank, int debug) {

  /*--------------------------------------------*/
  /* construct the file name                    */
  /*--------------------------------------------*/

  char filename[FILENAME_MAX];

  if (ymdSubDir == NO_APPEND_PATH) {
    if (myRank == NO_RANK_IN_NAME ) {
      sprintf(filename,"%s/ap.%llu", dirRoot, jobid);
    } else {
      sprintf(filename,"%s/ap.%llu.%d", dirRoot, jobid, myRank);
    }
  } else {
    time_t t = time(NULL);
    struct tm *timeInfo = gmtime(&t);

    if (myRank == NO_RANK_IN_NAME ) {
      //sprintf(filename,"%s/%d/%d/%d/ap.%llu", dirRoot, timeInfo->tm_year+1900, timeInfo->tm_mon+1,timeInfo->tm_mday, jobid);
        sprintf(filename,"%s/ap.%llu", dirRoot,jobid);
    } else {
    //sprintf(filename,"%s/%d/%d/%d/ap.%llu.%d", dirRoot, timeInfo->tm_year+1900, timeInfo->tm_mon+1,timeInfo->tm_mday, jobid, myRank);
      sprintf(filename,"%s/ap.%llu.%d", dirRoot,jobid, myRank);
     }
  }

  /*--------------------------------------------*/
  /* open file                                  */
  /*--------------------------------------------*/

  FILE *fh = NULL; 
  fh = fopen(filename, "w");
  if (fh == NULL) {
    if (debug != 0) printf("auto_perf: ERROR- task %d failed to open the file %s\n", myRank, filename);
  }


  return fh;
}


/*====================================================*/
/* write autoperf settings                            */
/*====================================================*/

int AP_writeSettings(FILE *fh, ap_settings_t *settings) {

  int version = 1;

  /*----------------------------*/
  /* check for null file handle */
  /*----------------------------*/

  if (fh == NULL) return 0;

  /*----------------------------*/
  /* write settings             */
  /*----------------------------*/

  fprintf(fh, "Settings:\n");
  fprintf(fh, "  version = %d\n", version);
  fprintf(fh, "  disable_all_env = %d\n", settings->env.disable_all_env);
  fprintf(fh, "  disable_sys_env = %d\n", settings->env.disable_sys_env);
  fprintf(fh, "  disable_proc_env = %d\n", settings->env.disable_proc_env);
  fprintf(fh, "  disable_mpi_env = %d\n", settings->env.disable_mpi_env);
  fprintf(fh, "  disable_hpm_env = %d\n", settings->env.disable_hpm_env);
  fprintf(fh, "  output_local_env = %d\n", settings->env.output_local_env);
  fprintf(fh, "  output_local_env_val = %d\n", settings->env.output_local_env_val);
  fprintf(fh, "  output_sys_env = %d\n", settings->env.output_sys_env);
  fprintf(fh, "  output_sys_env_val = %d\n", settings->env.output_sys_env_val);
  fprintf(fh, "  debug_level_env = %d\n", settings->env.debug_level_env);
  fprintf(fh, "  debug_level_env_val = %d\n", settings->env.debug_level_env_val);

  fprintf(fh, "  disable_sys = %d\n", settings->flags.disable_sys);
  fprintf(fh, "  disable_proc = %d\n", settings->flags.disable_proc);
  fprintf(fh, "  disable_mpi = %d\n", settings->flags.disable_mpi);
  fprintf(fh, "  disable_hpm = %d\n", settings->flags.disable_hpm);
  fprintf(fh, "  output_local = %d\n", settings->flags.output_local);
  fprintf(fh, "  output_sys = %d\n", settings->flags.output_sys);
  fprintf(fh, "  debug_level = %d\n", settings->flags.debug_level);


  return 0;
}


/*====================================================*/
/* write sys component data                           */
/*====================================================*/

int AP_writeSysData(FILE *fh, char *prefix, ap_sysData_t *data) {

  int version = 1;

  /*----------------------------*/
  /* check for null file handle */
  /*----------------------------*/

  if (fh == NULL) return 0;

  /*----------------------------*/
  /* write data                 */
  /*----------------------------*/

  fprintf(fh, "\nSys:\n");
  fprintf(fh, "  %sversion = %d\n", prefix, version);
  fprintf(fh, "  %sdisabled = %d\n", prefix, data->disabled);

  if (data->disabled == 0) {
    fprintf(fh, "  %scoresPerNode = %d\n", prefix, data->coresPerNode);
    fprintf(fh, "  %shwThreadsPerCore = %d\n", prefix, data->hwThreadsPerCore);
  }


  return 0;
}

/*=====================================================*/
/* write proc component data                           */
/*=====================================================*/

int AP_writeProcData(FILE *fh, char *prefix, ap_procData_t *data) {

  int version = 1;

  /*----------------------------*/
  /* check for null file handle */
  /*----------------------------*/

  if (fh == NULL) return 0;

  /*----------------------------*/
  /* write data                 */
  /*----------------------------*/

  fprintf(fh, "\nProc:\n");
  fprintf(fh, "  %sversion = %d\n", prefix, version);
  fprintf(fh, "  %sdisabled = %d\n", prefix, data->disabled);

  if (data->disabled == 0) {
    fprintf(fh, "  %sstartCycle = %llu\n", prefix, data->startCycle);
    fprintf(fh, "  %sstopCycle = %llu\n", prefix, data->stopCycle);
    fprintf(fh, "  %selapsedCycles = %llu\n", prefix, data->elapsedCycles);
    fprintf(fh, "  %selapsedTime = %f\n", prefix, data->elapsedTime);
    fprintf(fh, "  %sjobId = %llu\n", prefix, data->jobId);
    fprintf(fh, "  %snumProcessesOnNode = %d\n", prefix, data->numProcessesOnNode);
    fprintf(fh, "  %sprocessHWThreads = %d\n", prefix, data->processHWThreads);
    fprintf(fh, "  %sheapMaxUsed = %llu\n", prefix, data->heapMaxUsed);
  }


  return 0;
}


/*=====================================================*/
/* write hpm component data                            */
/*=====================================================*/

int AP_writeHPMData(FILE *fh, char *prefix, ap_hpmData_t *data) {

  int version = 1;

  /*----------------------------*/
  /* check for null file handle */
  /*----------------------------*/

  if (fh == NULL) return 0;

  /*----------------------------*/
  /* write data                 */
  /*----------------------------*/

  fprintf(fh, "\nHPM:\n");
  fprintf(fh, "  %sversion = %d\n", prefix, version);
  fprintf(fh, "  %sdisabled = %d\n", prefix, data->disabled);

  if (data->disabled == 0) {
    fprintf(fh, "  %sstartCycle = %llu\n", prefix, data->startCycle);
    fprintf(fh, "  %sstopCycle = %llu\n", prefix, data->stopCycle);
    fprintf(fh, "  %selapsedCycles = %llu\n", prefix, data->elapsedCycles);
    fprintf(fh, "  %selapsedTime = %f\n", prefix, data->elapsedTime);

    int i;
    for(i = 0; i < PAPI_NUM_EVENTS; i++) {
      char * final = malloc(PAPI_MAX_STR_LEN * sizeof(char));
      AP_HPM_GetEventName(data->ids[i], final);
      printf("[DEBUG] right before writing: %s\n",final);
      fprintf(fh, "DEBUG id = %s\n",final);
       fprintf(fh, "  %s%s = %llu\n", prefix,final, data->counts[i]);
    }

  }


  return 0;
}


/*=====================================================*/
/* write mpi component data                            */
/*=====================================================*/

int AP_writeMPIData(FILE *fh, char *prefix, ap_mpiData_t *data) {

  int version = 1;

  /*----------------------------*/
  /* check for null file handle */
  /*----------------------------*/

  if (fh == NULL) return 0;

  /*----------------------------*/
  /* write data                 */
  /*----------------------------*/

  fprintf(fh, "\nMPI:\n");
  fprintf(fh, "  %sversion = %d\n", prefix, version);
  fprintf(fh, "  %sdisabled = %d\n", prefix, data->disabled);

  if (data->disabled == 0) {
    fprintf(fh, "  %smyRank = %d\n", prefix, data->myRank);
    fprintf(fh, "  %snumRanks = %d\n", prefix, data->numRanks);
    fprintf(fh, "  %sstdMpiTime = %f\n", prefix, data->stdMpiTime);
    fprintf(fh, "  %smpiIoTime = %f\n", prefix, data->mpiIoTime);

    int i;
    for(i = 0; i < MIN_MPI_IO_ID; i++) {
       const char *routineName = AP_MPI_GetFuncName(i);
       fprintf(fh, "  %s%s_callCount = %lld\n", prefix, routineName, data->mpiRoutineData[i].callCount);
       fprintf(fh, "  %s%s_totalCycles = %llu\n", prefix, routineName, data->mpiRoutineData[i].totalCycles);
       fprintf(fh, "  %s%s_totalBytes = %f\n", prefix, routineName, data->mpiRoutineData[i].totalBytes);
       fprintf(fh, "  %s%s_totalTime = %f\n", prefix, routineName, data->mpiRoutineData[i].totalTime);
    }

#ifdef AP_MPIO_WRAPPERS_ENABLE
    for(i = MIN_MPI_IO_ID; i < MAX_MPI_IDS ;i++) {
       const char *routineName = AP_MPI_GetFuncName(i);
       fprintf(fh, "  %s%s_callCount = %lld\n", prefix, routineName, data->mpiRoutineData[i].callCount);
       fprintf(fh, "  %s%s_totalCycles = %llu\n", prefix, routineName, data->mpiRoutineData[i].totalCycles);
       fprintf(fh, "  %s%s_totalBytes = %f\n", prefix, routineName, data->mpiRoutineData[i].totalBytes);
       fprintf(fh, "  %s%s_totalTime = %f\n", prefix, routineName, data->mpiRoutineData[i].totalTime);
    }
#endif

  }


  return 0;
}

/*=====================================================*/
/* write proc component data                           */
/*=====================================================*/

int AP_writeProcDataLoc(FILE *fh, ap_procData_t *data) {

  /*----------------------------*/
  /* check for null file handle */
  /*----------------------------*/

  if (fh == NULL) return 0;

  /*----------------------------*/
  /* write data                 */
  /*----------------------------*/

  if (data->disabled == 0) {
    fprintf(fh, "  Process data:\n");
    fprintf(fh, "    Cycles = %llu\n", data->elapsedCycles);
    fprintf(fh, "    Time = %f\n", data->elapsedTime);
    fprintf(fh, "    Number of process per node = %d\n", data->numProcessesOnNode);
    fprintf(fh, "    Process HW threads = %d\n", data->processHWThreads);
    fprintf(fh, "    Max heap memory used = %llu\n", data->heapMaxUsed);
  }


  return 0;
}


/*=====================================================*/
/* write hpm component data                            */
/*=====================================================*/

int AP_writeHPMDataLoc(FILE *fh, ap_hpmData_t *data) {

  /*----------------------------*/
  /* check for null file handle */
  /*----------------------------*/

  if (fh == NULL) return 0;

  /*----------------------------*/
  /* write data                 */
  /*----------------------------*/

  if (data->disabled == 0) {
    fprintf(fh, "\n  Hardware counter data:\n");
    fprintf(fh, "    Cycles = %llu\n", data->elapsedCycles);
    fprintf(fh, "    Time = %f\n", data->elapsedTime);

    int i;
    for(i = 0; i < PAPI_NUM_EVENTS; i++) {
      char * name = malloc(PAPI_MAX_STR_LEN * sizeof(char));
      AP_HPM_GetEventName(data->ids[i],name);
       fprintf(fh, "    %s = %llu\n",name , data->counts[i]);
    }
  }


  return 0;
}


/*=====================================================*/
/* write mpi component data                            */
/*=====================================================*/

int AP_writeMPIDataLoc(FILE *fh, ap_mpiData_t *data) {

  /*----------------------------*/
  /* check for null file handle */
  /*----------------------------*/

    if (fh == NULL) return 0;

  /*----------------------------*/
  /* write data                 */
  /*----------------------------*/

  if (data->disabled == 0) {
    fprintf(fh, "\n  MPI Data:\n");
    fprintf(fh, "    Rank = %d\n", data->myRank);
    fprintf(fh, "    Number of Ranks = %d\n", data->numRanks);
    fprintf(fh, "    MPI Time (ex IO) = %f\n", data->stdMpiTime);
    fprintf(fh, "    MPI IO Time = %f\n", data->mpiIoTime);

    fprintf(fh, "\n    Routine_______________________  Calls____  Av._Bytes___  Tot_Seconds_\n");

    int i;
    for(i = 0; i < MIN_MPI_IO_ID; i++) {
      if (data->mpiRoutineData[i].callCount > 0) {
        const char *routineName = AP_MPI_GetFuncName(i);
        fprintf(fh, "    %-30s", routineName);
        fprintf(fh, "  %9lld", data->mpiRoutineData[i].callCount);
        fprintf(fh, "  %12.1f", data->mpiRoutineData[i].totalBytes/data->mpiRoutineData[i].callCount);
        fprintf(fh, "  %12.4f\n", data->mpiRoutineData[i].totalTime);
      }
    }

    #ifdef AP_MPIO_WRAPPERS_ENABLE
      for(i = MIN_MPI_IO_ID; i < MAX_MPI_IDS ;i++) {
        if (data->mpiRoutineData[i].callCount > 0) {
          const char *routineName = AP_MPI_GetFuncName(i);
          fprintf(fh, "    %-30s", routineName);
          fprintf(fh, "  %9lld", data->mpiRoutineData[i].callCount);
          fprintf(fh, "  %12.1f",  data->mpiRoutineData[i].totalBytes/data->mpiRoutineData[i].callCount);
          fprintf(fh, "  %12.4f\n",  data->mpiRoutineData[i].totalTime);
        }
      }
    #endif
  }


  return 0;
}
