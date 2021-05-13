# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# Mozilla's universal charset detector C/C++ Wrapping API
#      Writer(s) :
#          Detect class by John Gardiner Myers <jgmyers@proofpoint.com>
#          C wrapping API by JoungKyun.Kim <http://oops.org>
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.

DISTCLEANFILES =
EXTRA_DIST = Changelog LICENSE libchardet.spec \
			 project/libchardet.cbp test/utf-8.txt test/utf-8-bom.txt

ACLOCAL_AMFLAGS = -I m4
SUBDIRS = . src man test

#docdir = $(datadir)/doc/$(PACKAGE)-$(VERSION)
dist_doc_DATA = Changelog LICENSE

bin_SCRIPTS = chardet-config
pkgconfigdir=$(libdir)/pkgconfig
pkgconfig_DATA = chardet.pc

DISTCLEANFILES += *.bz2 aclocal.m4 *~

test-install:
	$(MAKE) DESTDIR=`pwd`/test-install install

distclean-local:
	rm -rf autom4te.cache test-install
