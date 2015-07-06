#!/bin/bash

rm -rf gcc 2> /dev/null
rm -rf gcc.legacy 2> /dev/null
rm -rf xl 2> /dev/null
rm -rf xl.legacy 2> /dev/null
rm -rf xl.ndebug 2> /dev/null
rm -rf xl.legacy.ndebug 2> /dev/null

mkdir gcc
mkdir gcc.legacy
mkdir xl
mkdir xl.legacy
mkdir xl.ndebug
mkdir xl.legacy.ndebug

./autoperf-gen-cxx.pl --trim --lib mpichcxx-gcc --output gcc/mpic++ /bgsys/drivers/ppcfloor/comm/gcc/bin/mpic++
./autoperf-gen-cxx.pl --trim --lib mpichcxx-gcc.legacy --output gcc.legacy/mpic++ /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpic++
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl --output xl/mpic++ /bgsys/drivers/ppcfloor/comm/xl/bin/mpic++
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.legacy --output xl.legacy/mpic++ /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpic++
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.legacy.ndebug --output xl.legacy.ndebug/mpic++ /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpic++
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.ndebug --output xl.ndebug/mpic++ /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpic++
./autoperf-gen-cxx.pl --trim --lib mpichcxx-gcc --output gcc/mpicxx /bgsys/drivers/ppcfloor/comm/gcc/bin/mpicxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-gcc --output gcc/mpixlcxx /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlcxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-gcc --output gcc/mpixlcxx_r /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlcxx_r
./autoperf-gen-cxx.pl --trim --lib mpichcxx-gcc.legacy --output gcc.legacy/mpicxx /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpicxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-gcc.legacy --output gcc.legacy/mpixlcxx /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlcxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-gcc.legacy --output gcc.legacy/mpixlcxx_r /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlcxx_r
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl --output xl/mpicxx /bgsys/drivers/ppcfloor/comm/xl/bin/mpicxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl --output xl/mpixlcxx /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlcxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl --output xl/mpixlcxx_r /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlcxx_r
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.legacy --output xl.legacy/mpicxx /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpicxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.legacy --output xl.legacy/mpixlcxx /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlcxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.legacy --output xl.legacy/mpixlcxx_r /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlcxx_r
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.legacy.ndebug --output xl.legacy.ndebug/mpicxx /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpicxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlcxx /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlcxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlcxx_r /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlcxx_r
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.ndebug --output xl.ndebug/mpicxx /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpicxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.ndebug --output xl.ndebug/mpixlcxx /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlcxx
./autoperf-gen-cxx.pl --trim --lib mpichcxx-xl.ndebug --output xl.ndebug/mpixlcxx_r /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlcxx_r

