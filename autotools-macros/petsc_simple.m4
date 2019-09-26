# SYNOPSIS
#
#   Simple test for PETSC
#
#   AM_PATH_PETSC(<package-required=yes/no> )
#
# DESCRIPTION
#
#   Provides a --with-petsc=DIR option for the PETSc math
#   library. Searches --with-petsc, $PETSC_DIR, and the usual places
#   for PETSc headers and libraries.
#
#   On success, sets HDF5_CFLAGS, HDF5_LIBS, and #defines HAVE_HDF5.
#   Assumes package is optional unless overridden with $2=yes.
#
# LAST MODIFICATION
#
#   $Id: hdf5_new.m4 31520 2012-06-28 14:53:30Z mpanesi $
#
# COPYLEFT
#
#   Copyright (c) 2012 Karl W. Schulz <karl@ices.utexas.edu>
#   Copyright (c) 2009 Rhys Ulerich <rhys.ulerich@gmail.com>
#   Copyright (c) 2008 Thomas Porschberg <thomas@randspringer.de>
#   Copyright (c) 2008 Caolan McNamara <caolan@skynet.ie>
#   Copyright (c) 2008 Alexandre Duret-Lutz <adl@gnu.org>
#   Copyright (c) 2008 Matthew Mueller <donut@azstarnet.com>
#
#   Copying and distribution of this file, with or without modification, are
#   permitted in any medium without royalty provided the copyright notice
#   and this notice are preserved.

AC_DEFUN([AX_PATH_PETSC],[

HAVE_PETSC=0
AC_ARG_VAR(PETSC_DIR,[root directory of PETSc installation])

AC_ARG_WITH(petsc, 
  [AS_HELP_STRING([--with-petsc[=DIR]],[root directory of PETSc installation (default = PETSC_DIR)])],
  [with_petsc=$withval
if test "${with_petsc}" != yes; then
    PETSC_PREFIX=$withval
fi
],[
with_petsc=$withval
if test "x${PETSC_DIR}" != "x"; then
   PETSC_PREFIX=${PETSC_DIR}
fi
])

# package requirement; if not specified, the default is to assume that
# the package is optional

is_package_required=ifelse([$1], ,no, $1 )

if test -d "${PETSC_PREFIX}" ; then
     AC_CHECK_FILE( [${PETSC_PREFIX}/lib/petsc/conf/variables], [found_varfile=yes],[found_varfile=no] )
fi

if test "$found_varfile" = yes; then
	HAVE_PETSC=1
        AC_DEFINE(HAVE_PETSC,1,[Define if PETSc is available])
        AC_MSG_NOTICE([PETSC install path found])
else
	if test "$is_package_required" = yes; then
	     AC_MSG_ERROR([PETSc install directory not found: try --with-petsc or setting PETSC_DIR]) 
	else
             AC_MSG_NOTICE([Optional PETSC install path not found: disabling])
	fi
fi


AC_SUBST(PETSC_PREFIX)
AC_SUBST(HAVE_PETSC)
AM_CONDITIONAL(PETSC_ENABLED,test x$HAVE_PETSC = x1)	

])
