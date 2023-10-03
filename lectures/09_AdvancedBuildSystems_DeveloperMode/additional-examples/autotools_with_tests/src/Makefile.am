AUTOMAKE_OPTIONS = foreign


# Define executable to create

bin_PROGRAMS            = rng-tool

# Define source code files which are part of the executable. Note how
# automake canonicalizes the "rng-tool" text to use as input
# below.. All characters in the name except for letters, numbers, the
# strudel (@), and the underscore are turned into underscores when
# making variable references.

rng_tool_SOURCES  = main.c mytools.c mytools.h

# Use GSL macro variables to provide augment include search path and
# library linkage

AM_CPPFLAGS = $(GSL_CFLAGS)
LIBS        = $(GSL_LIBS)



