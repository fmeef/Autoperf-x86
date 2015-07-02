//#include <stdlib.h>
//#include <math.h>
//#include <stdio.h>
//#include <time.h>
#include "hpm/ap_hpm.h"
#include "mpi/ap_mpi.h"
#include "proc/ap_proc.h"
#include "sys/ap_sys.h"

////#define MAX_CORES 16


typedef struct {
  int outputFlag;
  ap_sysData_t sysData;
  ap_mpiData_t mpiData;
  ap_procData_t procData;
  ap_hpmData_t hpmData;
} ap_collData_t;


void Collect_Data(ap_collData_t *);
void Output_Data(ap_collData_t *);
FILE *openOutputFile(uint64_t, int);
void Write_ProcData(FILE *, ap_procData_t *);
void Write_MPIData(FILE *, ap_mpiData_t *);
void Write_HPMData(FILE *, ap_collData_t *);


/*====================================================*/
/* Collect and output data                            */
/*====================================================*/
void AP_Collect_Local_MPI() {

  /*-------------------------------------------------*/
  /* Collect to the data to be output                */
  /*-------------------------------------------------*/

  ap_collData_t data;
  Collect_Data(&data);
  
  /*-------------------------------------------------*/
  /* Output data                                     */
  /*-------------------------------------------------*/

  Output_Data(&data);


  return;
}


