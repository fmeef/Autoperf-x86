make clean
make
SPACKDIR=/home/aballmer
mpicc test.c -O0 -I $SPACKDIR/scc15-spack/opt/unknown_arch/gcc@5.1.0/mpich@3.0.4/include -I  $SPACKDIR/scc15-spack/opt/unknown_arch/gcc@5.1.0/hwloc@1.9.1/include/ -L  $SPACKDIR/scc15-spack/opt/unknown_arch/gcc@5.1.0/hwloc@1.9.1/lib -L $SPACKDIR/autoperf-x86/trunk/build -I $SPACKDIR/autoperf-x86/trunk/src/lib -lpapi -L$SPACKDIR/opt/unknown_arch/gcc@5.1.0/papi@5.4.1/lib -I $SPACKDIR/scc15-spack/opt/unknown_arch/gcc@5.1.0/papi@5.4.1/include -lautoperf -lhwloc -luuid -o perftest
