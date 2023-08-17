## Load the following modules

```
module load  gcc/7.1.0 
module load impi/17.0.3
module load cmake/3.20.2
module load petsc/3.9
module load phdf5/1.8.16
```


## Run cmake with the following commad line
```
cmake -DHDF5_DIR=$TACC_HDF5_DIR -DCMAKE_CXX_COMPILER=mpicxx -DPETSC_DIR=$PETSC_DIR -DPETSC_ARCH=$PETSC_ARCH ../
```
