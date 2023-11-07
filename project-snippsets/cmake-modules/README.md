## Request a development node

```
idev
```

## Load the following modules

```
module load intel/19.1.1
module load impi/19.0.9
module load cmake/3.24.2
module load petsc/3.19-nohdf5
module load phdf5/1.14.0
```


## Run cmake with the following command line
```
cmake -DHDF5_DIR=$TACC_PHDF5_DIR -DCMAKE_CXX_COMPILER=mpiicpc -DCMAKE_C_COMPILER=mpiicc -DPETSC_DIR=$PETSC_DIR -DPETSC_ARCH=$PETSC_ARCH ../
```
