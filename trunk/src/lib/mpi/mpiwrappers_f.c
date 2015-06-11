/*===========================================================*/
/* Profiling Wrappers for Fortran  MPI functions             */
/*   can use status==MPI_F_STATUS_IGNORE to test for ignore  */
/*   MPI_UNDEFINED has the same value in fortran or C        */
/*   MPI_PROC_NULL has the same value in fortran or C        */
/*   MPI_ROOT has the same value in fortran or C             */
/*   MPI_IN_PLACE is an address, may be different in F77 & C */
/*     for MPICH can use MPIR_F_MPI_IN_PLACE                 */
/*===========================================================*/


#include "ap_config.h"
#include "autoperf.h"
#include "mpi/ap_mpi.h"
#include "mpi/fpmpi.h"

#define TIME(FUNC) \
          ap_cycle_t TB1, TB2;\
          APCYCLES(TB1); \
          FUNC; \
          APCYCLES(TB2)

#define BYTECOUNT(TYPE, COUNT) \
          MPI_Fint rc2, tsize; \
          pmpi_type_size(TYPE, &tsize, &rc2); \
          ap_bytes_t bytes = (COUNT) * tsize

#define BYTECOUNTND(TYPE, COUNT) \
          MPI_Fint rc3, tsize2; \
          pmpi_type_size(TYPE, &tsize2, &rc3); \
          bytes = (COUNT) * tsize2


/*----------------------------------------------------------*/
/* In fortran MPI_IN_PLACE is not set value, is an address  */
/* Address is fixed through use of a common block.          */
/* MPICH initializes and provides a global variable that    */
/* provides the address of the Fortran MPI_IN_PLACE address */
/* called MPIR_F_MPI_IN_PLACE, this is MPICH specific and   */
/* not standardized in the MPI specification                */
/*----------------------------------------------------------*/

extern void *MPIR_F_MPI_IN_PLACE;


