# HDF5

## Compile example

First we need to load the hdf5 module from TACC.
This will define the environmental variables `TACC_HDF5_INC` and `TACC_HDF5_LIB` that are needed to compile the test case

```
module load hdf5
```

Then compile with intel
```
icc -o h5_write.exe -I$TACC_HDF5_INC h5_write.c -L$TACC_HDF5_LIB -lhdf5 -lz
```

## Write and inspect file

```
./h5_write.exe ref.h5 0.
h5ls ref.h5
h5dump ref.h5
```

## Create a new file and compare

Option `-r` shows all differences.
Option `-d` uses an absolute tolerance
Option `-p` uses a relative tolerance

```
./h5_write.exe new.h5 1e-6
h5diff -r new.h5 ref.h5
h5diff -r -d 1e-7 new.h5 ref.h5
h5diff -r -d 1e-3 new.h5 ref.h5
h5diff -r -p 1e-7 new.h5 ref.h5
h5diff -r -p 1e-3 new.h5 ref.h5
```
