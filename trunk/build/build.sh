make clean
make
mpicc test.c -L ~/Documents/argonne/autoperf-x86/trunk/build -I ~/Documents/argonne/autoperf-x86/trunk/src/lib -lpapi -L/home/gnu3ra/Documents/argonne/scc15-spack/opt/unknown_arch/gcc@5.1.0/papi@5.4.1/lib -I /home/gnu3ra/Documents/argonne/scc15-spack/opt/unknown_arch/gcc@5.1.0/papi@5.4.1/include -lautoperf -lhwloc -o perftest