/*====================================================*/
/* Collect data                                       */
/*====================================================*/
void Collect_Data(ap_collData_t *data) {

////float min_total_comm = min_comm.time;
////float max_total_comm = max_comm.time;
////float avg_total_comm = total_comm;
////PMPI_Bcast(&avg_total_comm, 1, MPI_FLOAT, avg_comm_task, MPI_COMM_WORLD);
//
////int total_mpi_io_routines_called;
////PMPI_Allreduce(&mpi_io_routines_called, &total_mpi_io_routines_called, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
//
////float min_mpi_io_time, max_mpi_io_time, avg_mpi_io_time;
////if (total_mpi_io_routines_called > 0) {
////  PMPI_Allreduce(&mpi_io_time, &min_mpi_io_time, 1, MPI_FLOAT, MPI_MIN, MPI_COMM_WORLD);
////  PMPI_Allreduce(&mpi_io_time, &max_mpi_io_time, 1, MPI_FLOAT, MPI_MAX, MPI_COMM_WORLD);
////  PMPI_Allreduce(&mpi_io_time, &avg_mpi_io_time, 1, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);
////  avg_mpi_io_time = avg_mpi_io_time / ((float) ntasks);
////}
//
//  /*-------------------------------------------------*/
//  /* find the ranks having the most and least memory */
//  /*-------------------------------------------------*/
//
////struct memStruct { float mbytes; int rank; };
////struct memStruct my_mem, max_mem, min_mem;
//
////my_mem.mbytes = (float) heapmax;
////my_mem.rank   = myrank;
////PMPI_Allreduce(&my_mem, &max_mem, 1, MPI_FLOAT_INT, MPI_MAXLOC, MPI_COMM_WORLD);
////PMPI_Allreduce(&my_mem, &min_mem, 1, MPI_FLOAT_INT, MPI_MINLOC, MPI_COMM_WORLD);
//
//  /*-----------------------------------------------------*/
//  /* fill data structure to return                       */
//  /*-----------------------------------------------------*/
//
//  data->outputFlag = 0;
//  if (data->mpiData.myRank == 0) data->outputFlag = 1;
//  if (data->mpiData.myRank == min_comm_task) data->outputFlag = 1;
//  if (data->mpiData.myRank == max_comm_task) data->outputFlag = 1;
//  if (data->mpiData.myRank == avg_comm_task) data->outputFlag = 1;
//
//  return;
//}


/*====================================================*/
/* Output data                                        */
/*====================================================*/
void Output_Data(ap_collData_t *data) {

  /*-------------------------------------------------*/
  /* Determine if data will be written return if not */
  /*-------------------------------------------------*/

  if (data->outputFlag == 0) return;

  /*----------------------------------------------*/
  /* Determine output filename and open if needed */
  /*----------------------------------------------*/


  
  FILE *fh = openOutputFile(id, data->mpiData.myRank);

  /*--------------------------------------------*/
  /* write a text output file with summary data */
  /*--------------------------------------------*/

  if (fh != NULL) {
    Write_ProcData(fh, &(data->procData));
    Write_MPIData(fh, &(data->mpiData));
    Write_HPMData(fh, data);
  }

  /*--------------------------------------------*/
  /* close files                                */
  /*--------------------------------------------*/

  if (fh != stderr && fh != NULL) fclose(fh);


  return;
}


/*========================================================================*/
/* Print the counter values                                               */
/*========================================================================*/

void Write_ProcData(FILE *fh, ap_procData_t *data) {

  char id[39];
  uuid_unparse(data->jobId, id);
  
  fprintf(fh,"Process Data-\n");
  fprintf(fh,"  Job ID : %llu\n",id );
  fprintf(fh,"  HW Threads: %d\n", data->hwThreads);
  fprintf(fh,"  Node Processes : %d\n", data->numProcessesOnNode);
  fprintf(fh,"  Total elapsed time: %.3f sec\n", data->elapsedTime);
  fprintf(fh,"  Partition shape: <%d,%d,%d,%d,%d>\n", data->torusSize[0], data->torusSize[1],
              data->torusSize[2], data->torusSize[3], data->torusSize[4]);
  fprintf(fh,"  Torus connectivity: <%d,%d,%d,%d,%d>\n", data->isTorus[0], data->isTorus[1],
              data->isTorus[2], data->isTorus[3], data->isTorus[4]);
  fprintf(fh,"  Torus location: <%d,%d,%d,%d,%d>\n", data->torusCoords[0], data->torusCoords[1],
                  data->torusCoords[2], data->torusCoords[3], data->torusCoords[4]);

  fprintf(fh,"\nMemory Data-\n");
  fprintf(fh,"  Heap memory used: %llu Bytes\n", data->heapUsed);
//fprintf(fh,"  Heap memory available: %llu Bytes\n", data->heapAvail);


  return;
}


/*========================================================================*/
/* Print the MPI values                                                   */
/*========================================================================*/
void Write_MPIData(FILE *fh, ap_mpiData_t *data) {

  fprintf(fh,"MPI Data-\n");
  fprintf(fh,"  Rank: %d\n", data->myRank);
  fprintf(fh,"  Number of ranks: %d\n", data->numRanks);
  fprintf(fh,"  MPI Time: %.3f sec\n", data->stdMpiTime);
  fprintf(fh,"  MPI IO Time: %.3f sec\n\n", data->mpiIoTime);

  fprintf(fh,"  MPI Routine                   calls     avg. bytes      time(sec)\n");

  int id;
  for (id=0; id<MAX_MPI_IDS; id++) {
    if (data->mpiRoutineData[id].callCount > 0LL) {
      double avgBytes = data->mpiRoutineData[id].totalBytes / ((double) data->mpiRoutineData[id].callCount);
      fprintf(fh, "  %-22s %12lld    %11.1f   %12.3f\n",
              AP_MPI_GetFuncName(id),
              data->mpiRoutineData[id].callCount,
              data->mpiRoutineData[id].totalBytes/data->mpiRoutineData[id].callCount,
              TCONV(data->mpiRoutineData[id].totalTime,0LL));
    }
  }


  return;
}


///*========================================================================*/
///* Print the counter values with event labels, collective on a given node */
///*========================================================================*/
//void Write_HPMData(FILE *fh, ap_collData_t *data) {
//
//
//  /*------------------------------------------------------------------*/
//  /* print aggregate counts for each process when process_scope == 1  */
//  /*------------------------------------------------------------------*/
//
//  int process_scope = 1;
//  if (process_scope) {
//    fprintf(fh, "\n");
//    fprintf(fh, "======================================================================\n");
//    fprintf(fh, "Hardware counter report for BGQ  - aggregate values for MPI rank\n");
//    fprintf(fh, "======================================================================\n");
//
//    fprintf(fh, "  -- Cycles --------------------------------------------\n");
//    fprintf(fh, "Cycles = %llu\n", data->hpmData.finalizeCycle - data->hpmData.initCycle);
//    fprintf(fh, "\n");
//
//    fprintf(fh, "  -- A2 counters (summed over threads) -----------------\n");
//    int k;
//    for (k=0; k<NUM_P_EVENTS-1; k++) {
//      fprintf(fh, "%14llu  %s\n", data->hpmData.counts[k], AP_HPM_GetEventName(data->hpmData.ids[k]));
//    }
//    fprintf(fh, "\n");
//
//    fprintf(fh, "  -- L2 counters (shared for the node) -----------------\n");
//    fprintf(fh, "%14llu  L2 Hits\n",                          data->hpmData.counts[NUM_P_EVENTS]);
//    fprintf(fh, "%14llu  L2 Misses\n",                        data->hpmData.counts[NUM_P_EVENTS+1]);
//    fprintf(fh, "%14llu  L2 lines loaded from main memory\n", data->hpmData.counts[NUM_P_EVENTS+2]);
//    fprintf(fh, "%14llu  L2 lines stored to   main memory\n", data->hpmData.counts[NUM_P_EVENTS+3]);
//    fprintf(fh, "\n");
//
//    fprintf(fh, "  -- NW counters (shared for the node) -----------------\n");
//    fprintf(fh, "%14llu  32 byte chunks sent\n", data->hpmData.counts[NUM_P_EVENTS+NUM_L2_EVENTS]);
//    fprintf(fh, "%14llu  packets received\n",    data->hpmData.counts[NUM_P_EVENTS+NUM_L2_EVENTS+1]);
//    fprintf(fh, "\n");
//  }
//
//  /*-----------------------------------------------------------------------*/
//  /* print summed counts for all process on the node when node_scope == 1  */
//  /* TODO: fix local_comm                                                  */
//  /*-----------------------------------------------------------------------*/
//
//  int node_scope = 0;
//  if (node_scope) {
//
//    /*--------------------------------------------------------------------------*/
//    /* totcores is the total number of cores with counting enabled on this node */
//    /*--------------------------------------------------------------------------*/
//
//    int numcores = data->procData.hwThreads/4;
//    if (numcores < 1) numcores = 1;
//
//    MPI_Comm local_comm = MPI_COMM_WORLD; // this is wrong, need to split 
//
//    int totcores;
//    PMPI_Allreduce(&numcores, &totcores, 1, MPI_INT, MPI_SUM, local_comm);
//    if (totcores > data->sysData.coresPerNode) totcores = data->sysData.coresPerNode;
//
//    fprintf(fh, "\n");
//    fprintf(fh, "Summed Hardware Counter Data For Node-\n");
//
//    /*-----------------------------------------------------------------------------*/
//    /* avg_cycles is the average number of clock cycles for processes on this node */
//    /*-----------------------------------------------------------------------------*/
//
//    double cycles = data->hpmData.finalizeCycle - data->hpmData.initCycle;
//    double max_cycles, avg_cycles;
//    PMPI_Allreduce(&cycles, &max_cycles, 1, MPI_DOUBLE, MPI_MAX, local_comm);
//    PMPI_Allreduce(&cycles, &avg_cycles, 1, MPI_DOUBLE, MPI_SUM, local_comm);
//    avg_cycles = avg_cycles / ((double) data->procData.numProcessesOnNode);
//
//    /*-------------------------------------------------------------*/
//    /* sum the A2 counters over all processes that share this node */
//    /*-------------------------------------------------------------*/
//
//    uint64_t node_punit_counts[NUM_P_EVENTS];
//    PMPI_Allreduce(data->hpmData.counts, node_punit_counts, NUM_P_EVENTS, MPI_LONG_LONG, MPI_SUM, local_comm);
//
//    /*-------------------------------------------------------------*/
//    /* print node event data                                       */
//    /*-------------------------------------------------------------*/
//
//    fprintf(fh, "  Avg Cycles: %.0f\n", avg_cycles);
//    fprintf(fh, "  Max Cycles: %.0f \n", max_cycles);
//
//    int k;
//    for (k=0; k< NUM_P_EVENTS; k++) {
//      fprintf(fh, " %-40s: %14llu\n", AP_HPM_GetEventName(data->hpmData.ids[k]), node_punit_counts[k]);
//    }
//
//    fprintf(fh, "  L2 Hits                                : %14llu\n", data->hpmData.counts[NUM_P_EVENTS]);
//    fprintf(fh, "  L2 Misses                              : %14llu\n", data->hpmData.counts[NUM_P_EVENTS+1]);
//    fprintf(fh, "  L2 lines loaded from main memory       : %14llu\n", data->hpmData.counts[NUM_P_EVENTS+2]);
//    fprintf(fh, "  L2 lines stored to main memory         : %14llu\n", data->hpmData.counts[NUM_P_EVENTS+3]);
//
//    fprintf(fh, "  32 byte chunks sent                    : %14llu\n",
//            data->hpmData.counts[NUM_P_EVENTS+NUM_L2_EVENTS]);
//    fprintf(fh, "  Packets received                       : %14llu\n",
//             data->hpmData.counts[NUM_P_EVENTS+NUM_L2_EVENTS+1]);
//
//    /*--------------------------------------------------------------------*/
//    /* add derived metrics - have node scope for consistency with L2 data */
//    /*--------------------------------------------------------------------*/
//
//    int derived_metrics = 1;
//    if (derived_metrics == 1) {
//      double l1_misses        = (double) node_punit_counts[0];
//      double loads            = (double) node_punit_counts[1];
//      double l1p_misses       = (double) node_punit_counts[2];
//      double fxu_instructions = (double) node_punit_counts[3];
//      double fpu_instructions = (double) node_punit_counts[4];
//      double fpu_operations   = (double) node_punit_counts[5];
//  
//      // the following are node-averaged metrics; use max_cycles not avg_cycles
//
//      double ipc =(fxu_instructions + fpu_instructions) / (((double) totcores) * max_cycles);
//      double fxu_fraction = fxu_instructions / (fxu_instructions + fpu_instructions);
//      double fpu_fraction = fpu_instructions / (fxu_instructions + fpu_instructions);
//      double max_fraction = (fxu_fraction > fpu_fraction) ? fxu_fraction : fpu_fraction;
//      double percent_max_issue_rate = 100.0*ipc*max_fraction;
//
//      double l1_hits;
//      if (loads > l1_misses) l1_hits = (loads - l1_misses);
//      else                   l1_hits = 0.0;
//      double l1_hit_fraction  = l1_hits / loads;
//
//      double l1p_hits;
//      if (l1_misses > l1p_misses) l1p_hits = (l1_misses - l1p_misses);
//      else                        l1p_hits = 0.0;
//      double l1p_hit_fraction = l1p_hits / loads;
//
//      // Note: L2 hits is generally dominated by prefetch activity
//      double l2_hits;
//      double l2_misses =  data->hpmData.counts[NUM_P_EVENTS+1];
//      if (l1p_misses > l2_misses) l2_hits = (l1p_misses - l2_misses);
//      else                        l2_hits = 0.0;
//      double l2_hit_fraction  = l2_hits / loads;
//
//      // clamp the l2 fraction to make sure numbers add up to 1.0
//      if (l2_hit_fraction > (1.0 - l1_hit_fraction - l1p_hit_fraction)) 
//          l2_hit_fraction = (1.0 - l1_hit_fraction - l1p_hit_fraction);
//
//      double ddr_hit_fraction = 1.0 - l1_hit_fraction - l1p_hit_fraction - l2_hit_fraction;
//
//      // use max_cycles, not avg_cycles
//      double ld_bytes_per_cycle = ((double) (128L * data->hpmData.counts[NUM_P_EVENTS+2])) / max_cycles;
//      double st_bytes_per_cycle = ((double) (128L * data->hpmData.counts[NUM_P_EVENTS+3])) / max_cycles;
//
//      double GFlops = 1.6*fpu_operations / max_cycles;  // 1.6 is for A2 frequency in GHz
//
//      fprintf(fh, "\n");
//      fprintf(fh, "Derived metrics averaged over process(es) on node\n");
//      fprintf(fh, "Instruction mix:  FPU = %.2f %%,  FXU = %.2f %%\n", 100.0*fpu_fraction, 100.0*fxu_fraction);
//      fprintf(fh, "Instructions per cycle completed per core = %.4f\n", ipc);
//      fprintf(fh, "Per cent of max issue rate per core = %.2f %%\n", percent_max_issue_rate);
//      fprintf(fh, "Total weighted GFlops for this node = %.3lf\n", GFlops);
//      fprintf(fh, "Loads that hit in L1 d-cache = %6.2f %%\n", 100.0*l1_hit_fraction);
//      fprintf(fh, "                  L1P buffer = %6.2f %%\n", 100.0*l1p_hit_fraction);
//      fprintf(fh, "                  L2 cache   = %6.2f %%\n", 100.0*l2_hit_fraction);
//      fprintf(fh, "                  DDR        = %6.2f %%\n", 100.0*ddr_hit_fraction);
//      fprintf(fh, "DDR traffic for the node: ld = %.3f, st = %.3f, total = %.3f (Bytes/cycle)\n",
//                   ld_bytes_per_cycle, st_bytes_per_cycle, ld_bytes_per_cycle + st_bytes_per_cycle);
//      fprintf(fh, "\n");
//    }
//  }
//
//  /*------------------------------------------------------------------*/
//  /* print aggregate counts for each job                              */
//  /*------------------------------------------------------------------*/
//
//  int job_scope = 0;
//  if (job_scope) {
//
//    double cores_per_process = ((double) data->procData.hwThreads)/4;
//    double report_cores;
//    PMPI_Allreduce(&cores_per_process, &report_cores, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
//
//    if (data->mpiData.myRank == 0) {
//      fprintf(fh, "======================================================================\n");
//      fprintf(fh, "Aggregate BG/Q counter data for jobid %d\n", data->procData.jobId);
//      fprintf(fh, "This report includes all %d processes in MPI_COMM_WORLD and a total of %.0lf cores\n", 
//                  data->mpiData.numRanks, report_cores);
//      fprintf(fh, "======================================================================\n");
//    }
//
//    // determine average and max cycles for code block for processes in this reporting group
//
//    double cycles = (double) (data->hpmData.finalizeCycle - data->hpmData.initCycle);
//    double avg_cycles, max_cycles;
//    PMPI_Allreduce(&cycles, &max_cycles, 1, MPI_DOUBLE, MPI_MAX, MPI_COMM_WORLD);
//    PMPI_Allreduce(&cycles, &avg_cycles, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
//    avg_cycles = avg_cycles / ((double) data->mpiData.numRanks);
//
//    // sum the A2 counters over all processes in this reporting group
//    // note: this sum should be done with doubles because 64bit ints can overflow
//
//    struct workStruct {double val; int rank; };
//    struct workStruct my_work[NUM_P_EVENTS], min_work[NUM_P_EVENTS], max_work[NUM_P_EVENTS];
//    double dble_counts[NUM_P_EVENTS];
//
//    int i;
//    for (i=0; i<NUM_P_EVENTS; i++)  {
//      dble_counts[i] = (double) data->hpmData.counts[i];
//      my_work[i].val = (double) data->hpmData.counts[i];
//      my_work[i].rank = data->mpiData.myRank;
//    }
//
//    double total_punit_counts[NUM_P_EVENTS];
//    PMPI_Allreduce(dble_counts, total_punit_counts, NUM_P_EVENTS, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
//    PMPI_Allreduce(my_work, min_work, NUM_P_EVENTS, MPI_DOUBLE_INT, MPI_MINLOC, MPI_COMM_WORLD);
//    PMPI_Allreduce(my_work, max_work, NUM_P_EVENTS, MPI_DOUBLE_INT, MPI_MAXLOC, MPI_COMM_WORLD);
//
//    // write counter data
//
//    if (data->mpiData.myRank == 0) {
//      fprintf(fh, "----------------------------------------------------------------\n");
//      fprintf(fh, "avg cycles = %.0f, max cycles = %.0f :\n", avg_cycles, max_cycles);
//      fprintf(fh, "  -- Counter values ------------------------------------------\n");
//      fprintf(fh, "    min-value  min-rank    max-value  max-rank    avg-value   label\n");
//
//      int k;
//      for (k=0; k<NUM_P_EVENTS; k++) {
//        double avg_val = total_punit_counts[k]/((double) data->mpiData.numRanks);
//        fprintf(fh, "%14.6e %7d %14.6e %7d %14.6e %s\n", min_work[k].val, min_work[k].rank,
//                max_work[k].val, max_work[k].rank, avg_val, AP_HPM_GetEventName(data->hpmData.ids[k]));
//      }
//    }
//
//    double l1_misses        = total_punit_counts[0];
//    double loads            = total_punit_counts[1];
//    double l1p_misses       = total_punit_counts[2];
//    double fxu_instructions = total_punit_counts[3];
//    double fpu_instructions = total_punit_counts[4];
//    double fpu_operations   = total_punit_counts[5];
//
//    double max_flops = max_work[5].val;
//    double min_flops = min_work[5].val;
//    double my_flops  = my_work[5].val;
//
//    // the following are group-averaged metrics; use max_cycles not avg_cycles
//
//    double ipc =(fxu_instructions + fpu_instructions) / (report_cores * max_cycles);
//    double fxu_fraction = fxu_instructions / (fxu_instructions + fpu_instructions);
//    double fpu_fraction = fpu_instructions / (fxu_instructions + fpu_instructions);
//    double max_fraction = (fxu_fraction > fpu_fraction) ? fxu_fraction : fpu_fraction;
//    double percent_max_issue_rate = 100.0*ipc*max_fraction;
//
//    double GFlops = 1.6*fpu_operations / max_cycles;  // 1.6 is for A2 frequency in GHz
//
//    if (data->mpiData.myRank == 0) {
//      fprintf(fh, "\n");
//      fprintf(fh, "Derived metrics for code block averaged over all processes\n");
//      fprintf(fh, "Instruction mix:  FPU = %.2f %%,  FXU = %.2f %%\n", 
//                   100.0*fpu_fraction, 100.0*fxu_fraction);
//      fprintf(fh, "Instructions per cycle completed per core = %.4f\n", ipc);
//      fprintf(fh, "Per cent of max issue rate per core = %.2f %%\n", percent_max_issue_rate);
//      fprintf(fh, "Total weighted GFlops = %.3lf\n", GFlops);
//      fprintf(fh, "\n");
//    }
//  }
//
//
//  return;
//}
