/*----------------------------------------------------------*/
/*  types                                                   */
/*----------------------------------------------------------*/

typedef struct {
 int disable_all_env;
 int disable_sys_env;
 int disable_proc_env;
 int disable_mpi_env;
 int disable_hpm_env;

 int output_local_env;
 int output_local_env_val;
 int output_sys_env;
 int output_sys_env_val;

 int debug_level_env;
 int debug_level_env_val;
} ap_env_t;

typedef struct {
  int disable_sys;
  int disable_proc;
  int disable_mpi;
  int disable_hpm;
  int output_local;
  int output_sys;
  int debug_level;
} ap_flag_t;

typedef struct {
  ap_env_t env;
  ap_flag_t flags;
} ap_settings_t;

/*----------------------------------------------------------*/
/*    function prototypes                                   */
/*----------------------------------------------------------*/

void AP_Init(void);
void AP_Finalize(void);
ap_settings_t* AP_getSettings(void);
