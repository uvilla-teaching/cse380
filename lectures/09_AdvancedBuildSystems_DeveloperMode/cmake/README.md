# Basic compile

```
cmake -DGSL_ROOT_DIR=$GSL_DIR ..
make
```

Note that cmake loves rpath

```
make VERBOSE=1
```

# Other compiler options 

Compile in debug mode
```
cmake -DGSL_ROOT_DIR=$GSL_DIR -DCMAKE_BUILD_TYPE=Debug ..
```

Or in optimized mode
```
cmake -DGSL_ROOT_DIR=$GSL_DIR -DCMAKE_BUILD_TYPE=Release ..
```

Or  change the compiler

```
cmake -DGSL_ROOT_DIR=$GSL_DIR -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=icc ..
```
