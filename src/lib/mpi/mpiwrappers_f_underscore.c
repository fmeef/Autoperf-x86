/*==========================================================*/
/*    Fortran-to-C interface with one underscore            */
/*==========================================================*/


/*--------------------------------------------------------------------*/
/* include mpi header before defining macros to avoid changing header */
/*--------------------------------------------------------------------*/

#include "mpi.h"

/*----------------------------------------------------------------------*/
/* define macros to create trailing underscore version of fortran funcs */
/*----------------------------------------------------------------------*/

#define mpi_init              mpi_init_
#define mpi_init_thread       mpi_init_thread_
#define mpi_comm_size         mpi_comm_size_
#define mpi_comm_rank         mpi_comm_rank_
#define mpi_send              mpi_send_
#define mpi_ssend             mpi_ssend_
#define mpi_rsend             mpi_rsend_
#define mpi_bsend             mpi_bsend_
#define mpi_isend             mpi_isend_
#define mpi_issend            mpi_issend_
#define mpi_irsend            mpi_irsend_
#define mpi_ibsend            mpi_ibsend_
#define mpi_send_init         mpi_send_init_
#define mpi_ssend_init        mpi_ssend_init_
#define mpi_rsend_init        mpi_rsend_init_
#define mpi_bsend_init        mpi_bsend_init_
#define mpi_recv_init         mpi_recv_init_
#define mpi_recv              mpi_recv_
#define mpi_irecv             mpi_irecv_
#define mpi_sendrecv          mpi_sendrecv_
#define mpi_sendrecv_replace  mpi_sendrecv_replace_
#define mpi_buffer_attach     mpi_buffer_attach_
#define mpi_buffer_detach     mpi_buffer_detach_
#define mpi_probe             mpi_probe_
#define mpi_iprobe            mpi_iprobe_
#define mpi_test              mpi_test_
#define mpi_testany           mpi_testany_
#define mpi_testall           mpi_testall_
#define mpi_testsome          mpi_testsome_
#define mpi_wait              mpi_wait_
#define mpi_waitany           mpi_waitany_
#define mpi_waitall           mpi_waitall_
#define mpi_waitsome          mpi_waitsome_
#define mpi_start             mpi_start_
#define mpi_startall          mpi_startall_
#define mpi_bcast             mpi_bcast_
#define mpi_barrier           mpi_barrier_
#define mpi_gather            mpi_gather_
#define mpi_gatherv           mpi_gatherv_
#define mpi_scatter           mpi_scatter_
#define mpi_scatterv          mpi_scatterv_
#define mpi_scan              mpi_scan_
#define mpi_allgather         mpi_allgather_
#define mpi_allgatherv        mpi_allgatherv_
#define mpi_reduce            mpi_reduce_
#define mpi_allreduce         mpi_allreduce_
#define mpi_reduce_scatter    mpi_reduce_scatter_
#define mpi_alltoall          mpi_alltoall_
#define mpi_alltoallv         mpi_alltoallv_
#define mpi_alltoallw         mpi_alltoallw_
#define mpi_exscan            mpi_exscan_

#define mpi_file_close                 mpi_file_close_
#define mpi_file_delete                mpi_file_delete_
#define mpi_file_iread                 mpi_file_iread_
#define mpi_file_iread_at              mpi_file_iread_at_
#define mpi_file_iread_shared          mpi_file_iread_shared_
#define mpi_file_iwrite                mpi_file_iwrite_
#define mpi_file_iwrite_at             mpi_file_iwrite_at_
#define mpi_file_iwrite_shared         mpi_file_iwrite_shared_
#define mpi_file_open                  mpi_file_open_
#define mpi_file_preallocate           mpi_file_preallocate_
#define mpi_file_read                  mpi_file_read_
#define mpi_file_read_all              mpi_file_read_all_
#define mpi_file_read_all_begin        mpi_file_read_all_begin_
#define mpi_file_read_all_end          mpi_file_read_all_end_
#define mpi_file_read_at               mpi_file_read_at_
#define mpi_file_read_at_all           mpi_file_read_at_all_
#define mpi_file_read_at_all_begin     mpi_file_read_at_all_begin_
#define mpi_file_read_at_all_end       mpi_file_read_at_all_end_
#define mpi_file_read_ordered          mpi_file_read_ordered_
#define mpi_file_read_ordered_begin    mpi_file_read_ordered_begin_
#define mpi_file_read_ordered_end      mpi_file_read_ordered_end_
#define mpi_file_read_shared           mpi_file_read_shared_
#define mpi_file_seek                  mpi_file_seek_
#define mpi_file_seek_shared           mpi_file_seek_shared_
#define mpi_file_set_view              mpi_file_set_view_
#define mpi_file_sync                  mpi_file_sync_
#define mpi_file_write                 mpi_file_write_
#define mpi_file_write_all             mpi_file_write_all_
#define mpi_file_write_all_begin       mpi_file_write_all_begin_
#define mpi_file_write_all_end         mpi_file_write_all_end_
#define mpi_file_write_at              mpi_file_write_at_
#define mpi_file_write_at_all          mpi_file_write_at_all_
#define mpi_file_write_at_all_begin    mpi_file_write_at_all_begin_
#define mpi_file_write_at_all_end      mpi_file_write_at_all_end_
#define mpi_file_write_ordered         mpi_file_write_ordered_
#define mpi_file_write_ordered_begin   mpi_file_write_ordered_begin_
#define mpi_file_write_ordered_end     mpi_file_write_ordered_end_
#define mpi_file_write_shared          mpi_file_write_shared_

#define mpi_finalize          mpi_finalize_

/*--------------------------------*/
/* include fortran-to-c interface */
/*--------------------------------*/

#include "mpiwrappers_f.c"
