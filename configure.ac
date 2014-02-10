# Process this file with autoconf to produce a configure script.
# Configure template for chardet library
#
# $Id$

#
AC_PREREQ(2.59)
AC_INIT([libchardet], [1.0.4], [http://oops.org])
AC_CONFIG_AUX_DIR([tools])
AM_INIT_AUTOMAKE([-Wall -Werror -Wno-override foreign no-dependencies])
AM_MAINTAINER_MODE

AC_CONFIG_SRCDIR([src/nsUniversalDetector.h])
AC_CONFIG_HEADER([chardet-config.h])
AC_PREFIX_DEFAULT([/usr/local])

AC_SUBST(SONAME_INFO)
AC_SUBST(SONAME_VERSION)
AC_SUBST(SONAME_MAJOR)
AC_SUBST(SONAME_MINOR)
AC_SUBST(SONAME_REVISION)
AC_SUBST(PROG)

PROG=`echo $PACKAGE_NAME | sed 's/^lib//g'`

SONAME_MAJOR=1
SONAME_MINOR=0
SONAME_REVISION=0
SONAME_VERSION=$SONAME_MAJOR.$SONAME_MINOR.$SONAME_REVISION

SONAME_VALUE=$(($SONAME_MAJOR + $SONAME_MINOR))
SONAME_INFO="$SONAME_VALUE:$SONAME_REVISION:$SONAME_MINOR"

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AX_GL_VISIBILITY
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_AWK
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
AC_PROG_RANLIB

AC_PATH_PROG(PERL, perl)
if test ! -f "$ac_cv_path_PERL"; then
	AC_MSG_ERROR(Can't not found perl)
fi

AC_PATH_PROG(DATE, date)
if test ! -f "$ac_cv_path_DATE"; then
	AC_MSG_ERROR(Can't not found date)
fi

AC_SUBST(PACKAGE_DATE)
PACKAGE_DATE=$(LANG= $DATE +"%a %b %d %Y")

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T
AC_HEADER_TIME

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_STAT
AX_DLL_EXPORT_CHECK

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	man/Makefile
	chardet-config
	chardet.pc
	libchardet.spec
])
AC_OUTPUT
