#!/bin/bash

grep "mpi_init " tmp1.txt  > tmp4.txt
grep "mpi_init_thread " tmp1.txt | \
 sed s/v1/required/ | \
 sed s/v2/provided/ >> tmp4.txt
grep "mpi_comm_size " tmp1.txt | \
 sed s/v1/comm/ | \
 sed s/v2/size/ >> tmp4.txt
grep "mpi_comm_rank " tmp1.txt | \
 sed s/v1/comm/ | \
 sed s/v2/rank/ >> tmp4.txt
grep "mpi_send " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ >> tmp4.txt
grep "mpi_ssend " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ >> tmp4.txt
grep "mpi_rsend " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ >> tmp4.txt
grep "mpi_bsend " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ >> tmp4.txt
grep "mpi_isend " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/request/ >> tmp4.txt
grep "mpi_issend " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/request/ >> tmp4.txt
grep "mpi_irsend " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/request/ >> tmp4.txt
grep "mpi_ibsend " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/request/ >> tmp4.txt
grep "mpi_send_init " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/request/ >> tmp4.txt
grep "mpi_ssend_init " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/request/ >> tmp4.txt
grep "mpi_rsend_init " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/request/ >> tmp4.txt
grep "mpi_bsend_init " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/request/ >> tmp4.txt
grep "mpi_recv_init " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/source/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/request/ >> tmp4.txt
grep "mpi_recv " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/source/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/status/ >> tmp4.txt
grep "mpi_irecv " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/source/ | \
 sed s/v5/tag/ | \
 sed s/v6/comm/ | \
 sed s/v7/request/ >> tmp4.txt
grep "mpi_sendrecv " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/sendcount/ | \
 sed s/v3/sendtype/ | \
 sed s/v4/dest/ | \
 sed s/v5/sendtag/ | \
 sed s/v6/recvbuf/ | \
 sed s/v7/recvcount/ | \
 sed s/v8/recvtype/ | \
 sed s/v9/source/ | \
 sed s/v10/recvtag/ | \
 sed s/v11/comm/ | \
 sed s/v12/status/ >> tmp4.txt
grep "mpi_sendrecv_replace " tmp1.txt | \
 sed s/v1/buf/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/dest/ | \
 sed s/v5/sendtag/ | \
 sed s/v6/source/ | \
 sed s/v7/recvtag/ | \
 sed s/v8/comm/ | \
 sed s/v9/status/ >> tmp4.txt
grep "mpi_buffer_attach " tmp1.txt | \
 sed s/v1/buffer/ | \
 sed s/v2/size/ >> tmp4.txt
grep "mpi_buffer_detach " tmp1.txt | \
 sed s/v1/buffer_addr/ | \
 sed s/v2/size/ >> tmp4.txt
grep "mpi_probe " tmp1.txt | \
 sed s/v1/source/ | \
 sed s/v2/tag/ | \
 sed s/v3/comm/ | \
 sed s/v4/status/ >> tmp4.txt
grep "mpi_iprobe " tmp1.txt | \
 sed s/v1/source/ | \
 sed s/v2/tag/ | \
 sed s/v3/comm/ | \
 sed s/v4/flag/ | \
 sed s/v5/status/ >> tmp4.txt
grep "mpi_test " tmp1.txt | \
 sed s/v1/request/ | \
 sed s/v2/flag/ | \
 sed s/v3/status/ >> tmp4.txt
grep "mpi_testany " tmp1.txt | \
 sed s/v1/count/ | \
 sed s/v2/array_of_requests/ | \
 sed s/v3/indx/ | \
 sed s/v4/flag/ | \
 sed s/v5/status/ >> tmp4.txt
grep "mpi_testall " tmp1.txt | \
 sed s/v1/count/ | \
 sed s/v2/array_of_requests/ | \
 sed s/v3/flag/ | \
 sed s/v4/array_of_statuses/ >> tmp4.txt
grep "mpi_testsome " tmp1.txt | \
 sed s/v1/incount/ | \
 sed s/v2/array_of_requests/ | \
 sed s/v3/outcount/ | \
 sed s/v4/array_of_indices/ | \
 sed s/v5/array_of_statuses/ >> tmp4.txt
grep "mpi_wait " tmp1.txt | \
 sed s/v1/request/ | \
 sed s/v2/status/ >> tmp4.txt
grep "mpi_waitany " tmp1.txt | \
 sed s/v1/count/ | \
 sed s/v2/array_of_requests/ | \
 sed s/v3/indx/ | \
 sed s/v4/status/ >> tmp4.txt
grep "mpi_waitall " tmp1.txt | \
 sed s/v1/count/ | \
 sed s/v2/array_of_requests/ | \
 sed s/v3/array_of_statuses/ >> tmp4.txt
