#include <stdio.h>
#include <stdint.h>
#include <autoperf.h>
#include <sys/ap_sys.h>
#include <proc/ap_proc.h>
#include <hpm/ap_hpm.h>
#include <mpi/ap_mpi.h>

#define NO_RANK_IN_NAME -1
#define NO_APPEND_PATH 0
#define APPEND_PATH 1

FILE * AP_openOutputFile(char *, int, uint64_t, int, int);
int AP_writeSettings(FILE *, ap_settings_t *);
int AP_writeSysData(FILE *, char *, ap_sysData_t *);
int AP_writeProcData(FILE *, char *, ap_procData_t *);
int AP_writeHPMData(FILE *, char *, ap_hpmData_t *);
int AP_writeMPIData(FILE *, char *, ap_mpiData_t *);
int AP_writeProcDataLoc(FILE *, ap_procData_t *);
int AP_writeHPMDataLoc(FILE *, ap_hpmData_t *);
int AP_writeMPIDataLoc(FILE *, ap_mpiData_t *);
