# Examples of building a library using Autotools

## Download and untar the GSL library

```
export VERSION=2.8
wget https://mirror.ibcp.fr/pub/gnu/gsl/gsl-$VERSION.tar.gz  
tar -xzf gsl-$VERSION.tar.gz
cd gsl-$VERSION
```
## Let's get access to a compute node

```
idev -A CDA23007 -t 30:00 -p vm_small
```

## configure

```
./configure
more config.log
more config.h
more Makefile
```

Note: system-related variables (e.g. presence of <sys/stat.h>, package-specific variables (e.g. PACKAGE_VERSION)

## Building

Let's build using a single-core

```
/bin/time -f '%e' make >& make.log
make clean
```

# Let's build using all cores

```
/bin/time -f '%e' make -j >& make.log
```
(DON'T do this on a login node!!!)

## Try make install

```
make install
```

Why it fails and how to fix it?

```
../configure --help
../configure --prefix=$HOME/bin/gsl-$VERSION
make
make install
ls $HOME/bin/gsl-$VERSION
```

What compiler was used?
```
grep "\bCC\b" config.log
```
NOTE: \b for word boundaries: looks for full words only
grep "\bCFLAGS\b" config.log

## Changing flags/Compiler options:
```
./configure --prefix=$HOME/bin/gsl-$VERSION-intel CC=icc CFLAGS="-g -O0"
```

You could also do `export CC=icc`, but better don't. Why?

```
head -n 20 configure.log
```

## VPATHS
Often it is a good idea to keep the source code and your build in separate directories. How? Use `VPATHS`

```
make distclean
mkdir build-intel && cd build-intel
../configure --prefix=$HOME/bin/gsl-$VERSION-intel CC=icc CFLAGS="-g -O0"
```

## Make checks

```
make -j 16 check
find . -name "*.log"
```


