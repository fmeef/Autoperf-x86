make clean
make
mpicc test.c -I ~/Documents/argonne/scc15-spack/opt/unknown_arch/gcc@5.1.0/mpich@3.0.4/include -I  ~/Documents/argonne/scc15-spack/opt/unknown_arch/gcc@5.1.0/hwloc@1.9/include/ -L  ~/Documents/argonne/scc15-spack/opt/unknown_arch/gcc@5.1.0/hwloc@1.9/lib -L ~/Documents/argonne/autoperf-x86/trunk/build -I ~/Documents/argonne/autoperf-x86/trunk/src/lib -lpapi -L/home/gnu3ra/Documents/argonne/scc15-spack/opt/unknown_arch/gcc@5.1.0/papi@5.4.1/lib -I /home/gnu3ra/Documents/argonne/scc15-spack/opt/unknown_arch/gcc@5.1.0/papi@5.4.1/include -lautoperf -lhwloc -o perftest