./autoperf-gen-fortran.pl --trim --lib mpichf77-gcc --output gcc/mpif77 /bgsys/drivers/ppcfloor/comm/gcc/bin/mpif77
./autoperf-gen-fortran.pl --trim --lib mpichf77-gcc --output gcc/mpixlf77 /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlf77
./autoperf-gen-fortran.pl --trim --lib mpichf77-gcc --output gcc/mpixlf77_r /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlf77_r
./autoperf-gen-fortran.pl --trim --lib mpichf77-gcc.legacy --output gcc.legacy/mpif77 /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpif77
./autoperf-gen-fortran.pl --trim --lib mpichf77-gcc.legacy --output gcc.legacy/mpixlf77 /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlf77
./autoperf-gen-fortran.pl --trim --lib mpichf77-gcc.legacy --output gcc.legacy/mpixlf77_r /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlf77_r
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl --output xl/mpif77 /bgsys/drivers/ppcfloor/comm/xl/bin/mpif77
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl --output xl/mpixlf77 /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlf77
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl --output xl/mpixlf77_r /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlf77_r
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl.legacy --output xl.legacy/mpif77 /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpif77
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl.legacy --output xl.legacy/mpixlf77 /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlf77
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl.legacy --output xl.legacy/mpixlf77_r /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlf77_r
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl.legacy.ndebug --output xl.legacy.ndebug/mpif77 /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpif77
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlf77 /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlf77
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlf77_r /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlf77_r
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl.ndebug --output xl.ndebug/mpif77 /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpif77
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl.ndebug --output xl.ndebug/mpixlf77 /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlf77
./autoperf-gen-fortran.pl --trim --lib mpichf77-xl.ndebug --output xl.ndebug/mpixlf77_r /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlf77_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc --output gcc/mpif90 /bgsys/drivers/ppcfloor/comm/gcc/bin/mpif90
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc --output gcc/mpixlf90 /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlf90
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc --output gcc/mpixlf90_r /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlf90_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc.legacy --output gcc.legacy/mpif90 /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpif90
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc.legacy --output gcc.legacy/mpixlf90 /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlf90
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc.legacy --output gcc.legacy/mpixlf90_r /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlf90_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl --output xl/mpif90 /bgsys/drivers/ppcfloor/comm/xl/bin/mpif90
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl --output xl/mpixlf90 /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlf90
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl --output xl/mpixlf90_r /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlf90_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy --output xl.legacy/mpif90 /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpif90
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy --output xl.legacy/mpixlf90 /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlf90
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy --output xl.legacy/mpixlf90_r /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlf90_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy.ndebug --output xl.legacy.ndebug/mpif90 /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpif90
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlf90 /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlf90
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlf90_r /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlf90_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.ndebug --output xl.ndebug/mpif90 /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpif90
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.ndebug --output xl.ndebug/mpixlf90 /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlf90
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.ndebug --output xl.ndebug/mpixlf90_r /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlf90_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc --output gcc/mpixlf2003 /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlf2003
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc --output gcc/mpixlf2003_r /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlf2003_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc --output gcc/mpixlf2008 /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlf2008
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc --output gcc/mpixlf2008_r /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlf2008_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc.legacy --output gcc.legacy/mpixlf2003 /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlf2003
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc.legacy --output gcc.legacy/mpixlf2003_r /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlf2003_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc.legacy --output gcc.legacy/mpixlf2008 /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlf2008
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc.legacy --output gcc.legacy/mpixlf2008_r /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlf2008_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl --output xl/mpixlf2003 /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlf2003
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl --output xl/mpixlf2003_r /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlf2003_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl --output xl/mpixlf2008 /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlf2008
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl --output xl/mpixlf2008_r /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlf2008_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy --output xl.legacy/mpixlf2003 /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlf2003
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy --output xl.legacy/mpixlf2003_r /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlf2003_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy --output xl.legacy/mpixlf2008 /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlf2008
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy --output xl.legacy/mpixlf2008_r /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlf2008_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlf2003 /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlf2003
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlf2003_r /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlf2003_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlf2008 /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlf2008
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlf2008_r /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlf2008_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.ndebug --output xl.ndebug/mpixlf2003 /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlf2003
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.ndebug --output xl.ndebug/mpixlf2003_r /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlf2003_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.ndebug --output xl.ndebug/mpixlf2008 /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlf2008
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.ndebug --output xl.ndebug/mpixlf2008_r /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlf2008_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc --output gcc/mpixlf95 /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlf95
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc --output gcc/mpixlf95_r /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlf95_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc.legacy --output gcc.legacy/mpixlf95 /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlf95
./autoperf-gen-fortran.pl --trim --lib mpichf90-gcc.legacy --output gcc.legacy/mpixlf95_r /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlf95_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl --output xl/mpixlf95 /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlf95
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl --output xl/mpixlf95_r /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlf95_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy --output xl.legacy/mpixlf95 /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlf95
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy --output xl.legacy/mpixlf95_r /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlf95_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlf95 /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlf95
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.legacy.ndebug --output xl.legacy.ndebug/mpixlf95_r /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlf95_r
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.ndebug --output xl.ndebug/mpixlf95 /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlf95
./autoperf-gen-fortran.pl --trim --lib mpichf90-xl.ndebug --output xl.ndebug/mpixlf95_r /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlf95_r

./autoperf-gen-cc.pl --trim --output gcc/mpicc /bgsys/drivers/ppcfloor/comm/gcc/bin/mpicc
./autoperf-gen-cc.pl --trim --output gcc/mpixlc /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlc
./autoperf-gen-cc.pl --trim --output gcc/mpixlc_r /bgsys/drivers/ppcfloor/comm/gcc/bin/mpixlc_r
./autoperf-gen-cc.pl --trim --output gcc.legacy/mpicc /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpicc
./autoperf-gen-cc.pl --trim --output gcc.legacy/mpixlc /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlc
./autoperf-gen-cc.pl --trim --output gcc.legacy/mpixlc_r /bgsys/drivers/ppcfloor/comm/gcc.legacy/bin/mpixlc_r
./autoperf-gen-cc.pl --trim --output xl/mpicc /bgsys/drivers/ppcfloor/comm/xl/bin/mpicc
./autoperf-gen-cc.pl --trim --output xl/mpixlc /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlc
./autoperf-gen-cc.pl --trim --output xl/mpixlc_r /bgsys/drivers/ppcfloor/comm/xl/bin/mpixlc_r
./autoperf-gen-cc.pl --trim --output xl.legacy/mpicc /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpicc
./autoperf-gen-cc.pl --trim --output xl.legacy/mpixlc /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlc
./autoperf-gen-cc.pl --trim --output xl.legacy/mpixlc_r /bgsys/drivers/ppcfloor/comm/xl.legacy/bin/mpixlc_r
./autoperf-gen-cc.pl --trim --output xl.legacy.ndebug/mpicc /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpicc
./autoperf-gen-cc.pl --trim --output xl.legacy.ndebug/mpixlc /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlc
./autoperf-gen-cc.pl --trim --output xl.legacy.ndebug/mpixlc_r /bgsys/drivers/ppcfloor/comm/xl.legacy.ndebug/bin/mpixlc_r
./autoperf-gen-cc.pl --trim --output xl.ndebug/mpicc /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpicc
./autoperf-gen-cc.pl --trim --output xl.ndebug/mpixlc /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlc
./autoperf-gen-cc.pl --trim --output xl.ndebug/mpixlc_r /bgsys/drivers/ppcfloor/comm/xl.ndebug/bin/mpixlc_r
