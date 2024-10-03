# HDF5 example using cmake

## Download HDF5

```
wget https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-1.14/hdf5-1.14.2/src/hdf5-1.14.2.tar.gz
tar -zxf hdf5-1.14.2.tar.gz
cd hdf5-1.14.2
ls
```

## Load CMake

```
module load cmake
```

## Build

CMake uses VPATHS :)

First we need to __configure__ our build
```
mkdir build
cd build
cmake ..
```

Then we can proceed as usual

```
make -j 4
make install
```

Opsy....

```
cmake -DCMAKE_INSTALL_PREFIX=$HOME/sw/hdf5
make -j 4
make install
ls $HOME/sw/hdf5
```

# How can I see these options?

Use `cmake -L`

```
cmake -L 2>&1 | grep INSTALL
```

Note, to start from scratch simply delete `CMakeCache.txt`

```
rm CMakeCache.txt 
cmake ..
cmake -LA 2>&1 | grep INSTALL
```

## Interactive
Use `ccmake`

Option `A` toggles advanced mode



