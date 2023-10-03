# Run autoscan to find out things

```
autoscan
cp configure.scan configure.ac
```

Add version and name to configure.ac

Bootstrap the buildsystem

```
autoreconf --install
```

What about GSL?

```
mkdir m4
cp $TACC_GSL_DIR/share/aclocal/gsl.m4 m4
```

Tell stuff to configure.ac

```
AC_CONFIG_MACRO_DIR([m4])

AX_PATH_GSL(2.1,[],AC_MSG_ERROR([Unable to locate GSL or meet minimum version requirement]))
```

Now we need to re-boostrap
```
autoreconf
./configure --help
```

Setup automake
```
AM_INIT_AUTOMAKE 
AC_OUTPUT(Makefile src/Makefile)
```


Create a `Makefile.am`
autoreconf –f -i

Also add

```
AM_CFLAGS = $(GSL_CFLAGS)
LIBS      = $(GSL_LIBS)
```

To makefile.am
