
typedef struct {
  int disabled;
  int coresPerNode;
  int hwThreadsPerCore;
} ap_sysData_t;


int AP_Sys_Init(int);
int AP_Sys_Finalize(void);
int AP_Sys_GetData(ap_sysData_t* );
