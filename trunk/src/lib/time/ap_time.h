/*=======================================================*/
/* define functions and types for measuring time         */
/*=======================================================*/

#ifndef AP_TIME_H
#define AP_TIME_H

#include <stdint.h>
#include <papi.h>
#include "ap_config.h"

typedef uint64_t ap_cycle_t;

#define APCYCLES(TB) TB = PAPI_get_real_cyc()
#define APCTCONV(TB) (SEC_PER_CYCLE*((double) (TB)))

#endif
