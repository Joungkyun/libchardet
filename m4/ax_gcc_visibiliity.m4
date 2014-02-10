dnl
dnl                       Written by JoungKyun.Kim
dnl            Copyright (c) 2011 JoungKyun.Kim <http://oops.org>
dnl
dnl ----------------------------------------------------------------------------
dnl Redistribution and use in source and binary forms, with or without
dnl modification, are permitted provided that the following conditions are met:
dnl
dnl     * Redistributions of source code must retain the above copyright notice,
dnl       this list of conditions and the following disclaimer.
dnl
dnl     * Redistributions in binary form must reproduce the above copyright
dnl       notice, this list of conditions and the following disclaimer in the
dnl       documentation and/or other materials provided with the distribution.
dnl
dnl     * Neither the name of JoungKyun.Kim nor the url of oops.org
dnl       nor the names of their contributors may be used to endorse or
dnl       promote products derived from this software without specific prior
dnl       written permission.
dnl
dnl THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
dnl AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
dnl IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
dnl ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
dnl LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
dnl CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
dnl SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
dnl INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
dnl CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
dnl ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
dnl POSSIBILITY OF SUCH DAMAGE.
dnl ----------------------------------------------------------------------------
dnl  This file is part of olibc.
dnl
dnl  $Id$
dnl

AC_SUBST(GCC_MAJOR_VERSION)
AC_SUBST(GCC_MINOR_VERSION)
AC_SUBST(GCC_PATCH_VERSION)

dnl Get GCC major.minor.patch version
AC_DEFUN([AX_GCC_VERSION],
[
if test $GCC = "yes"; then
	if test -z "$PERL"; then
		AC_PATH_PROG(PERL, perl)
		if test ! -f "$ac_cv_path_PERL"; then
			AC_MSG_ERROR(Can't not found perl)
		fi
	fi

	if test -n "$PERL"; then
		GCC_VERSION="`$CC -dumpversion 2> /dev/null | $PERL -pe 's/([[0-9]]+)\.([[0-9]]+)\.([[0-9]]+)/GCC_MAJOR_VERSION=\1;GCC_MINOR_VERSION=\2;GCC_PATCH_VERSION=\3;/g'`"
		eval "$GCC_VERSION"
	fi
fi
])

AC_DEFUN([AX_GCC_VISIBILITY],
[
if test "$GCC" = "yes"; then
	AX_GCC_VERSION
    if test $GCC_MAJOR_VERSION -ge 4; then
        CFLAGS="$CFLAGS -fvisibility=hidden"
    fi
fi
])

dnl Copyright (C) 2005 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl visibility.m4 serial 1 (gettext-0.15)
dnl From Bruno Haible.
dnl Modifyed by Joungkyun.Kim

dnl Tests whether the compiler supports the command-line option
dnl -fvisibility=hidden and the function and variable attributes
dnl __attribute__((__visibility__("hidden"))) and
dnl __attribute__((__visibility__("default"))).
dnl Does *not* test for __visibility__("protected") - which has tricky
dnl semantics (see the 'vismain' test in glibc) and does not exist e.g. on
dnl MacOS X.
dnl Does *not* test for __visibility__("internal") - which has processor
dnl dependent semantics.
dnl Does *not* test for #pragma GCC visibility push(hidden) - which is
dnl "really only recommended for legacy code".
dnl Set the __visibility__("hidden") option in variable CFLAG.
dnl Defines and sets the variable HAVE_VISIBILITY.

AC_DEFUN([AX_GL_VISIBILITY],
[
  AC_REQUIRE([AC_PROG_CC])
  HAVE_VISIBILITY=0
  if test -n "$GCC"; then
    AC_MSG_CHECKING([for simple visibility declarations])
    AC_CACHE_VAL(gl_cv_cc_visibility, [
      gl_save_CFLAGS="$CFLAGS"
      CFLAGS="$CFLAGS -fvisibility=hidden"
      AC_TRY_COMPILE(
        [extern __attribute__((__visibility__("hidden"))) int hiddenvar;
         extern __attribute__((__visibility__("default"))) int exportedvar;
         extern __attribute__((__visibility__("hidden"))) int hiddenfunc (void);
         extern __attribute__((__visibility__("default"))) int exportedfunc (void);],
        [],
        gl_cv_cc_visibility=yes,
        gl_cv_cc_visibility=no)
      CFLAGS="$gl_save_CFLAGS"])
    AC_MSG_RESULT([$gl_cv_cc_visibility])
    if test $gl_cv_cc_visibility = yes; then
      CFLAGS="$CFLAGS -fvisibility=hidden"
      HAVE_VISIBILITY=1
      AC_DEFINE_UNQUOTED([HAVE_VISIBILITY], [$HAVE_VISIBILITY],
        [Define to 1, depending whether the compiler supports simple visibility declarations.])
    fi
  fi
])
