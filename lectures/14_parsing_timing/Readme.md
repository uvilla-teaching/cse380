# Obtain and build libGRVY

```
wget https://github.com/hpcsi/grvy/releases/download/0.38.0/grvy-0.38.0.tar.gz
tar -xzf grvy-0.38.0.tar.gz
cd grvy-0.38.0
```

Load the boost module, configure, and build
```
module load boost
./configure --with-boost=$TACC_BOOST_DIR --enable-boost-headers-only  CC=icc CXX=icpc FC=ifort
make
```

## Show input file parsing:

```
cd examples
cat input.c
cat pecos-input.txt
```

## Show timing
```
cat timer.c
./timer
```

## Show logging
```
cat messages.c
./messages
```