/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_init                            */
/*----------------------------------------------------------*/
void mpi_init(MPI_Fint *ierr)
{
  pmpi_init(ierr);

  AP_Init();

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_init_thread                     */
/*----------------------------------------------------------*/
void mpi_init_thread(MPI_Fint * required, MPI_Fint * provided, MPI_Fint * ierr)
{
  pmpi_init_thread(required, provided, ierr);

  AP_Init();

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_comm_size                       */
/*----------------------------------------------------------*/
void mpi_comm_size(MPI_Fint * comm, MPI_Fint * size, MPI_Fint * ierr)
{
  TIME(pmpi_comm_size(comm, size, ierr));
  AP_MPI_logCall(COMM_SIZE_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_comm_rank                       */
/*----------------------------------------------------------*/
void mpi_comm_rank(MPI_Fint * comm, MPI_Fint * rank, MPI_Fint * ierr)
{
  TIME(pmpi_comm_rank(comm, rank, ierr));
  AP_MPI_logCall(COMM_RANK_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_send                            */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_send(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_send(buf, count, datatype, dest, tag, comm, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(SEND_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_ssend                           */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_ssend(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_ssend(buf, count, datatype, dest, tag, comm, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(SSEND_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_rsend                           */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_rsend(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_rsend(buf, count, datatype, dest, tag, comm, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(RSEND_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_bsend                           */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_bsend(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_bsend(buf, count, datatype, dest, tag, comm, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(BSEND_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_isend                           */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_isend(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_isend(buf, count, datatype, dest, tag, comm, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(ISEND_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_issend                          */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_issend(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_issend(buf, count, datatype, dest, tag, comm, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(ISSEND_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_irsend                          */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_irsend(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_irsend(buf, count, datatype, dest, tag, comm, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(IRSEND_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_ibsend                          */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_ibsend(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_ibsend(buf, count, datatype, dest, tag, comm, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(IBSEND_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_send_init                       */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_send_init(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_send_init(buf, count, datatype, dest, tag, comm, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(SEND_INIT_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_ssend_init                      */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_ssend_init(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_ssend_init(buf, count, datatype, dest, tag, comm, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(SSEND_INIT_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_rsend_init                      */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_rsend_init(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_rsend_init(buf, count, datatype, dest, tag, comm, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(RSEND_INIT_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_bsend_init                      */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
void mpi_bsend_init(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_bsend_init(buf, count, datatype, dest, tag, comm, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(BSEND_INIT_ID, TB1, TB2, NOSRC, (int) *dest, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_recv_init                       */
/*   source may be MPI_ANY_SOURCE or MPI_PROC_NULL          */
/*----------------------------------------------------------*/
void mpi_recv_init(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * source, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_recv_init(buf, count, datatype, source, tag, comm, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(RECV_INIT_ID, TB1, TB2, (int) *source, NODEST, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_recv                            */
/*   source may be MPI_ANY_SOURCE or MPI_PROC_NULL          */
/*   status may be MPI_STATUS_IGNORE                        */
/*----------------------------------------------------------*/
void mpi_recv(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * source, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_recv(buf, count, datatype, source, tag, comm, status, ierr));

  MPI_Fint count_received, rc;
  int src;
  if (status != MPI_F_STATUS_IGNORE) {
    pmpi_get_count(status, datatype, &count_received, &rc);
    if (count_received == MPI_UNDEFINED) count_received = *count;

    MPI_Status cStatus;
    int err = MPI_Status_f2c(status, &cStatus);
    if (err == MPI_SUCCESS) {
      src = cStatus.MPI_SOURCE;
    } else {
      src = *source;
    }
  } else {
    count_received = *count;
    src = *source;
  }

  BYTECOUNT(datatype, count_received);

  AP_MPI_logCall(RECV_ID, TB1, TB2, src, NODEST, bytes, MPI_Comm_f2c(*comm));

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_irecv                           */
/*   source may be MPI_ANY_SOURCE or MPI_PROC_NULL          */
/*----------------------------------------------------------*/
void mpi_irecv(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * source, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_irecv(buf, count, datatype, source, tag, comm, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(IRECV_ID, TB1, TB2, (int) *source, NODEST, bytes, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_sendrecv                        */
/*   dest may be MPI_PROC_NULL                              */
/*   source may be MPI_ANY_SOURCE or MPI_PROC_NULL          */
/*   status may be MPI_STATUS_IGNORE                        */
/*----------------------------------------------------------*/
void mpi_sendrecv(void * sendbuf, MPI_Fint * sendcount, MPI_Fint * sendtype, MPI_Fint * dest, MPI_Fint * sendtag, void * recvbuf, MPI_Fint * recvcount, MPI_Fint * recvtype, MPI_Fint * source, MPI_Fint * recvtag, MPI_Fint * comm, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierr));

  MPI_Fint count_received, rc;
  int src;
  if (status != MPI_F_STATUS_IGNORE) {
    pmpi_get_count(status, recvtype, &count_received, &rc);
    if (count_received == MPI_UNDEFINED) count_received = *recvcount;

    MPI_Status cStatus;
    int err = MPI_Status_f2c(status, &cStatus);
    if (err == MPI_SUCCESS) {
      src = cStatus.MPI_SOURCE;
    } else {
      src = *source;
    }
  } else {
    count_received = *recvcount;
    src = *source;
  }

  BYTECOUNT(sendtype, *sendcount);
  ap_bytes_t sbytes = bytes;
  BYTECOUNTND(recvtype, count_received);
  bytes += sbytes;

  AP_MPI_logCall(SENDRECV_ID, TB1, TB2, src, (int) *dest, bytes, MPI_Comm_f2c(*comm));

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_sendrecv_replace                */
/*   dest may be MPI_PROC_NULL                              */
/*   source may be MPI_ANY_SOURCE or MPI_PROC_NULL          */
/*   status may be MPI_STATUS_IGNORE                        */
/*----------------------------------------------------------*/
void mpi_sendrecv_replace(void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * dest, MPI_Fint * sendtag, MPI_Fint * source, MPI_Fint * recvtag, MPI_Fint * comm, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierr));

  MPI_Fint count_received, rc;
  int src;
  if (status != MPI_F_STATUS_IGNORE) {
    pmpi_get_count(status, datatype, &count_received, &rc);
    if (count_received == MPI_UNDEFINED) count_received = *count;

    MPI_Status cStatus;
    int err = MPI_Status_f2c(status, &cStatus);
    if (err == MPI_SUCCESS) {
      src = cStatus.MPI_SOURCE;
    } else {
      src = (int) *source;
    }
  } else {
    count_received = *count;
    src = (int) *source;
  }

  BYTECOUNT(datatype, *count + count_received);

  AP_MPI_logCall(SENDRECV_REPLACE_ID, TB1, TB2, src, (int) *dest, bytes, MPI_Comm_f2c(*comm));

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_buffer_attach                   */
/*----------------------------------------------------------*/
void mpi_buffer_attach(void * buffer, MPI_Fint * size, MPI_Fint * ierr)
{
  TIME(pmpi_buffer_attach(buffer, size, ierr));
  AP_MPI_logCall(BUFFER_ATTACH_ID, TB1, TB2, NOSRC, NODEST, (ap_bytes_t) *size, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_buffer_detach                   */
/*----------------------------------------------------------*/
void mpi_buffer_detach(void * buffer_addr, MPI_Fint * size, MPI_Fint * ierr)
{
  TIME(pmpi_buffer_detach(buffer_addr, size, ierr));
  AP_MPI_logCall(BUFFER_DETACH_ID, TB1, TB2, NOSRC, NODEST, (ap_bytes_t) *size, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_probe                           */
/* source may be MPI_ANY_SOURCE or MPI_PROC_NULL            */
/* tag may be MPI_ANY_TAG                                   */
/*----------------------------------------------------------*/
void mpi_probe(MPI_Fint * source, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_probe(source, tag, comm, status, ierr));
  AP_MPI_logCall(PROBE_ID, TB1, TB2, (int) *source, NODEST, NOBYTES, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_iprobe                          */
/* source may be MPI_ANY_SOURCE or MPI_PROC_NULL            */
/* tag may be MPI_ANY_TAG                                   */
/* status undefined if no matching message found            */
/*----------------------------------------------------------*/
void mpi_iprobe(MPI_Fint * source, MPI_Fint * tag, MPI_Fint * comm, MPI_Fint * flag, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_iprobe(source, tag, comm, flag, status, ierr));
  AP_MPI_logCall(IPROBE_ID, TB1, TB2, (int) *source, NODEST, NOBYTES, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_test                            */
/*   request arg may be MPI_REQUEST_NULL, no status         */
/*   request may have been canceled, status will show cancel*/
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */
/*   only recieve requests contain loggable data, not send  */
/*----------------------------------------------------------*/
void mpi_test(MPI_Fint * request, MPI_Fint * flag, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_test(request, flag, status, ierr));
  AP_MPI_logCall(TEST_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_testany                         */
/*   request arg may be MPI_REQUEST_NULL, no status         */
/*   request may have been canceled, status will show cancel*/
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */
/*   only recieve requests contain loggable data, not send  */
/*----------------------------------------------------------*/
void mpi_testany(MPI_Fint * count, MPI_Fint array_of_requests[], MPI_Fint * indx, MPI_Fint * flag, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_testany(count, array_of_requests, indx, flag, status, ierr));
  AP_MPI_logCall(TESTANY_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_testall                         */
/*   request arg may be MPI_REQUEST_NULL, no status         */
/*   request may have been canceled, status will show cancel*/
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */
/*   only recieve requests contain loggable data, not send  */
/*----------------------------------------------------------*/
void mpi_testall(MPI_Fint * count, MPI_Fint array_of_requests[], MPI_Fint * flag, MPI_Fint array_of_statuses[], MPI_Fint * ierr)
{
  TIME(pmpi_testall(count, array_of_requests, flag, array_of_statuses, ierr));
  AP_MPI_logCall(TESTALL_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_testsome                        */
/*   request arg may be MPI_REQUEST_NULL, no status         */
/*   request may have been canceled, status will show cancel*/
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */
/*   only recieve requests contain loggable data, not send  */
/*----------------------------------------------------------*/
void mpi_testsome(MPI_Fint * incount, MPI_Fint array_of_requests[], MPI_Fint * outcount, MPI_Fint array_of_indices[], MPI_Fint array_of_statuses[], MPI_Fint * ierr)
{
  TIME(pmpi_testsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierr));
  AP_MPI_logCall(TESTSOME_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_wait                            */
/*   request arg may be MPI_REQUEST_NULL, no status         */
/*   request may have been canceled, status will show cancel*/
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */
/*   only recieve requests contain loggable data, not send  */
/*----------------------------------------------------------*/
void mpi_wait(MPI_Fint * request, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_wait(request, status, ierr));
  AP_MPI_logCall(WAIT_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_waitany                         */
/*   request arg may be MPI_REQUEST_NULL, no status         */
/*   request may have been canceled, status will show cancel*/
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */
/*   only recieve requests contain loggable data, not send  */
/*----------------------------------------------------------*/
void mpi_waitany(MPI_Fint * count, MPI_Fint array_of_requests[], MPI_Fint * indx, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_waitany(count, array_of_requests, indx, status, ierr));
  AP_MPI_logCall(WAITANY_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_waitall                         */
/*   request arg may be MPI_REQUEST_NULL, no status         */
/*   request may have been canceled, status will show cancel*/
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */
/*   only recieve requests contain loggable data, not send  */
/*----------------------------------------------------------*/
void mpi_waitall(MPI_Fint * count, MPI_Fint array_of_requests[], MPI_Fint array_of_statuses[], MPI_Fint * ierr)
{
  TIME(pmpi_waitall(count, array_of_requests, array_of_statuses, ierr));
  AP_MPI_logCall(WAITALL_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_waitsome                        */
/*   request arg may be MPI_REQUEST_NULL, no status         */
/*   request may have been canceled, status will show cancel*/
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */
/*   only recieve requests contain loggable data, not send  */
/*----------------------------------------------------------*/
void mpi_waitsome(MPI_Fint * incount, MPI_Fint array_of_requests[], MPI_Fint * outcount, MPI_Fint array_of_indices[], MPI_Fint array_of_statuses[], MPI_Fint * ierr)
{
  TIME(pmpi_waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierr));
  AP_MPI_logCall(WAITSOME_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_start                           */
/*----------------------------------------------------------*/
void mpi_start(MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_start(request, ierr));
  AP_MPI_logCall(START_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_startall                        */
/*----------------------------------------------------------*/
void mpi_startall(MPI_Fint * count, MPI_Fint array_of_requests[], MPI_Fint * ierr)
{
  TIME(pmpi_startall(count, array_of_requests, ierr));
  AP_MPI_logCall(STARTALL_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_bcast                           */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
void mpi_bcast(void * buffer, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * root, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_bcast(buffer, count, datatype, root, comm, ierr));

  ap_bytes_t bytes = 0;
  if (*root != MPI_PROC_NULL) {
    BYTECOUNTND(datatype, *count);
  }

  AP_MPI_logCall(BCAST_ID, TB1, TB2, (int) *root, NODEST, bytes, MPI_Comm_f2c(*comm)); 

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_barrier                         */
/*----------------------------------------------------------*/
void mpi_barrier(MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_barrier(comm, ierr));
  AP_MPI_logCall(BARRIER_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_Comm_f2c(*comm)); 
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_gather                          */
/*   Receive values ignored except at root                  */
/*   at root sendbuf may be MPI_IN_PLACE                    */
/*   sendcount and sendtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sig.   */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
void mpi_gather(void * sendbuf, MPI_Fint * sendcount, MPI_Fint * sendtype, void * recvbuf, MPI_Fint * recvcount, MPI_Fint * recvtype, MPI_Fint * root, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr));

  ap_bytes_t bytes;
  if (*root == MPI_PROC_NULL) {
    bytes = 0;
  } else if (*root == MPI_ROOT) {
    BYTECOUNTND(recvtype, *recvcount);
  } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
    BYTECOUNTND(recvtype, *recvcount);
  } else {
    BYTECOUNT(sendtype, *sendcount);
  }

  AP_MPI_logCall(GATHER_ID, TB1, TB2, NOSRC, (int) *root, bytes, MPI_Comm_f2c(*comm)); 

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_gatherv                         */
/*   Receive values ignored except at root                  */
/*   at root sendbuf may be MPI_IN_PLACE                    */
/*   sendcount and sendtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sigs.  */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
void mpi_gatherv(void * sendbuf, MPI_Fint * sendcount, MPI_Fint * sendtype, void * recvbuf, MPI_Fint * recvcounts, MPI_Fint * displs, MPI_Fint * recvtype, MPI_Fint * root, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierr));

  ap_bytes_t bytes;
  if (*root == MPI_PROC_NULL) {
    bytes = 0;
  } else if (*root == MPI_ROOT) {
    bytes = 0;
  } else if (sendbuf == MPIR_F_MPI_IN_PLACE) {
    BYTECOUNTND(recvtype, recvcounts[*root]);
  } else {
    BYTECOUNT(sendtype, *sendcount);
  }

  AP_MPI_logCall(GATHERV_ID, TB1, TB2, NOSRC, (int) *root, bytes, MPI_Comm_f2c(*comm)); 

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_scatter                         */
/*   send values ignored except at root                     */
/*   all args significant at root                           */
/*   at root recvbuf may be MPI_IN_PLACE                    */
/*   recvcount and recvtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sig.   */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
void mpi_scatter(void * sendbuf, MPI_Fint * sendcount, MPI_Fint * sendtype, void * recvbuf, MPI_Fint * recvcount, MPI_Fint * recvtype, MPI_Fint * root, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr));

  ap_bytes_t bytes;
  if (*root == MPI_PROC_NULL) {
    bytes = 0;
  } else if (*root == MPI_ROOT) {
    BYTECOUNTND(recvtype, *recvcount);
  } else if (recvbuf == MPIR_F_MPI_IN_PLACE) {
    BYTECOUNTND(sendtype, *sendcount);
  } else {
    BYTECOUNTND(recvtype, *recvcount);
  }

  AP_MPI_logCall(SCATTER_ID, TB1, TB2, (int) *root, NODEST, bytes, MPI_Comm_f2c(*comm)); 

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_scatterv                        */
/*   send values ignored except at root                     */
/*   all args significant at root                           */
/*   at root recvbuf may be MPI_IN_PLACE                    */
/*   recvcount and recvtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sig.   */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
void mpi_scatterv(void * sendbuf, MPI_Fint * sendcounts, MPI_Fint * displs, MPI_Fint * sendtype, void * recvbuf, MPI_Fint * recvcount, MPI_Fint * recvtype, MPI_Fint * root, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierr));

  ap_bytes_t bytes;
  if (*root == MPI_PROC_NULL) {
    bytes = 0;
  } else if (*root == MPI_ROOT) {
    bytes = 0;
  } else if (recvbuf == MPIR_F_MPI_IN_PLACE) {
    BYTECOUNTND(sendtype, sendcounts[*root]);
  } else {
    BYTECOUNTND(recvtype, *recvcount);
  }

  AP_MPI_logCall(SCATTERV_ID, TB1, TB2, (int) *root, NODEST, bytes, MPI_Comm_f2c(*comm)); 

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_scan                            */
/*----------------------------------------------------------*/
void mpi_scan(void * sendbuf, void * recvbuf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * op, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_scan(sendbuf, recvbuf, count, datatype, op, comm, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(SCAN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_Comm_f2c(*comm)); 
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_allgather                       */
/*   sendbuf may be MPI_IN_PLACE                            */
/*   sendcount and sendtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sig.   */
/*    todo: handle MPI_IN_PLACE                             */
/*----------------------------------------------------------*/
void mpi_allgather(void * sendbuf, MPI_Fint * sendcount, MPI_Fint * sendtype, void * recvbuf, MPI_Fint * recvcount, MPI_Fint * recvtype, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr));
  ap_bytes_t bytes;
  if (sendbuf != MPIR_F_MPI_IN_PLACE) {
    BYTECOUNTND(sendtype, *sendcount);
  } else {
    BYTECOUNTND(recvtype, *recvcount);
  }
  AP_MPI_logCall(ALLGATHER_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_Comm_f2c(*comm)); 
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_allgatherv                      */
/*   sendbuf may be MPI_IN_PLACE                            */
/*   sendcount and sendtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sig.   */
/*    todo: handle MPI_IN_PLACE                             */
/*----------------------------------------------------------*/
void mpi_allgatherv(void * sendbuf, MPI_Fint * sendcount, MPI_Fint * sendtype, void * recvbuf, MPI_Fint * recvcounts, MPI_Fint * displs, MPI_Fint * recvtype, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierr));
  ap_bytes_t bytes;
  if (sendbuf != MPIR_F_MPI_IN_PLACE) {
    BYTECOUNTND(sendtype, *sendcount);
  } else {
    MPI_Fint rank;
    MPI_Fint *ierr;
    pmpi_comm_rank(comm, &rank, ierr);
    BYTECOUNTND(recvtype, recvcounts[rank]);
  }
  AP_MPI_logCall(ALLGATHERV_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_Comm_f2c(*comm)); 
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_reduce                          */
/*   at root sendbuf may be MPI_IN_PLACE                    */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
void mpi_reduce(void * sendbuf, void * recvbuf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * op, MPI_Fint * root, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_reduce(sendbuf, recvbuf, count, datatype, op, root, comm, ierr));

  ap_bytes_t bytes;
  if (*root == MPI_PROC_NULL) {
    bytes = 0;
  } else {
    BYTECOUNTND(datatype, *count);
  }

  AP_MPI_logCall(REDUCE_ID, TB1, TB2, NOSRC, (int) *root, bytes, MPI_Comm_f2c(*comm)); 

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_allreduce                       */
/*----------------------------------------------------------*/
void mpi_allreduce(void * sendbuf, void * recvbuf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * op, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_allreduce(sendbuf, recvbuf, count, datatype, op, comm, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(ALLREDUCE_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_Comm_f2c(*comm)); 
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_reduce_scatter                  */
/*----------------------------------------------------------*/
void mpi_reduce_scatter(void * sendbuf, void * recvbuf, MPI_Fint recvcounts[], MPI_Fint * datatype, MPI_Fint * op, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierr));

  MPI_Fint rc, tsize;
  pmpi_type_size(datatype, &tsize, &rc);

  MPI_Fint tasks;
  int i, num = 0;
  pmpi_comm_size(comm, &tasks, &rc);
  for (i=0; i<tasks; i++) num += recvcounts[i];
  ap_bytes_t bytes = num * tsize;

  AP_MPI_logCall(REDUCE_SCATTER_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_Comm_f2c(*comm)); 

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_alltoall                        */
/*   sendbuf may be MPI_IN_PLACE                            */
/*   sendcount and sendtype are ignored for MPI_IN_PLACE    */
/*   recvcount*recvtype must be consistent with send sig.   */
/*     for intercommunicators                               */
/*----------------------------------------------------------*/
void mpi_alltoall(void * sendbuf, MPI_Fint * sendcount, MPI_Fint * sendtype, void * recvbuf, MPI_Fint * recvcount, MPI_Fint * recvtype, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierr));
  BYTECOUNT(recvtype, *recvcount);

  MPI_Fint tasks, rc;
  pmpi_comm_size(comm, &tasks, &rc);
  bytes = bytes*tasks;

  AP_MPI_logCall(ALLTOALL_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_Comm_f2c(*comm)); 

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_alltoallv                       */
/*   sendbuf may be MPI_IN_PLACE                            */
/*   sendcount,sendtype,sdispls are ignored for MPI_IN_PLACE*/
/*   recvcount*recvtype must be consistent with send sig.   */
/*     for intercommunicators                               */
/*----------------------------------------------------------*/
void mpi_alltoallv(void * sendbuf, MPI_Fint * sendcounts, MPI_Fint * sdispls, MPI_Fint * sendtype, void * recvbuf, MPI_Fint * recvcounts, MPI_Fint * rdispls, MPI_Fint * recvtype, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierr));

  MPI_Fint tsize, rc;
  pmpi_type_size(recvtype, &tsize, &rc);

  int i, count = 0;
  MPI_Fint tasks;
  pmpi_comm_size(comm, &tasks, &rc);
  for (i=0; i<tasks; i++) count += recvcounts[i];

  ap_bytes_t bytes = (ap_bytes_t) (count * tsize);

  AP_MPI_logCall(ALLTOALLV_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_Comm_f2c(*comm)); 

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_alltoallw                       */
/*   sendbuf may be MPI_IN_PLACE                            */
/*   sendcount,sendtype,sdispls are ignored for MPI_IN_PLACE*/
/*   recvcount*recvtype must be consistent with send sig.   */
/*     for intercommunicators                               */
/*----------------------------------------------------------*/
void mpi_alltoallw(void * sendbuf, MPI_Fint sendcounts[], MPI_Fint sdispls[], MPI_Fint sendtypes[], void * recvbuf, MPI_Fint recvcounts[], MPI_Fint rdispls[], MPI_Fint recvtypes[], MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierr));

  ap_bytes_t bytes = 0;
  int i;
  MPI_Fint tasks, tsize, rc;
  pmpi_comm_size(comm, &tasks, &rc);
  for (i=0; i<tasks; i++) {
    pmpi_type_size(&(recvtypes[i]), &tsize, &rc);
    bytes += recvcounts[i]*tsize;
  }

  AP_MPI_logCall(ALLTOALLW_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_Comm_f2c(*comm));

  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_exscan                          */
/*----------------------------------------------------------*/
void mpi_exscan(void * sendbuf, void * recvbuf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * op, MPI_Fint * comm, MPI_Fint * ierr)
{
  TIME(pmpi_exscan(sendbuf, recvbuf, count, datatype, op, comm, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(EXSCAN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_Comm_f2c(*comm)); 
  return;
}

/* Enable or disable the wrappers for MPI-IO  */
#ifdef AP_MPIO_WRAPPERS_ENABLE

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_close                      */
/*----------------------------------------------------------*/
void mpi_file_close(MPI_Fint * fh, MPI_Fint * ierr)
{
  TIME(pmpi_file_close(fh, ierr));
  AP_MPI_logCall(FILE_CLOSE_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_delete                     */
/*----------------------------------------------------------*/
void mpi_file_delete(char * filename AP_FORT_MIXED_LEN(d1), MPI_Fint * info, MPI_Fint * ierr AP_FORT_END_LEN(d1))
{
  TIME(pmpi_file_delete(filename AP_FORT_MIXED_LEN_ARG(d1), info, ierr AP_FORT_END_LEN_ARG(d1)));
  AP_MPI_logCall(FILE_DELETE_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_iread                      */
/*----------------------------------------------------------*/
void mpi_file_iread(MPI_Fint * fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_file_iread(fh, buf, count, datatype, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_IREAD_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_iread_at                   */
/*----------------------------------------------------------*/
void mpi_file_iread_at(MPI_Fint * fh, MPI_Offset * offset, void * buf, MPI_Fint  * count, MPI_Fint * datatype, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_file_iread_at(fh, offset, buf, count, datatype, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_IREAD_AT_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_iread_shared               */
/*----------------------------------------------------------*/
void mpi_file_iread_shared(MPI_Fint * fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_file_iread_shared(fh, buf, count, datatype, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_IREAD_SHARED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_iwrite                     */
/*----------------------------------------------------------*/
void mpi_file_iwrite(MPI_Fint * fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_file_iwrite(fh, buf, count, datatype, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_IWRITE_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_iwrite_at                  */
/*----------------------------------------------------------*/
void mpi_file_iwrite_at(MPI_Fint * fh, MPI_Offset * offset, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_file_iwrite_at(fh, offset, buf, count, datatype, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_IWRITE_AT_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_iwrite_shared              */
/*----------------------------------------------------------*/
void mpi_file_iwrite_shared(MPI_Fint * fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * request, MPI_Fint * ierr)
{
  TIME(pmpi_file_iwrite_shared(fh, buf, count, datatype, request, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_IWRITE_SHARED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_open                       */
/*----------------------------------------------------------*/
void mpi_file_open(MPI_Fint * comm, char * filename AP_FORT_MIXED_LEN(d2), MPI_Fint * amode, MPI_Fint * info, MPI_Fint * fh, MPI_Fint * ierr AP_FORT_END_LEN(d2) )
{
  TIME(pmpi_file_open(comm, filename AP_FORT_MIXED_LEN_ARG(d2), amode, info, fh, ierr AP_FORT_END_LEN_ARG(d2)));
  AP_MPI_logCall(FILE_OPEN_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_Comm_f2c(*comm));
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_preallocate                */
/*----------------------------------------------------------*/
void mpi_file_preallocate(MPI_Fint * fh, MPI_Offset * size, MPI_Fint * ierr)
{
  TIME(pmpi_file_preallocate(fh, size, ierr));
  AP_MPI_logCall(FILE_PREALLOCATE_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read                       */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */
/*----------------------------------------------------------*/
void mpi_file_read(MPI_Fint * fh, void * buf, MPI_Fint  * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_read(fh, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_READ_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_all                   */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */
/*----------------------------------------------------------*/
void mpi_file_read_all(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_all(fh, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_READ_ALL_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_all_begin             */
/*----------------------------------------------------------*/
void mpi_file_read_all_begin(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_all_begin(fh, buf, count, datatype, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_READ_ALL_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_all_end               */
/*----------------------------------------------------------*/
void mpi_file_read_all_end(MPI_Fint* fh, void * buf, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_all_end(fh, buf, status, ierr));
  AP_MPI_logCall(FILE_READ_ALL_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_at                    */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */
/*----------------------------------------------------------*/
void mpi_file_read_at(MPI_Fint* fh, MPI_Offset * offset, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_at(fh, offset, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_READ_AT_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_at_all                */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */
/*----------------------------------------------------------*/
void mpi_file_read_at_all(MPI_Fint* fh, MPI_Offset * offset, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_at_all(fh, offset, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_READ_AT_ALL_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_at_all_begin          */
/*----------------------------------------------------------*/
void mpi_file_read_at_all_begin(MPI_Fint* fh, MPI_Offset * offset, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_at_all_begin(fh, offset, buf, count, datatype, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_READ_AT_ALL_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_at_all_end            */
/*----------------------------------------------------------*/
void mpi_file_read_at_all_end(MPI_Fint* fh, void * buf, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_at_all_end(fh, buf, status, ierr));
  AP_MPI_logCall(FILE_READ_AT_ALL_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_ordered               */
/*----------------------------------------------------------*/
void mpi_file_read_ordered(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_ordered(fh, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_READ_ORDERED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_ordered_begin         */
/*----------------------------------------------------------*/
void mpi_file_read_ordered_begin(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_ordered_begin(fh, buf, count, datatype, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_READ_ORDERED_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_ordered_end           */
/*----------------------------------------------------------*/
void mpi_file_read_ordered_end(MPI_Fint* fh, void * buf, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_ordered_end(fh, buf, status, ierr));
  AP_MPI_logCall(FILE_READ_ORDERED_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_read_shared                */
/*----------------------------------------------------------*/
void mpi_file_read_shared(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_read_shared(fh, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_READ_SHARED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_seek                       */
/*----------------------------------------------------------*/
void mpi_file_seek(MPI_Fint* fh, MPI_Offset * offset, MPI_Fint * whence, MPI_Fint * ierr)
{
  TIME(pmpi_file_seek(fh, offset, whence, ierr));
  AP_MPI_logCall(FILE_SEEK_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_seek_shared                */
/*----------------------------------------------------------*/
void mpi_file_seek_shared(MPI_Fint* fh, MPI_Offset * offset, MPI_Fint * whence, MPI_Fint * ierr)
{
  TIME(pmpi_file_seek_shared(fh, offset, whence, ierr));
  AP_MPI_logCall(FILE_SEEK_SHARED_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_set_view                   */
/*----------------------------------------------------------*/
void mpi_file_set_view(MPI_Fint* fh, MPI_Offset * disp, MPI_Fint * etype, MPI_Fint * filetype, char * datarep AP_FORT_MIXED_LEN(d5), MPI_Fint * info, MPI_Fint * ierr AP_FORT_END_LEN(d5))
{
  TIME(pmpi_file_set_view(fh, disp, etype, filetype, datarep AP_FORT_MIXED_LEN_ARG(d5), info, ierr AP_FORT_END_LEN_ARG(d5)));
  AP_MPI_logCall(FILE_SET_VIEW_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_sync                       */
/*----------------------------------------------------------*/
void mpi_file_sync(MPI_Fint* fh, MPI_Fint * ierr)
{
  TIME(pmpi_file_sync(fh, ierr));
  AP_MPI_logCall(FILE_SYNC_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write                      */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */
/*----------------------------------------------------------*/
void mpi_file_write(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_write(fh, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_WRITE_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_all                  */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */
/*----------------------------------------------------------*/
void mpi_file_write_all(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_all(fh, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_WRITE_ALL_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_all_begin            */
/*----------------------------------------------------------*/
void mpi_file_write_all_begin(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_all_begin(fh, buf, count, datatype, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_WRITE_ALL_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_all_end              */
/*----------------------------------------------------------*/
void mpi_file_write_all_end(MPI_Fint* fh, void * buf, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_all_end(fh, buf, status, ierr));
  AP_MPI_logCall(FILE_WRITE_ALL_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_at                   */
/*----------------------------------------------------------*/
void mpi_file_write_at(MPI_Fint* fh, MPI_Offset * offset, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_at(fh, offset, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_WRITE_AT_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_at_all               */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */
/*----------------------------------------------------------*/
void mpi_file_write_at_all(MPI_Fint* fh, MPI_Offset * offset, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_at_all(fh, offset, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_WRITE_AT_ALL_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_at_all_begin         */
/*----------------------------------------------------------*/
void mpi_file_write_at_all_begin(MPI_Fint* fh, MPI_Offset * offset, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_at_all_begin(fh, offset, buf, count, datatype, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_WRITE_AT_ALL_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_at_all_end           */
/*----------------------------------------------------------*/
void mpi_file_write_at_all_end(MPI_Fint* fh, void * buf, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_at_all_end(fh, buf, status, ierr));
  AP_MPI_logCall(FILE_WRITE_AT_ALL_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_ordered              */
/*----------------------------------------------------------*/
void mpi_file_write_ordered(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_ordered(fh, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_WRITE_ORDERED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_ordered_begin        */
/*----------------------------------------------------------*/
void mpi_file_write_ordered_begin(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_ordered_begin(fh, buf, count, datatype, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_WRITE_ORDERED_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_ordered_end          */
/*----------------------------------------------------------*/
void mpi_file_write_ordered_end(MPI_Fint* fh, void * buf, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_ordered_end(fh, buf, status, ierr));
  AP_MPI_logCall(FILE_WRITE_ORDERED_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return;
}

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_file_write_shared               */
/*----------------------------------------------------------*/
void mpi_file_write_shared(MPI_Fint* fh, void * buf, MPI_Fint * count, MPI_Fint * datatype, MPI_Fint * status, MPI_Fint * ierr)
{
  TIME(pmpi_file_write_shared(fh, buf, count, datatype, status, ierr));
  BYTECOUNT(datatype, *count);
  AP_MPI_logCall(FILE_WRITE_SHARED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return;
}

/* end of if AP_MPIO_WRAPPERS == DISABLED */
#endif

/*----------------------------------------------------------*/
/* wrapper for Fortran: mpi_finalize                        */
/*----------------------------------------------------------*/
void mpi_finalize(MPI_Fint * ierr)
{
  AP_Finalize();

  pmpi_finalize(ierr);

  return;
}
