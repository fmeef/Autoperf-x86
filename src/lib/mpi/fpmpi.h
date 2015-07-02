#ifndef FPMPI_H
#define FPMPI_H


#include "mpi.h"

/*==========================================================*/
/* define how fortran strings are passed                    */
/*==========================================================*/

#define AP_FORT_LEN_TYPE  MPI_Fint *     // Set the type for the Fortran hidden character length argument
#define AP_FORT_CHAR_ARG_CASE  2         // 1- mixed, 2-end, 3-other, location of hidden length argument

#if AP_FORT_CHAR_ARG_CASE == 1 
#define AP_FORT_MIXED_LEN(a) , AP_FORT_LEN_TYPE a
#define AP_FORT_END_LEN(a)
#define AP_FORT_MIXED_LEN_ARG(a) , a
#define AP_FORT_END_LEN_ARG(a)
#elif  AP_FORT_CHAR_ARG_CASE == 2 
#define AP_FORT_MIXED_LEN(a)
#define AP_FORT_END_LEN(a)   , AP_FORT_LEN_TYPE a
#define AP_FORT_MIXED_LEN_ARG(a)
#define AP_FORT_END_LEN_ARG(a) , a
#else
#define AP_FORT_MIXED_LEN(a)
#define AP_FORT_END_LEN(a)
#define AP_FORT_MIXED_LEN_ARG(a)
#define AP_FORT_END_LEN_ARG(a)
#endif


/*==========================================================*/
/* C prototypes for fortran mpi calls                       */
/*==========================================================*/

void pmpi_init ( MPI_Fint * );
void pmpi_init_thread ( MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_comm_size (MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_comm_rank ( MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_send ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_ssend ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_rsend ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_bsend ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_isend ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_issend ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_irsend ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_ibsend ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_send_init ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_ssend_init ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *);
void pmpi_rsend_init ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *);
void pmpi_bsend_init ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *);
void pmpi_recv_init ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_recv ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_irecv ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_sendrecv ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_sendrecv_replace ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_buffer_attach ( void*, MPI_Fint *, MPI_Fint * );
void pmpi_buffer_detach ( void*, MPI_Fint *, MPI_Fint * );
void pmpi_probe ( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_iprobe ( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_test ( MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_testany ( MPI_Fint *, MPI_Fint [], MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_testall ( MPI_Fint *, MPI_Fint [], MPI_Fint *, MPI_Fint [], MPI_Fint * );
void pmpi_testsome ( MPI_Fint *, MPI_Fint [], MPI_Fint *, MPI_Fint [], MPI_Fint [], MPI_Fint * );
void pmpi_wait ( MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_waitany ( MPI_Fint *, MPI_Fint [], MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_waitall ( MPI_Fint *, MPI_Fint [], MPI_Fint [], MPI_Fint * );
void pmpi_waitsome ( MPI_Fint *, MPI_Fint [], MPI_Fint *, MPI_Fint [], MPI_Fint [], MPI_Fint * );
void pmpi_start ( MPI_Fint *, MPI_Fint * );
void pmpi_startall ( MPI_Fint *, MPI_Fint [], MPI_Fint * );
void pmpi_bcast ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_barrier ( MPI_Fint *, MPI_Fint * );
void pmpi_gather ( void*, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_gatherv ( void*, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_scatter ( void*, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_scatterv ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_scan ( void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_allgather ( void*, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_allgatherv ( void*, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_reduce ( void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_allreduce ( void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_reduce_scatter ( void*, void*, MPI_Fint [], MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_alltoall ( void*, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_alltoallv ( void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_alltoallw ( void*, MPI_Fint [], MPI_Fint [], MPI_Fint [], void*, MPI_Fint [], MPI_Fint [], MPI_Fint [], MPI_Fint *, MPI_Fint * );
void pmpi_exscan ( void*, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_close ( MPI_Fint *, MPI_Fint * );
void pmpi_file_delete ( char * AP_FORT_MIXED_LEN(), MPI_Fint *, MPI_Fint * AP_FORT_END_LEN() );
void pmpi_file_iread ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_iread_at ( MPI_Fint *, MPI_Offset *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_iread_shared ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_iwrite ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_iwrite_at ( MPI_Fint *, MPI_Offset *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_iwrite_shared ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_open ( MPI_Fint *, char * AP_FORT_MIXED_LEN(), MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * AP_FORT_END_LEN() );
void pmpi_file_preallocate ( MPI_Fint *, MPI_Offset *, MPI_Fint * );
void pmpi_file_read ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_all ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_all_begin ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_all_end ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_at ( MPI_Fint *, MPI_Offset *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_at_all ( MPI_Fint *, MPI_Offset *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_at_all_begin ( MPI_Fint *, MPI_Offset *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_at_all_end ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_ordered ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_ordered_begin ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_ordered_end ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint * );
void pmpi_file_read_shared ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_seek ( MPI_Fint *, MPI_Offset *, MPI_Fint *, MPI_Fint * );
void pmpi_file_seek_shared ( MPI_Fint *, MPI_Offset *, MPI_Fint *, MPI_Fint * );
void pmpi_file_set_view ( MPI_Fint *, MPI_Offset *, MPI_Fint *, MPI_Fint *, char * AP_FORT_MIXED_LEN(), MPI_Fint *, MPI_Fint * AP_FORT_END_LEN() );
void pmpi_file_sync ( MPI_Fint *, MPI_Fint * );
void pmpi_file_write ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_all ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_all_begin ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_all_end ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_at ( MPI_Fint *, MPI_Offset *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_at_all ( MPI_Fint *, MPI_Offset *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_at_all_begin ( MPI_Fint *, MPI_Offset *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_at_all_end ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_ordered ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_ordered_begin ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_ordered_end ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint * );
void pmpi_file_write_shared ( MPI_Fint *, void*, MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint * );
void pmpi_finalize ( MPI_Fint * );

void pmpi_type_size(MPI_Fint *, MPI_Fint *, MPI_Fint *);
void pmpi_get_count(MPI_Fint *, MPI_Fint *, MPI_Fint *, MPI_Fint *);

#endif
