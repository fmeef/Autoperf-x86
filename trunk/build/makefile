LIBSRC = ../src/lib
CC = gcc
BGSYS = /bgsys/drivers/ppcfloor
INC =  -I /home/gnu3ra/Documents/argonne/scc15-spack/opt/unknown_arch/gcc@5.1.0/papi@5.4.1/include -L /home/gnu3ra/Documents/argonne/scc15-spack/opt/unknown_arch/gcc@5.1.0/papi@5.4.1/lib -I$(LIBSRC) -I/home/aballmer/scc15-spack/opt/unknown_arch/gcc@4.4.7/mpich@3.0.4/include -I/home/aballmer/scc15-spack/opt/unknown_arch/gcc@4.4.7/hwloc@1.9/include/ 

CFLAGS = -g -O3 $(INC) -lhwloc

#------------------------------------------
# targets
#default: all
#all:	libautoperf.a
#------------------------------------------

libautoperf.a: autoperf.o ap_collect.o ap_collect_mpiproc.o ap_hpm.o ap_proc.o ap_sys.o ap_mpi.o mpiwrappers_c.o mpiwrappers_f.o mpiwrappers_f_underscore.o util.o
	ar crv $@ $^
	chmod 644 libautoperf.a

clean ::
	rm -f *.a *.o

#------------------------------------------
# rules
#------------------------------------------

autoperf.o: $(LIBSRC)/autoperf.c $(LIBSRC)/hpm/ap_hpm.h $(LIBSRC)/mpi/ap_mpi.h $(LIBSRC)/proc/ap_proc.h $(LIBSRC)/ap_config.h
	$(CC) -c $(CFLAGS) $(LIBSRC)/autoperf.c

ap_collect.o: $(LIBSRC)/coll/ap_collect.c
	$(CC) -c $(CFLAGS) $(LIBSRC)/coll/ap_collect.c

ap_collect_mpiproc.o: $(LIBSRC)/coll/ap_collect_mpiproc.c $(LIBSRC)/hpm/ap_hpm.h $(LIBSRC)/mpi/ap_mpi.h $(LIBSRC)/proc/ap_proc.h $(LIBSRC)/sys/ap_sys.h $(LIBSRC)/autoperf.h $(LIBSRC)/coll/util.h
	$(CC) -c $(CFLAGS) $(LIBSRC)/coll/ap_collect_mpiproc.c

util.o: $(LIBSRC)/coll/util.c
	$(CC) -c $(CFLAGS) $(LIBSRC)/coll/util.c

ap_hpm.o: $(LIBSRC)/hpm/ap_hpm.c $(LIBSRC)/ap_config.h $(LIBSRC)/hpm/ap_hpm.h $(LIBSRC)/ap_config.h
	$(CC) -c $(CFLAGS) $(LIBSRC)/hpm/ap_hpm.c

ap_proc.o: $(LIBSRC)/proc/ap_proc.c $(LIBSRC)/proc/ap_proc.h $(LIBSRC)/time/ap_time.h 
	$(CC) -c $(CFLAGS) $(LIBSRC)/proc/ap_proc.c

ap_sys.o: $(LIBSRC)/sys/ap_sys.c $(LIBSRC)/sys/ap_sys.h $(LIBSRC)/ap_config.h
	$(CC) -c $(CFLAGS) $(LIBSRC)/sys/ap_sys.c

ap_mpi.o: $(LIBSRC)/mpi/ap_mpi.c $(LIBSRC)/mpi/ap_mpi.h $(LIBSRC)/ap_config.h
	$(CC) -c $(CFLAGS) $(LIBSRC)/mpi/ap_mpi.c

mpiwrappers_c.o: $(LIBSRC)/mpi/mpiwrappers_c.c $(LIBSRC)/autoperf.h $(LIBSRC)/mpi/ap_mpi.h $(LIBSRC)/ap_config.h
	$(CC) -c $(CFLAGS) $(LIBSRC)/mpi/mpiwrappers_c.c

mpiwrappers_f.o: $(LIBSRC)/mpi/mpiwrappers_f.c $(LIBSRC)/autoperf.h $(LIBSRC)/mpi/ap_mpi.h $(LIBSRC)/mpi/fpmpi.h $(LIBSRC)/ap_config.h
	$(CC) -c $(CFLAGS) $(LIBSRC)/mpi/mpiwrappers_f.c

mpiwrappers_f_underscore.o: $(LIBSRC)/mpi/mpiwrappers_f_underscore.c $(LIBSRC)/autoperf.h $(LIBSRC)/mpi/ap_mpi.h $(LIBSRC)/mpi/fpmpi.h $(LIBSRC)/ap_config.h
	$(CC) -c $(CFLAGS) $(LIBSRC)/mpi/mpiwrappers_f_underscore.c

