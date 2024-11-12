# CMake and CTest with boost

## 1. Load boost

```
module load boost
```

## 2. Create a subdirectory `build` and run `cmake`

```
mkdir build
cd build
cmake
```

Note that cmake should automatically pick up the location of boost.
If not try:
```
cmake -DBOOST_ROOT=$TACC_BOOST_DIR ..
```

## 3. Compile
```
make
```

You should see the test being compiled

## 4. Run ctest
```
cd test
ctest
```
