## Request a development node

```
idev
```

## Configuration 1 (intel compilers): use standalone version of HDF5

### Load the following modules

```
module load intel/19.1.1
module load impi/19.0.9
module load cmake/3.24.2
module load petsc/3.19-nohdf5
module load phdf5/1.14.0
```

### Run cmake with the following command line
```
cmake -DHDF5_DIR=$TACC_PHDF5_DIR -DCMAKE_CXX_COMPILER=mpiicpc -DCMAKE_C_COMPILER=mpiicc -DPETSC_DIR=$PETSC_DIR -DPETSC_ARCH=$PETSC_ARCH ../
make
```

## Configuration 2 (inter compilers): use HDF5 from PETSc

### Load the following modules

```
module load intel/19.1.1
module load impi/19.0.9
module load cmake/3.24.2
module load petsc/3.19
```

### Run cmake with the following command line
```
cmake -DHDF5_DIR=$PETSC_DIR/$PETSC_ARCH -DCMAKE_CXX_COMPILER=mpiicpc -DCMAKE_C_COMPILER=mpiicc -DPETSC_DIR=$PETSC_DIR -DPETSC_ARCH=$PETSC_ARCH ../
make
```

## Configuration 3 (GCC)

### Load the following modules
```
module purge
module load gcc/11.2.0
module load cmake/3.24.2
module load impi/19.0.9
module load petsc/3.19
```

### Run cmake with the following command line
```
cmake -DHDF5_DIR=$PETSC_DIR/$PETSC_ARCH -DCMAKE_CXX_COMPILER=mpicxx -DCMAKE_C_COMPILER=mpicc -DPETSC_DIR=$PETSC_DIR -DPETSC_ARCH=$PETSC_ARCH ../
```


## Run

```
ibrun -n 1 ./hello_project
```