grep "mpi_waitsome " tmp1.txt | \
 sed s/v1/incount/ | \
 sed s/v2/array_of_requests/ | \
 sed s/v3/outcount/ | \
 sed s/v4/array_of_indices/ | \
 sed s/v5/array_of_statuses/ >> tmp4.txt
grep "mpi_start " tmp1.txt | \
 sed s/v1/request/ >> tmp4.txt
grep "mpi_startall " tmp1.txt | \
 sed s/v1/count/ | \
 sed s/v2/array_of_requests/ >> tmp4.txt
grep "mpi_bcast " tmp1.txt | \
 sed s/v1/buffer/ | \
 sed s/v2/count/ | \
 sed s/v3/datatype/ | \
 sed s/v4/root/ | \
 sed s/v5/comm/ >> tmp4.txt
grep "mpi_barrier " tmp1.txt | \
 sed s/v1/comm/ >> tmp4.txt
grep "mpi_gather " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/sendcount/ | \
 sed s/v3/sendtype/ | \
 sed s/v4/recvbuf/ | \
 sed s/v5/recvcount/ | \
 sed s/v6/recvtype/ | \
 sed s/v7/root/ | \
 sed s/v8/comm/ >> tmp4.txt
grep "mpi_gatherv " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/sendcount/ | \
 sed s/v3/sendtype/ | \
 sed s/v4/recvbuf/ | \
 sed s/v5/recvcounts/ | \
 sed s/v6/displs/ | \
 sed s/v7/recvtype/ | \
 sed s/v8/root/ | \
 sed s/v9/comm/ >> tmp4.txt
grep "mpi_scatter " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/sendcount/ | \
 sed s/v3/sendtype/ | \
 sed s/v4/recvbuf/ | \
 sed s/v5/recvcount/ | \
 sed s/v6/recvtype/ | \
 sed s/v7/root/ | \
 sed s/v8/comm/ >> tmp4.txt
grep "mpi_scatterv " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/sendcounts/ | \
 sed s/v3/displs/ | \
 sed s/v4/sendtype/ | \
 sed s/v5/recvbuf/ | \
 sed s/v6/recvcount/ | \
 sed s/v7/recvtype/ | \
 sed s/v8/root/ | \
 sed s/v9/comm/ >> tmp4.txt
grep "mpi_scan " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/recvbuf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/op/ | \
 sed s/v6/comm/ >> tmp4.txt
grep "mpi_allgather " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/sendcount/ | \
 sed s/v3/sendtype/ | \
 sed s/v4/recvbuf/ | \
 sed s/v5/recvcount/ | \
 sed s/v6/recvtype/ | \
 sed s/v7/comm/ >> tmp4.txt
grep "mpi_allgatherv " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/sendcount/ | \
 sed s/v3/sendtype/ | \
 sed s/v4/recvbuf/ | \
 sed s/v5/recvcounts/ | \
 sed s/v6/displs/ | \
 sed s/v7/recvtype/ | \
 sed s/v8/comm/ >> tmp4.txt
grep "mpi_reduce " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/recvbuf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/op/ | \
 sed s/v6/root/ | \
 sed s/v7/comm/ >> tmp4.txt
grep "mpi_allreduce " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/recvbuf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/op/ | \
 sed s/v6/comm/ >> tmp4.txt
grep "mpi_reduce_scatter " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/recvbuf/ | \
 sed s/v3/recvcounts/ | \
 sed s/v4/datatype/ | \
 sed s/v5/op/ | \
 sed s/v6/comm/ >> tmp4.txt
grep "mpi_alltoall " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/sendcount/ | \
 sed s/v3/sendtype/ | \
 sed s/v4/recvbuf/ | \
 sed s/v5/recvcount/ | \
 sed s/v6/recvtype/ | \
 sed s/v7/comm/ >> tmp4.txt
grep "mpi_alltoallv " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/sendcounts/ | \
 sed s/v3/sdispls/ | \
 sed s/v4/sendtype/ | \
 sed s/v5/recvbuf/ | \
 sed s/v6/recvcounts/ | \
 sed s/v7/rdispls/ | \
 sed s/v8/recvtype/ | \
 sed s/v9/comm/ >> tmp4.txt
grep "mpi_alltoallw " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/sendcounts/ | \
 sed s/v3/sdispls/ | \
 sed s/v4/sendtypes/ | \
 sed s/v5/recvbuf/ | \
 sed s/v6/recvcounts/ | \
 sed s/v7/rdispls/ | \
 sed s/v8/recvtypes/ | \
 sed s/v9/comm/ >> tmp4.txt
grep "mpi_exscan " tmp1.txt | \
 sed s/v1/sendbuf/ | \
 sed s/v2/recvbuf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/op/ | \
 sed s/v6/comm/ >> tmp4.txt
