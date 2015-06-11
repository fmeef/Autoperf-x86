/*==========================================================*/
/* Profiling Wrappers for C MPI functions                   */
/*==========================================================*/

#include "ap_config.h"
#include "autoperf.h"
#include "mpi/ap_mpi.h"
#include "time/ap_time.h"

#define APMPICONST

#define TIME(FUNC) \
          ap_cycle_t TB1, TB2;\
          APCYCLES(TB1); \
          int rc = FUNC; \
          APCYCLES(TB2)

#define BYTECOUNT(TYPE, COUNT) \
          int tsize; \
          PMPI_Type_size(TYPE, &tsize); \
          ap_bytes_t bytes = (COUNT) * tsize

#define BYTECOUNTND(TYPE, COUNT) \
          int tsize2; \
          PMPI_Type_size(TYPE, &tsize2); \
          bytes = (COUNT) * tsize2

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Init                                  */
/*----------------------------------------------------------*/
int MPI_Init(int * argc, char *** argv)
{
  int rc = PMPI_Init(argc, argv);

  AP_Init();

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Init_thread                           */
/*----------------------------------------------------------*/
int MPI_Init_thread(int * argc, char *** argv, int required, int * provided)
{
  int rc = PMPI_Init_thread(argc, argv, required, provided);

  AP_Init();

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Comm_size                             */
/*----------------------------------------------------------*/
int MPI_Comm_size(MPI_Comm comm, int * size)
{
  TIME(PMPI_Comm_size(comm, size));
  AP_MPI_logCall(COMM_SIZE_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Comm_rank                             */
/*----------------------------------------------------------*/
int MPI_Comm_rank(MPI_Comm comm, int * rank)
{
  TIME(PMPI_Comm_rank(comm, rank));
  AP_MPI_logCall(COMM_RANK_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Send                                  */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Send(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
  TIME(PMPI_Send(buf, count, datatype, dest, tag, comm));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(SEND_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Ssend                                 */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Ssend(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
  TIME(PMPI_Ssend(buf, count, datatype, dest, tag, comm));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(SSEND_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Rsend                                 */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Rsend(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
  TIME(PMPI_Rsend(buf, count, datatype, dest, tag, comm));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(RSEND_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Bsend                                 */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Bsend(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
  TIME(PMPI_Bsend(buf, count, datatype, dest, tag, comm));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(BSEND_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Isend                                 */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Isend(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request)
{
  TIME(PMPI_Isend(buf, count, datatype, dest, tag, comm, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(ISEND_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Issend                                */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Issend(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request)
{
  TIME(PMPI_Issend(buf, count, datatype, dest, tag, comm, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(ISSEND_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Irsend                                */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Irsend(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request)
{
  TIME(PMPI_Irsend(buf, count, datatype, dest, tag, comm, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(IRSEND_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Ibsend                                */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Ibsend(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request)
{
  TIME(PMPI_Ibsend(buf, count, datatype, dest, tag, comm, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(IBSEND_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Send_init                             */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Send_init(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request)
{
  TIME(PMPI_Send_init(buf, count, datatype, dest, tag, comm, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(SEND_INIT_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Ssend_init                            */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Ssend_init(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request)
{
  TIME(PMPI_Ssend_init(buf, count, datatype, dest, tag, comm, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(SSEND_INIT_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Rsend_init                            */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Rsend_init(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request)
{
  TIME(PMPI_Rsend_init(buf, count, datatype, dest, tag, comm, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(RSEND_INIT_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Bsend_init                            */
/*   dest may be MPI_PROC_NULL                              */
/*----------------------------------------------------------*/
int MPI_Bsend_init(APMPICONST void * buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request)
{
  TIME(PMPI_Bsend_init(buf, count, datatype, dest, tag, comm, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(BSEND_INIT_ID, TB1, TB2, NOSRC, dest, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Recv_init                             */
/*   source may be MPI_ANY_SOURCE or MPI_PROC_NULL          */
/*----------------------------------------------------------*/
int MPI_Recv_init(void * buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request * request)
{
  TIME(PMPI_Recv_init(buf, count, datatype, source, tag, comm, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(RECV_INIT_ID, TB1, TB2, source, NODEST, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Recv                                  */
/*   source may be MPI_ANY_SOURCE or MPI_PROC_NULL          */
/*   status may be MPI_STATUS_IGNORE                        */
/*----------------------------------------------------------*/
int MPI_Recv(void * buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status * status)
{
  TIME(PMPI_Recv(buf, count, datatype, source, tag, comm, status));

  int count_received, src;
  if (status != MPI_STATUS_IGNORE) {
    PMPI_Get_count(status, datatype, &count_received);
    if (count_received == MPI_UNDEFINED) count_received = count;
    src = status->MPI_SOURCE;
  } else {
    count_received = count;
    src = source;
  }

  BYTECOUNT(datatype, count_received);

  AP_MPI_logCall(RECV_ID, TB1, TB2, src, NODEST, bytes, comm);

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Irecv                                 */
/*   source may be MPI_ANY_SOURCE or MPI_PROC_NULL          */
/*----------------------------------------------------------*/
int MPI_Irecv(void * buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request * request)
{
  TIME(PMPI_Irecv(buf, count, datatype, source, tag, comm, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(IRECV_ID, TB1, TB2, source, NODEST, bytes, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Sendrecv                              */
/*   dest may be MPI_PROC_NULL                              */
/*   source may be MPI_ANY_SOURCE or MPI_PROC_NULL          */
/*   status may be MPI_STATUS_IGNORE                        */
/*----------------------------------------------------------*/
int MPI_Sendrecv(APMPICONST void * sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void * recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status * status)
{
  TIME(PMPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status));

  int count_received, src;
  if (status != MPI_STATUS_IGNORE) {
    PMPI_Get_count(status, recvtype, &count_received);
    if (count_received == MPI_UNDEFINED) count_received = recvcount;
    src = status->MPI_SOURCE;
  } else {
    count_received = recvcount;
    src = source;
  }

  BYTECOUNT(sendtype, sendcount);
  ap_bytes_t sbytes = bytes;
  BYTECOUNTND(recvtype, count_received);
  bytes += sbytes;

  AP_MPI_logCall(SENDRECV_ID, TB1, TB2, src, dest, bytes, comm);

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Sendrecv_replace                      */
/*   dest may be MPI_PROC_NULL                              */
/*   source may be MPI_ANY_SOURCE or MPI_PROC_NULL          */
/*   status may be MPI_STATUS_IGNORE                        */
/*----------------------------------------------------------*/
int MPI_Sendrecv_replace(void * buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status * status)
{
  TIME(PMPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status));

  int count_received, src;
  if (status != MPI_STATUS_IGNORE) {
    PMPI_Get_count(status, datatype, &count_received);
    if (count_received == MPI_UNDEFINED) count_received = count;
    src = status->MPI_SOURCE;
  } else {
    count_received = count;
    src = source;
  }

  BYTECOUNT(datatype, count + count_received);

  AP_MPI_logCall(SENDRECV_REPLACE_ID, TB1, TB2, src, dest, bytes, comm);

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Buffer_attach                         */
/*----------------------------------------------------------*/
int MPI_Buffer_attach(void * buffer, int size)
{
  TIME(PMPI_Buffer_attach(buffer, size));
  AP_MPI_logCall(BUFFER_ATTACH_ID, TB1, TB2, NOSRC, NODEST, (ap_bytes_t) size, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Buffer_detach                         */
/*----------------------------------------------------------*/
int MPI_Buffer_detach(void * buffer_addr, int * size)
{
  TIME(PMPI_Buffer_detach(buffer_addr, size));
  AP_MPI_logCall(BUFFER_DETACH_ID, TB1, TB2, NOSRC, NODEST, (ap_bytes_t) size, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Probe                                 */
/* source may be MPI_ANY_SOURCE or MPI_PROC_NULL            */
/* tag may be MPI_ANY_TAG                                   */
/*----------------------------------------------------------*/
int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status * status)
{
  TIME(PMPI_Probe(source, tag, comm, status));
  AP_MPI_logCall(PROBE_ID, TB1, TB2, source, NODEST, NOBYTES, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Iprobe                                */
/* source may be MPI_ANY_SOURCE or MPI_PROC_NULL            */
/* tag may be MPI_ANY_TAG                                   */
/* status undefined if no matching message found            */
/*----------------------------------------------------------*/
int MPI_Iprobe(int source, int tag, MPI_Comm comm, int * flag, MPI_Status * status)
{
  TIME(PMPI_Iprobe(source, tag, comm, flag, status));
  AP_MPI_logCall(IPROBE_ID, TB1, TB2, source, NODEST, NOBYTES, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Test                                  */
/*   request arg may be MPI_REQUEST_NULL, no status         */  
/*   request may have been canceled, status will show cancel*/  
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */  
/*   only recieve requests contain loggable data, not send  */  
/*----------------------------------------------------------*/
int MPI_Test(MPI_Request * request, int * flag, MPI_Status * status)
{
  TIME(PMPI_Test(request, flag, status));
  AP_MPI_logCall(TEST_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Testany                               */
/*   request arg may be MPI_REQUEST_NULL, no status         */  
/*   request may have been canceled, status will show cancel*/  
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */  
/*   only recieve requests contain loggable data, not send  */  
/*----------------------------------------------------------*/
int MPI_Testany(int count, MPI_Request array_of_requests[], int * indx, int * flag, MPI_Status * status)
{
  TIME(PMPI_Testany(count, array_of_requests, indx, flag, status));
  AP_MPI_logCall(TESTANY_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Testall                               */
/*   request arg may be MPI_REQUEST_NULL, no status         */  
/*   request may have been canceled, status will show cancel*/  
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */  
/*   only recieve requests contain loggable data, not send  */  
/*----------------------------------------------------------*/
int MPI_Testall(int count, MPI_Request array_of_requests[], int * flag, MPI_Status array_of_statuses[])
{
  TIME(PMPI_Testall(count, array_of_requests, flag, array_of_statuses));
  AP_MPI_logCall(TESTALL_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Testsome                              */
/*   request arg may be MPI_REQUEST_NULL, no status         */  
/*   request may have been canceled, status will show cancel*/  
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */  
/*   only recieve requests contain loggable data, not send  */  
/*----------------------------------------------------------*/
int MPI_Testsome(int incount, MPI_Request array_of_requests[], int * outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
  TIME(PMPI_Testsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses));
  AP_MPI_logCall(TESTSOME_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Wait                                  */
/*   request arg may be MPI_REQUEST_NULL, no status         */  
/*   request may have been canceled, status will show cancel*/  
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */  
/*   only recieve requests contain loggable data, not send  */  
/*----------------------------------------------------------*/
int MPI_Wait(MPI_Request * request, MPI_Status * status)
{
  TIME(PMPI_Wait(request, status));
  AP_MPI_logCall(WAIT_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Waitany                               */
/*   request arg may be MPI_REQUEST_NULL, no status         */  
/*   request may have been canceled, status will show cancel*/  
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */  
/*   only recieve requests contain loggable data, not send  */  
/*----------------------------------------------------------*/
int MPI_Waitany(int count, MPI_Request array_of_requests[], int * indx, MPI_Status * status)
{
  TIME(PMPI_Waitany(count, array_of_requests, indx, status));
  AP_MPI_logCall(WAITANY_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Waitall                               */
/*   request arg may be MPI_REQUEST_NULL, no status         */  
/*   request may have been canceled, status will show cancel*/  
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */  
/*   only recieve requests contain loggable data, not send  */  
/*----------------------------------------------------------*/
int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status array_of_statuses[])
{
  TIME(PMPI_Waitall(count, array_of_requests, array_of_statuses));
  AP_MPI_logCall(WAITALL_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Waitsome                              */
/*   request arg may be MPI_REQUEST_NULL, no status         */  
/*   request may have been canceled, status will show cancel*/  
/*   status arg may be MPI_STATUS_IGNORE, if so no status   */  
/*   only recieve requests contain loggable data, not send  */  
/*----------------------------------------------------------*/
int MPI_Waitsome(int incount, MPI_Request array_of_requests[], int * outcount, int array_of_indices[], MPI_Status array_of_statuses[])
{
  TIME(PMPI_Waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses));
  AP_MPI_logCall(WAITSOME_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Start                                 */
/*----------------------------------------------------------*/
int MPI_Start(MPI_Request * request)
{
  TIME(PMPI_Start(request));
  AP_MPI_logCall(START_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Startall                              */
/*----------------------------------------------------------*/
int MPI_Startall(int count, MPI_Request array_of_requests[])
{
  TIME(PMPI_Startall(count, array_of_requests));
  AP_MPI_logCall(STARTALL_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Bcast                                 */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
int MPI_Bcast(void * buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm)
{
  TIME(PMPI_Bcast(buffer, count, datatype, root, comm));

  ap_bytes_t bytes = 0;
  if (root != MPI_PROC_NULL) {
    BYTECOUNTND(datatype, count);
  }

  AP_MPI_logCall(BCAST_ID, TB1, TB2, root, NODEST, bytes, comm); 

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Barrier                               */
/*----------------------------------------------------------*/
int MPI_Barrier(MPI_Comm comm)
{
  TIME(PMPI_Barrier(comm));
  AP_MPI_logCall(BARRIER_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, comm); 
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Gather                                */
/*   Receive values ignored except at root                  */
/*   at root sendbuf may be MPI_IN_PLACE                    */
/*   sendcount and sendtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sig.   */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
int MPI_Gather(APMPICONST void * sendbuf, int sendcount, MPI_Datatype sendtype, void * recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
  TIME(PMPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm));
  
  ap_bytes_t bytes = 0;
  if (root == MPI_PROC_NULL) {
    bytes = 0;
  } else if (root == MPI_ROOT) {
    BYTECOUNTND(recvtype, recvcount);
  } else if (sendbuf == MPI_IN_PLACE) {
    BYTECOUNTND(recvtype, recvcount);
  } else {
    BYTECOUNTND(sendtype, sendcount);
  }

  AP_MPI_logCall(GATHER_ID, TB1, TB2, NOSRC, root, bytes, comm); 

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Gatherv                               */
/*   Receive values ignored except at root                  */
/*   at root sendbuf may be MPI_IN_PLACE                    */
/*   sendcount and sendtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sigs. */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
int MPI_Gatherv(APMPICONST void * sendbuf, int sendcount, MPI_Datatype sendtype, void * recvbuf, APMPICONST int * recvcounts, APMPICONST int * displs, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
  TIME(PMPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm));

  ap_bytes_t bytes = 0;
  if (root == MPI_PROC_NULL) {
    bytes = 0;
  } else if (root == MPI_ROOT) {
    bytes = 0;
  } else if (sendbuf == MPI_IN_PLACE) {
    BYTECOUNTND(recvtype, recvcounts[root]);
  } else {
    BYTECOUNTND(sendtype, sendcount);
  }

  AP_MPI_logCall(GATHERV_ID, TB1, TB2, NOSRC, root, bytes, comm); 

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Scatter                               */
/*   send values ignored except at root                     */
/*   all args significant at root                           */
/*   at root recvbuf may be MPI_IN_PLACE                    */
/*   recvcount and recvtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sig.   */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
int MPI_Scatter(APMPICONST void * sendbuf, int sendcount, MPI_Datatype sendtype, void * recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
  TIME(PMPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm));

  ap_bytes_t bytes;
  if (root == MPI_PROC_NULL) {
    bytes = 0;
  } else if (root == MPI_ROOT) {
    BYTECOUNTND(recvtype, recvcount);
  } else if (recvbuf == MPI_IN_PLACE) {
    BYTECOUNTND(sendtype, sendcount);
  } else {
    BYTECOUNTND(recvtype, recvcount);
  }

  AP_MPI_logCall(SCATTER_ID, TB1, TB2, root, NODEST, bytes, comm); 

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Scatterv                              */
/*   send values ignored except at root                     */
/*   all args significant at root                           */
/*   at root recvbuf may be MPI_IN_PLACE                    */
/*   recvcount and recvtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sig.   */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
int MPI_Scatterv(APMPICONST void * sendbuf, APMPICONST int * sendcounts, APMPICONST int * displs, MPI_Datatype sendtype, void * recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm)
{
  TIME(PMPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm));

  ap_bytes_t bytes;
  if (root == MPI_PROC_NULL) {
    bytes = 0;
  } else if (root == MPI_ROOT) {
    bytes = 0;
  } else if (recvbuf == MPI_IN_PLACE) {
    BYTECOUNTND(sendtype, sendcounts[root]);
  } else {
    BYTECOUNTND(recvtype, recvcount);
  }

  AP_MPI_logCall(SCATTERV_ID, TB1, TB2, root, NODEST, bytes, comm); 

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Scan                                  */
/*----------------------------------------------------------*/
int MPI_Scan(APMPICONST void * sendbuf, void * recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
  TIME(PMPI_Scan(sendbuf, recvbuf, count, datatype, op, comm));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(SCAN_ID, TB1, TB2, NOSRC, NODEST, bytes, comm); 
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Allgather                             */
/*   sendbuf may be MPI_IN_PLACE                            */
/*   sendcount and sendtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sig.   */
/*----------------------------------------------------------*/
int MPI_Allgather(APMPICONST void * sendbuf, int sendcount, MPI_Datatype sendtype, void * recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
  TIME(PMPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm));
  ap_bytes_t bytes;
  if (sendbuf != MPI_IN_PLACE) {
    BYTECOUNTND(sendtype, sendcount);
  } else {
    BYTECOUNTND(recvtype, recvcount);
  }
  AP_MPI_logCall(ALLGATHER_ID, TB1, TB2, NOSRC, NODEST, bytes, comm); 
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Allgatherv                            */
/*   sendbuf may be MPI_IN_PLACE                            */
/*   sendcount and sendtype are ignored for MPI_IN_PLACE    */
/*   recvcount/recvtype must be consistent with send sig.   */
/*----------------------------------------------------------*/
int MPI_Allgatherv(APMPICONST void * sendbuf, int sendcount, MPI_Datatype sendtype, void * recvbuf, APMPICONST int * recvcounts, APMPICONST int * displs, MPI_Datatype recvtype, MPI_Comm comm)
{
  TIME(PMPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm));
  ap_bytes_t bytes;
  if (sendbuf != MPI_IN_PLACE) {
    BYTECOUNTND(sendtype, sendcount);
  } else {
    int rank;
    PMPI_Comm_rank(comm, &rank);
    BYTECOUNTND(recvtype, recvcounts[rank]);
  }
  AP_MPI_logCall(ALLGATHERV_ID, TB1, TB2, NOSRC, NODEST, bytes, comm); 
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Reduce                                */
/*   at root sendbuf may be MPI_IN_PLACE                    */
/*   root may be MPI_ROOT and MPI_PROC_NULL for intercomms. */
/*----------------------------------------------------------*/
int MPI_Reduce(APMPICONST void * sendbuf, void * recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)
{
  TIME(PMPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm));

  ap_bytes_t bytes;
  if (root == MPI_PROC_NULL) {
    bytes = 0;
  } else {
    BYTECOUNTND(datatype, count);
  }

  AP_MPI_logCall(REDUCE_ID, TB1, TB2, NOSRC, root, bytes, comm); 

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Allreduce                             */
/*----------------------------------------------------------*/
int MPI_Allreduce(APMPICONST void * sendbuf, void * recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
  TIME(PMPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(ALLREDUCE_ID, TB1, TB2, NOSRC, NODEST, bytes, comm); 
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Reduce_scatter                        */
/*----------------------------------------------------------*/
int MPI_Reduce_scatter(APMPICONST void * sendbuf, void * recvbuf, APMPICONST int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
  TIME(PMPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm));

  int tsize;
  PMPI_Type_size(datatype, &tsize);

  int i, tasks, num = 0;
  PMPI_Comm_size(comm, &tasks);
  for (i=0; i<tasks; i++) num += recvcounts[i];
  ap_bytes_t bytes = num * tsize;

  AP_MPI_logCall(REDUCE_SCATTER_ID, TB1, TB2, NOSRC, NODEST, bytes, comm); 

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Alltoall                              */
/*   sendbuf may be MPI_IN_PLACE                            */
/*   sendcount and sendtype are ignored for MPI_IN_PLACE    */
/*   recvcount*recvtype must be consistent with send sig.   */
/*     for intercommunicators                               */
/*----------------------------------------------------------*/
int MPI_Alltoall(APMPICONST void * sendbuf, int sendcount, MPI_Datatype sendtype, void * recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
{
  TIME(PMPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm));
  BYTECOUNT(recvtype, recvcount);

  int tasks;
  PMPI_Comm_size(comm, &tasks);
  bytes = bytes*tasks;

  AP_MPI_logCall(ALLTOALL_ID, TB1, TB2, NOSRC, NODEST, bytes, comm); 

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Alltoallv                             */
/*   sendbuf may be MPI_IN_PLACE                            */
/*   sendcount,sendtype,sdispls are ignored for MPI_IN_PLACE*/
/*   recvcount*recvtype must be consistent with send sig.   */
/*     for intercommunicators                               */
/*----------------------------------------------------------*/
int MPI_Alltoallv(APMPICONST void * sendbuf, APMPICONST int * sendcounts, APMPICONST int * sdispls, MPI_Datatype sendtype, void * recvbuf, APMPICONST int * recvcounts, APMPICONST int * rdispls, MPI_Datatype recvtype, MPI_Comm comm)
{
  TIME(PMPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm));

  int tsize;
  PMPI_Type_size(recvtype, &tsize);

  int i, tasks, count = 0;
  PMPI_Comm_size(comm, &tasks);
  for (i=0; i<tasks; i++) count += recvcounts[i];

  ap_bytes_t bytes = (ap_bytes_t) (count * tsize);

  AP_MPI_logCall(ALLTOALLV_ID, TB1, TB2, NOSRC, NODEST, bytes, comm); 

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Alltoallw                             */
/*   sendbuf may be MPI_IN_PLACE                            */
/*   sendcount,sendtype,sdispls are ignored for MPI_IN_PLACE*/
/*   recvcount*recvtype must be consistent with send sig.   */
/*     for intercommunicators                               */
/*----------------------------------------------------------*/
int MPI_Alltoallw(APMPICONST void * sendbuf, APMPICONST int sendcounts[], APMPICONST int sdispls[], APMPICONST MPI_Datatype  sendtypes[], void * recvbuf, APMPICONST int recvcounts[], APMPICONST int rdispls[], APMPICONST MPI_Datatype recvtypes[], MPI_Comm comm)
{
  TIME(PMPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm));

  ap_bytes_t bytes = 0;
  int i, tasks, tsize;
  PMPI_Comm_size(comm, &tasks);
  for (i=0; i<tasks; i++) {
    PMPI_Type_size(recvtypes[i], &tsize);
    bytes += recvcounts[i]*tsize;
  }

  AP_MPI_logCall(ALLTOALLW_ID, TB1, TB2, NOSRC, NODEST, bytes, comm);

  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Exscan                                */
/*----------------------------------------------------------*/
int MPI_Exscan(APMPICONST void * sendbuf, void * recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
{
  TIME(PMPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(EXSCAN_ID, TB1, TB2, NOSRC, NODEST, bytes, comm); 
  return rc;
}

/* Enable or disable the wrappers for MPI-IO */
#ifdef AP_MPIO_WRAPPERS_ENABLE

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_close                            */
/*----------------------------------------------------------*/
int MPI_File_close(MPI_File * fh)
{
  TIME(PMPI_File_close(fh));
  AP_MPI_logCall(FILE_CLOSE_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_delete                           */
/*----------------------------------------------------------*/
int MPI_File_delete(APMPICONST char * filename, MPI_Info info)
{
  TIME(PMPI_File_delete(filename, info));
  AP_MPI_logCall(FILE_DELETE_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_iread                            */
/*----------------------------------------------------------*/
int MPI_File_iread(MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Request * request)
{
  TIME(PMPI_File_iread(fh, buf, count, datatype, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_IREAD_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_iread_at                         */
/*----------------------------------------------------------*/
int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void * buf, int count, MPI_Datatype datatype, MPI_Request * request)
{
  TIME(PMPI_File_iread_at(fh, offset, buf, count, datatype, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_IREAD_AT_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_iread_shared                     */
/*----------------------------------------------------------*/
int MPI_File_iread_shared(MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Request * request)
{
  TIME(PMPI_File_iread_shared(fh, buf, count, datatype, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_IREAD_SHARED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_iwrite                           */
/*----------------------------------------------------------*/
int MPI_File_iwrite(MPI_File fh, APMPICONST void * buf, int count, MPI_Datatype datatype, MPI_Request * request)
{
  TIME(PMPI_File_iwrite(fh, buf, count, datatype, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_IWRITE_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_iwrite_at                        */
/*----------------------------------------------------------*/
int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, APMPICONST void * buf, int count, MPI_Datatype datatype, MPI_Request * request)
{
  TIME(PMPI_File_iwrite_at(fh, offset, buf, count, datatype, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_IWRITE_AT_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_iwrite_shared                    */
/*----------------------------------------------------------*/
int MPI_File_iwrite_shared(MPI_File fh, APMPICONST void * buf, int count, MPI_Datatype datatype, MPI_Request * request)
{
  TIME(PMPI_File_iwrite_shared(fh, buf, count, datatype, request));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_IWRITE_SHARED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_open                             */
/*----------------------------------------------------------*/
int MPI_File_open(MPI_Comm comm, APMPICONST char * filename, int amode, MPI_Info info, MPI_File * fh)
{
  TIME(PMPI_File_open(comm, filename, amode, info, fh));
  AP_MPI_logCall(FILE_OPEN_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, comm);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_preallocate                      */
/*----------------------------------------------------------*/
int MPI_File_preallocate(MPI_File fh, MPI_Offset size)
{
  TIME(PMPI_File_preallocate(fh, size));
  AP_MPI_logCall(FILE_PREALLOCATE_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read                             */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */  
/*----------------------------------------------------------*/
int MPI_File_read(MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_read(fh, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_READ_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_all                         */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */  
/*----------------------------------------------------------*/
int MPI_File_read_all(MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_read_all(fh, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_READ_ALL_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_all_begin                   */
/*----------------------------------------------------------*/
int MPI_File_read_all_begin(MPI_File fh, void * buf, int count, MPI_Datatype datatype)
{
  TIME(PMPI_File_read_all_begin(fh, buf, count, datatype));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_READ_ALL_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_all_end                     */
/*----------------------------------------------------------*/
int MPI_File_read_all_end(MPI_File fh, void * buf, MPI_Status * status)
{
  TIME(PMPI_File_read_all_end(fh, buf, status));
  AP_MPI_logCall(FILE_READ_ALL_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_at                          */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */  
/*----------------------------------------------------------*/
int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_read_at(fh, offset, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_READ_AT_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_at_all                      */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */  
/*----------------------------------------------------------*/
int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_read_at_all(fh, offset, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_READ_AT_ALL_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_at_all_begin                */
/*----------------------------------------------------------*/
int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void * buf, int count, MPI_Datatype datatype)
{
  TIME(PMPI_File_read_at_all_begin(fh, offset, buf, count, datatype));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_READ_AT_ALL_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_at_all_end                  */
/*----------------------------------------------------------*/
int MPI_File_read_at_all_end(MPI_File fh, void * buf, MPI_Status * status)
{
  TIME(PMPI_File_read_at_all_end(fh, buf, status));
  AP_MPI_logCall(FILE_READ_AT_ALL_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_ordered                     */
/*----------------------------------------------------------*/
int MPI_File_read_ordered(MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_read_ordered(fh, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_READ_ORDERED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_ordered_begin               */
/*----------------------------------------------------------*/
int MPI_File_read_ordered_begin(MPI_File fh, void * buf, int count, MPI_Datatype datatype)
{
  TIME(PMPI_File_read_ordered_begin(fh, buf, count, datatype));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_READ_ORDERED_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_ordered_end                 */
/*----------------------------------------------------------*/
int MPI_File_read_ordered_end(MPI_File fh, void * buf, MPI_Status * status)
{
  TIME(PMPI_File_read_ordered_end(fh, buf, status));
  AP_MPI_logCall(FILE_READ_ORDERED_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_read_shared                      */
/*----------------------------------------------------------*/
int MPI_File_read_shared(MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_read_shared(fh, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_READ_SHARED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_seek                             */
/*----------------------------------------------------------*/
int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence)
{
  TIME(PMPI_File_seek(fh, offset, whence));
  AP_MPI_logCall(FILE_SEEK_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_seek_shared                      */
/*----------------------------------------------------------*/
int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence)
{
  TIME(PMPI_File_seek_shared(fh, offset, whence));
  AP_MPI_logCall(FILE_SEEK_SHARED_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_set_view                         */
/*----------------------------------------------------------*/
int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, APMPICONST char * datarep, MPI_Info info)
{
  TIME(PMPI_File_set_view(fh, disp, etype, filetype, datarep, info));
  AP_MPI_logCall(FILE_SET_VIEW_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_sync                             */
/*----------------------------------------------------------*/
int MPI_File_sync(MPI_File fh)
{
  TIME(PMPI_File_sync(fh));
  AP_MPI_logCall(FILE_SYNC_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write                            */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */  
/*----------------------------------------------------------*/
int MPI_File_write(MPI_File fh, APMPICONST void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_write(fh, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_WRITE_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_all                        */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */  
/*----------------------------------------------------------*/
int MPI_File_write_all(MPI_File fh, APMPICONST void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_write_all(fh, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_WRITE_ALL_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_all_begin                  */
/*----------------------------------------------------------*/
int MPI_File_write_all_begin(MPI_File fh, APMPICONST void * buf, int count, MPI_Datatype datatype)
{
  TIME(PMPI_File_write_all_begin(fh, buf, count, datatype));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_WRITE_ALL_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_all_end                    */
/*----------------------------------------------------------*/
int MPI_File_write_all_end(MPI_File fh, APMPICONST void * buf, MPI_Status * status)
{
  TIME(PMPI_File_write_all_end(fh, buf, status));
  AP_MPI_logCall(FILE_WRITE_ALL_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_at                         */
/*----------------------------------------------------------*/
int MPI_File_write_at(MPI_File fh, MPI_Offset offset, APMPICONST void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_write_at(fh, offset, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_WRITE_AT_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_at_all                     */
/* status arg may be MPI_STATUS_IGNORE, if so no status     */  
/*----------------------------------------------------------*/
int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, APMPICONST void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_write_at_all(fh, offset, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_WRITE_AT_ALL_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_at_all_begin               */
/*----------------------------------------------------------*/
int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, APMPICONST void * buf, int count, MPI_Datatype datatype)
{
  TIME(PMPI_File_write_at_all_begin(fh, offset, buf, count, datatype));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_WRITE_AT_ALL_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_at_all_end                 */
/*----------------------------------------------------------*/
int MPI_File_write_at_all_end(MPI_File fh, APMPICONST void * buf, MPI_Status * status)
{
  TIME(PMPI_File_write_at_all_end(fh, buf, status));
  AP_MPI_logCall(FILE_WRITE_AT_ALL_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_ordered                    */
/*----------------------------------------------------------*/
int MPI_File_write_ordered(MPI_File fh, APMPICONST void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_write_ordered(fh, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_WRITE_ORDERED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_ordered_begin              */
/*----------------------------------------------------------*/
int MPI_File_write_ordered_begin(MPI_File fh, APMPICONST void * buf, int count, MPI_Datatype datatype)
{
  TIME(PMPI_File_write_ordered_begin(fh, buf, count, datatype));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_WRITE_ORDERED_BEGIN_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_ordered_end                */
/*----------------------------------------------------------*/
int MPI_File_write_ordered_end(MPI_File fh, APMPICONST void * buf, MPI_Status * status)
{
  TIME(PMPI_File_write_ordered_end(fh, buf, status));
  AP_MPI_logCall(FILE_WRITE_ORDERED_END_ID, TB1, TB2, NOSRC, NODEST, NOBYTES, MPI_COMM_NULL);
  return rc;
}

/*----------------------------------------------------------*/
/* wrapper for C: MPI_File_write_shared                     */
/*----------------------------------------------------------*/
int MPI_File_write_shared(MPI_File fh, APMPICONST void * buf, int count, MPI_Datatype datatype, MPI_Status * status)
{
  TIME(PMPI_File_write_shared(fh, buf, count, datatype, status));
  BYTECOUNT(datatype, count);
  AP_MPI_logCall(FILE_WRITE_SHARED_ID, TB1, TB2, NOSRC, NODEST, bytes, MPI_COMM_NULL);
  return rc;
}

/*end of if AP_MPIO_WRAPPERS == DISABLED  */
#endif

/*----------------------------------------------------------*/
/* wrapper for C: MPI_Finalize                              */
/*----------------------------------------------------------*/
int MPI_Finalize(void)
{

  AP_Finalize();

  int rc = PMPI_Finalize();

  return rc;
}
