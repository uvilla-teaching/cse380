## Initial set-up

Before you start:

```
module load gsl
```

## Step 1
Use `autoscan` to generate an initial template for `configure.ac`

## Step 2
Then boostrap your configuration with
```
autoreconf --install
```

## Step 3: Add m4 macros:

```
mkdir m4
cp $TACC_GSL_DIR/share/aclocal/gsl.m4 m4
```

Also, add the macro in `configure.ac`

```
AC_CONFIG_MACRO_DIR([m4])
AX_PATH_GSL(2.1,[],AC_MSG_ERROR([Unable to locate GSL or meet minimum version requirement]))
```
Everytime you change something
```
autoreconf
../configure --help
```

# Step 4: Set up automake

Modify `configure.ac`
```
AM_INIT_AUTOMAKE
AC_OUTPUT(Makefile, src/Makefile)
```

Create a `Makefile.am`
```
AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4
SUBDIRS = src
```

Create a `src/Makefile.am`
```
AUTOMAKE_OPTIONS = foreign

# Define executable to create
bin_PROGRAMS            = rng-tool

# Define source code files which are part of the executable. 
rng_tool_SOURCES  = main.c mytools.c mytools.h

# Use GSL macro variables to provide augment include search path and
# library linkage

AM_CPPFLAGS = $(GSL_CFLAGS)
LIBS        = $(GSL_LIBS)
```

Reconfigure everything
```
autoreconf –f -i
```


