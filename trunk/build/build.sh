make clean
make
SPACKDIR=/home/gnu3ra/Documents/argonne/scc15-spack
GCC=$(gcc --version | grep ^gcc | sed 's/^.* //g')
mpicc test.c -O0 -I $SPACKDIR/opt/unknown_arch/gcc@$GCC/mpich@3.0.4/include -I  $SPACKDIR/opt/unknown_arch/gcc@$GCC/hwloc@1.9.1/include/ -L  $SPACKDIR/opt/unknown_arch/gcc@$GCC/hwloc@1.9.1/lib -L ../build -I ../src/lib -lpapi -L$SPACKDIR/opt/unknown_arch/gcc@$GCC/papi@5.4.1/lib -I $SPACKDIR/opt/unknown_arch/gcc@5.1.0/papi@5.4.1/include -lautoperf -lhwloc -luuid -o perftest
