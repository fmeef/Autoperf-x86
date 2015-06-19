#include <mpi.h>
#include <math.h>
#include "ap_config.h"
#include "coll/util.h"
#include <sys/types.h>
#include <unistd.h>
#include <uuid/uuid.h>

typedef struct {int minTimeRank; int maxTimeRank; int avTimeRank;} outputRanks_t;


/*====================================================*/
/* Identify ranks with min, max, adn average MPI time */
/*====================================================*/
void findMPIRanks(ap_mpiData_t *mpiData, outputRanks_t *outputRanks) {

  if (mpiData->disabled != 0) {
    outputRanks->minTimeRank = 0;
    outputRanks->maxTimeRank = 0;
    outputRanks->avTimeRank = 0;

    return;
  }

  struct commStruct { double time; int rank; };
  struct commStruct my_comm;
  my_comm.time = mpiData->stdMpiTime;
  my_comm.rank = mpiData->myRank;

  struct commStruct min_comm, max_comm;
  PMPI_Allreduce(&my_comm, &min_comm, 1, MPI_DOUBLE_INT, MPI_MINLOC, MPI_COMM_WORLD);
  PMPI_Allreduce(&my_comm, &max_comm, 1, MPI_DOUBLE_INT, MPI_MAXLOC, MPI_COMM_WORLD);

  double sum_comm;
  PMPI_Allreduce(&my_comm.time, &sum_comm, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  my_comm.time = fabs(my_comm.time - (sum_comm/(double) mpiData->numRanks));

  struct commStruct avg_comm;
  PMPI_Allreduce(&my_comm, &avg_comm, 1, MPI_DOUBLE_INT, MPI_MINLOC, MPI_COMM_WORLD);

  outputRanks->minTimeRank = min_comm.rank;
  outputRanks->maxTimeRank = max_comm.rank;
  outputRanks->avTimeRank = avg_comm.rank;


  return;
}


/*====================================================*/
/* Collect and output data                            */
/*====================================================*/
void AP_CollectAndOutputRanks() {

  /*--------------*/
  /* Get data     */
  /*--------------*/

  ap_settings_t *settings = AP_getSettings();

  ap_sysData_t sysData;
  AP_Sys_GetData(&sysData);

  ap_procData_t procData;
  AP_Proc_GetData(&procData);

  ap_hpmData_t hpmData;
  AP_HPM_GetData(&hpmData);

  ap_mpiData_t mpiData;
  AP_MPI_GetData(&mpiData);

  /*------------------------------*/
  /* identify ranks to write data */
  /*------------------------------*/

  outputRanks_t outputRanks;
  findMPIRanks(&mpiData, &outputRanks);
  
  /*------------*/
  /* Open files */
  /*------------*/

  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  FILE *locFile = NULL;
  FILE *sysFile = NULL;
  if (rank == 0) {
    uint64_t jobId;
    if (procData.disabled == 0) {
    jobId = procData.jobId;
    printf("[DEBUG] procData.jobId is %d\n",jobId);
  } else {
      uuid_generate_time(jobId);
    printf("[DEBUG] procData is disabled %d\n",jobId);
  }

    if (settings->flags.output_local != 0) {
      locFile = AP_openOutputFile(OUTPUT_LOCAL_DIR, NO_APPEND_PATH, jobId, NO_RANK_IN_NAME,
                                  settings->flags.debug_level);
    }

    if (settings->flags.output_sys != 0) {
      sysFile= AP_openOutputFile(OUTPUT_SYS_DIR, APPEND_PATH, jobId, NO_RANK_IN_NAME, settings->flags.debug_level);
    }
  }

  /*------------------------*/
  /* send data to rank zero */
  /*------------------------*/

    ap_sysData_t minSysData, maxSysData, avSysData;
    ap_procData_t minProcData, maxProcData, avProcData;
    ap_hpmData_t minHPMData, maxHPMData, avHPMData;
    ap_mpiData_t minMPIData, maxMPIData, avMPIData;
  
    int minTagStart = 0, maxTagStart = 10, avTagStart = 20;
    MPI_Request req[12];
    MPI_Status stat[12];
  
    if (rank == 0) {
      MPI_Irecv(&minSysData, sizeof(ap_sysData_t), MPI_BYTE, outputRanks.minTimeRank, minTagStart+1,
               MPI_COMM_WORLD, &req[0]);
      MPI_Irecv(&minProcData, sizeof(ap_procData_t), MPI_BYTE, outputRanks.minTimeRank, minTagStart+2, 
               MPI_COMM_WORLD, &req[1]);
      MPI_Irecv(&minHPMData, sizeof(ap_hpmData_t), MPI_BYTE, outputRanks.minTimeRank, minTagStart+3, 
               MPI_COMM_WORLD, &req[2]);
      MPI_Irecv(&minMPIData, sizeof(ap_mpiData_t), MPI_BYTE, outputRanks.minTimeRank, minTagStart+4, 
               MPI_COMM_WORLD, &req[3]);
    
      MPI_Irecv(&maxSysData, sizeof(ap_sysData_t), MPI_BYTE, outputRanks.maxTimeRank, maxTagStart+1, 
               MPI_COMM_WORLD, &req[4]);
      MPI_Irecv(&maxProcData, sizeof(ap_procData_t), MPI_BYTE, outputRanks.maxTimeRank, maxTagStart+2, 
               MPI_COMM_WORLD, &req[5]);
      MPI_Irecv(&maxHPMData, sizeof(ap_hpmData_t), MPI_BYTE, outputRanks.maxTimeRank, maxTagStart+3, 
               MPI_COMM_WORLD, &req[6]);
      MPI_Irecv(&maxMPIData, sizeof(ap_mpiData_t), MPI_BYTE, outputRanks.maxTimeRank, maxTagStart+4, 
               MPI_COMM_WORLD, &req[7]);
  
      MPI_Irecv(&avSysData, sizeof(ap_sysData_t), MPI_BYTE, outputRanks.avTimeRank, avTagStart+1, 
               MPI_COMM_WORLD, &req[8]);
      MPI_Irecv(&avProcData, sizeof(ap_procData_t), MPI_BYTE, outputRanks.avTimeRank, avTagStart+2, 
               MPI_COMM_WORLD, &req[9]);
      MPI_Irecv(&avHPMData, sizeof(ap_hpmData_t), MPI_BYTE, outputRanks.avTimeRank, avTagStart+3, 
               MPI_COMM_WORLD, &req[10]);
      MPI_Irecv(&avMPIData, sizeof(ap_mpiData_t), MPI_BYTE, outputRanks.avTimeRank, avTagStart+4, 
               MPI_COMM_WORLD, &req[11]);
    }
  
    if (rank == outputRanks.minTimeRank) {
      MPI_Send(&sysData, sizeof(ap_sysData_t), MPI_BYTE, 0, minTagStart + 1, MPI_COMM_WORLD);
      MPI_Send(&procData, sizeof(ap_procData_t), MPI_BYTE, 0, minTagStart + 2, MPI_COMM_WORLD);
      MPI_Send(&hpmData, sizeof(ap_hpmData_t), MPI_BYTE, 0, minTagStart + 3, MPI_COMM_WORLD);
      MPI_Send(&mpiData, sizeof(ap_mpiData_t), MPI_BYTE, 0, minTagStart + 4, MPI_COMM_WORLD);
    }
  
    if (rank == outputRanks.maxTimeRank) {
      MPI_Send(&sysData, sizeof(ap_sysData_t), MPI_BYTE, 0, maxTagStart + 1, MPI_COMM_WORLD);
      MPI_Send(&procData, sizeof(ap_procData_t), MPI_BYTE, 0, maxTagStart + 2, MPI_COMM_WORLD);
      MPI_Send(&hpmData, sizeof(ap_hpmData_t), MPI_BYTE, 0, maxTagStart + 3, MPI_COMM_WORLD);
      MPI_Send(&mpiData, sizeof(ap_mpiData_t), MPI_BYTE, 0, maxTagStart + 4, MPI_COMM_WORLD);
    }
  
    if (rank == outputRanks.avTimeRank) {
      MPI_Send(&sysData, sizeof(ap_sysData_t), MPI_BYTE, 0, avTagStart + 1, MPI_COMM_WORLD);
      MPI_Send(&procData, sizeof(ap_procData_t), MPI_BYTE, 0, avTagStart + 2, MPI_COMM_WORLD);
      MPI_Send(&hpmData, sizeof(ap_hpmData_t), MPI_BYTE, 0, avTagStart + 3, MPI_COMM_WORLD);
      MPI_Send(&mpiData, sizeof(ap_mpiData_t), MPI_BYTE, 0, avTagStart + 4, MPI_COMM_WORLD);
    }
  
    if (rank == 0) {
      MPI_Waitall(12, req, stat);
    }

  /*------------------------*/
  /* write data             */
  /*------------------------*/

    if (locFile != NULL) {
      fprintf(locFile, "Data for rank 0 - \n");
    }
    AP_writeProcDataLoc(locFile, &procData);
    AP_writeHPMDataLoc(locFile,  &hpmData);
    AP_writeMPIDataLoc(locFile,  &mpiData);

    AP_writeSettings(sysFile, settings);
    AP_writeSysData(sysFile, "zero_", &sysData);
    AP_writeProcData(sysFile, "zero_", &procData);
    AP_writeHPMData(sysFile, "zero_", &hpmData);
    AP_writeMPIData(sysFile, "zero_", &mpiData);
  
    if (locFile != NULL) {
      fprintf(locFile, "\nData for rank with minimum MPI Time:");

      if (outputRanks.minTimeRank == 0) {
        fprintf(locFile, " is rank 0\n"); 
      } else { 
        fprintf(locFile, "\n");
        AP_writeProcDataLoc(locFile, &minProcData);
        AP_writeHPMDataLoc(locFile,  &minHPMData);
        AP_writeMPIDataLoc(locFile, &minMPIData);
      }
    }
  
    AP_writeSysData(sysFile, "min_", &minSysData);
    AP_writeProcData(sysFile, "min_", &minProcData);
    AP_writeHPMData(sysFile, "min_", &minHPMData);
    AP_writeMPIData(sysFile, "min_", &minMPIData);
  
    if (locFile != NULL) {
      fprintf(locFile, "\nData for rank with maximum MPI Time:");

      if (outputRanks.maxTimeRank == 0) {
        fprintf(locFile, " is rank 0\n"); 
      } else if (outputRanks.maxTimeRank == outputRanks.minTimeRank) { 
        fprintf(locFile, " is same as minimum MPI time rank\n"); 
      } else { 
        fprintf(locFile, "\n");
        AP_writeProcDataLoc(locFile, &maxProcData);
        AP_writeHPMDataLoc(locFile, &maxHPMData);
        AP_writeMPIDataLoc(locFile, &maxMPIData);
      }
    }
  
    AP_writeSysData(sysFile, "max_", &maxSysData);
    AP_writeProcData(sysFile, "max_", &maxProcData);
    AP_writeHPMData(sysFile, "max_", &maxHPMData);
    AP_writeMPIData(sysFile, "max_", &maxMPIData);

    if (locFile != NULL) {
      fprintf(locFile, "\nData for rank with average MPI Time:");

      if (outputRanks.avTimeRank == 0) {
        fprintf(locFile, " is rank 0\n"); 
      } else if (outputRanks.avTimeRank == outputRanks.minTimeRank) { 
        fprintf(locFile, " is same as minimum MPI time rank\n"); 
      } else if (outputRanks.avTimeRank == outputRanks.maxTimeRank) { 
        fprintf(locFile, " is same as maximum MPI time rank\n"); 
      } else { 
        fprintf(locFile, "\n");
        AP_writeProcDataLoc(locFile, &avProcData);
        AP_writeHPMDataLoc(locFile, &avHPMData);
        AP_writeMPIDataLoc(locFile, &avMPIData);
      }
    }
  
    AP_writeSysData(sysFile, "av_", &avSysData);
    AP_writeProcData(sysFile, "av_", &avProcData);
    AP_writeHPMData(sysFile, "av_", &avHPMData);
    AP_writeMPIData(sysFile, "av_", &avMPIData);

  /*-------------*/
  /* close files */
  /*-------------*/

  if (rank == 0) {
    if (locFile != NULL) fclose(locFile);
    if (sysFile != NULL) fclose(sysFile);
  }


  return;
}