grep "mpi_file_close " tmp1.txt | \
 sed s/v1/fh/ >> tmp4.txt
grep "mpi_file_delete " tmp1.txt | \
 sed s/v1/filename/ | \
 sed s/v2/info/ >> tmp4.txt
grep "mpi_file_iread " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/request/ >> tmp4.txt
grep "mpi_file_iread_at " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/offset/ | \
 sed s/v3/buf/ | \
 sed s/v4/count/ | \
 sed s/v5/datatype/ | \
 sed s/v6/request/ >> tmp4.txt
grep "mpi_file_iread_shared " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/request/ >> tmp4.txt
grep "mpi_file_iwrite " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/request/ >> tmp4.txt
grep "mpi_file_iwrite_at " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/offset/ | \
 sed s/v3/buf/ | \
 sed s/v4/count/ | \
 sed s/v5/datatype/ | \
 sed s/v6/request/ >> tmp4.txt
grep "mpi_file_iwrite_shared " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/request/ >> tmp4.txt
grep "mpi_file_open " tmp1.txt | \
 sed s/v1/comm/ | \
 sed s/v2/filename/ | \
 sed s/v3/amode/ | \
 sed s/v4/info/ | \
 sed s/v5/fh/ >> tmp4.txt
grep "mpi_file_preallocate " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/size/ >> tmp4.txt
grep "mpi_file_read " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/status/ >> tmp4.txt
grep "mpi_file_read_all " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/status/ >> tmp4.txt
grep "mpi_file_read_all_begin " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ >> tmp4.txt
grep "mpi_file_read_all_end " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/status/ >> tmp4.txt
grep "mpi_file_read_at " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/offset/ | \
 sed s/v3/buf/ | \
 sed s/v4/count/ | \
 sed s/v5/datatype/ | \
 sed s/v6/status/ >> tmp4.txt
grep "mpi_file_read_at_all " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/offset/ | \
 sed s/v3/buf/ | \
 sed s/v4/count/ | \
 sed s/v5/datatype/ | \
 sed s/v6/status/ >> tmp4.txt
grep "mpi_file_read_at_all_begin " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/offset/ | \
 sed s/v3/buf/ | \
 sed s/v4/count/ | \
 sed s/v5/datatype/ >> tmp4.txt
grep "mpi_file_read_at_all_end " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/status/ >> tmp4.txt
grep "mpi_file_read_ordered " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/status/ >> tmp4.txt
grep "mpi_file_read_ordered_begin " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ >> tmp4.txt
grep "mpi_file_read_ordered_end " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/status/ >> tmp4.txt
grep "mpi_file_read_shared " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/status/ >> tmp4.txt
grep "mpi_file_seek " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/offset/ | \
 sed s/v3/whence/ >> tmp4.txt
grep "mpi_file_seek_shared " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/offset/ | \
 sed s/v3/whence/ >> tmp4.txt
grep "mpi_file_set_view " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/disp/ | \
 sed s/v3/etype/ | \
 sed s/v4/filetype/ | \
 sed s/v5/datarep/ | \
 sed s/v6/info/ >> tmp4.txt
grep "mpi_file_sync " tmp1.txt | \
 sed s/v1/fh/ >> tmp4.txt
grep "mpi_file_write " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/status/ >> tmp4.txt
grep "mpi_file_write_all " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/status/ >> tmp4.txt
grep "mpi_file_write_all_begin " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ >> tmp4.txt
grep "mpi_file_write_all_end " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/status/ >> tmp4.txt
grep "mpi_file_write_at " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/offset/ | \
 sed s/v3/buf/ | \
 sed s/v4/count/ | \
 sed s/v5/datatype/ | \
 sed s/v6/status/ >> tmp4.txt
grep "mpi_file_write_at_all " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/offset/ | \
 sed s/v3/buf/ | \
 sed s/v4/count/ | \
 sed s/v5/datatype/ | \
 sed s/v6/status/ >> tmp4.txt
grep "mpi_file_write_at_all_begin " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/offset/ | \
 sed s/v3/buf/ | \
 sed s/v4/count/ | \
 sed s/v5/datatype/ >> tmp4.txt
grep "mpi_file_write_at_all_end " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/status/ >> tmp4.txt
grep "mpi_file_write_ordered " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/status/ >> tmp4.txt
grep "mpi_file_write_ordered_begin " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ >> tmp4.txt
grep "mpi_file_write_ordered_end " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/status/ >> tmp4.txt
grep "mpi_file_write_shared " tmp1.txt | \
 sed s/v1/fh/ | \
 sed s/v2/buf/ | \
 sed s/v3/count/ | \
 sed s/v4/datatype/ | \
 sed s/v5/status/ >> tmp4.txt
grep "mpi_finalize " tmp1.txt >> tmp4.txt
