#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([cse380], [0.1], [uvilla@oden.utexas.edu])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/main.c])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC

# Check for GSL

AX_PATH_GSL(1.15,[],AC_MSG_ERROR([Unable to locate GSL or meet minimum version requirement]))


AC_OUTPUT(Makefile src/Makefile)
