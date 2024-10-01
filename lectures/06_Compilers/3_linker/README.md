# Try to compile bessel.c

```
icc -g bessel.c
```
Why does not work?

```
module load gsl
icc -I $TACC_GSL_INC bessel.c
```
Still not working

```
icc -g -I $TACC_GSL_INC bessel.c -L$TACC_GSL_LIB -lgsl -lgslcblas
ldd a.out
```

```
module del gsl
ldd a.out

nm -u a.out
```

What about adding the path to the exectutable?
```
module load gsl
icc -g -I $TACC_GSL_INC bessel.c -L$TACC_GSL_LIB -lgsl -lgslcblas -Wl,-rpath,$TACC_GSL_LIB
module del gsl
./a.out
```
Still running!

What about static linking?
```
icc -g -I $TACC_GSL_INC bessel.c -static -L$TACC_GSL_LIB -lgsl -lgslcblas
```

The command above won't work because some system library that need to be linked are only dynamic.
Thus we need to manually statically link libgsl and libgslcblas

```
icc -g -I $TACC_GSL_INC bessel.c $TACC_GSL_LIB/libgsl.a $TACC_GSL_LIB/libgslcblas.a
```
Show again nm -u and ldd
