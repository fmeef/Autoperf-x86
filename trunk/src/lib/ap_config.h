/*=======================================================*/
/* Autoperf configuration settings                       */
/*=======================================================*/

#ifndef AP_CONFIG_H
#define AP_CONFIG_H

// configure time
#define SEC_PER_CYCLE 0.625e-9

// configure output
//#define OUTPUT_SYS_DIR "/gpfs/mira-fs0/logs/autoperf"
#define OUTPUT_SYS_DIR "/home/gnu3ra/argonne/autoperf/output"
#define OUTPUT_LOCAL_DIR "."

// configure system component
#define CORES_PER_NODE 16
#define HW_THREADS_PER_CORE 4

// configure MPI component
#define AP_MPIO_WRAPPERS_ENABLE              // Define to enable MPI-IO wrappers

#endif
