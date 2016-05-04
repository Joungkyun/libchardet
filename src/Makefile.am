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

# $Id$

SONAME_MAJOR    = @SONAME_MAJOR@
SONAME_MINOR    = @SONAME_MINOR@
SONAME_REVISION = @SONAME_REVISION@
SONAME_INFO     = @SONAME_INFO@
SONAME_VERSION  = @SONAME_VERSION@

includedir = @includedir@/chardet

include_HEADERS = nsUniversalDetector.h chardet.h \
				../include/nscore.h ../include/version.h \
				../chardet-config.h
noinst_HEADERS = CharDistribution.h \
				nsCodingStateMachine.h \
				nsGB2312Prober.h \
				nsSBCSGroupProber.h \
				JpCntx.h \
				nsEUCJPProber.h \
				nsHebrewProber.h \
				nsSBCharSetProber.h \
				nsEUCKRProber.h \
				nsLatin1Prober.h \
				nsSJISProber.h \
				nsBig5Prober.h \
				nsEUCTWProber.h \
				nsMBCSGroupProber.h \
				nsUTF8Prober.h \
				nsCharSetProber.h \
				nsEscCharsetProber.h \
				nsPkgInt.h \
				../include/prmem.h \
				tables/Big5Freq.tab \
				tables/EUCKRFreq.tab \
				tables/EUCTWFreq.tab \
				tables/GB2312Freq.tab \
				tables/JISFreq.tab

AM_CFLAGS = -Wall @CFLAGS@
AM_CXXFLAGS = -Wall -Wno-non-virtual-dtor -nostdinc++ -fno-rtti -fno-exceptions @CPPFLAGS@
AM_LDFLAGS = -version-info $(SONAME_INFO) @LDFLAGS@ @LIBS@ @MINGW_CYGWIN_DYNLIB@

lib_LTLIBRARIES = libchardet.la
libchardet_la_SOURCES = CharDistribution.cpp JpCntx.cpp \
		tables/LangBulgarianModel.cpp \
		tables/LangCyrillicModel.cpp \
		tables/LangGreekModel.cpp \
		tables/LangHebrewModel.cpp \
		tables/LangHungarianModel.cpp \
		tables/LangThaiModel.cpp \
		tables/LangArabicModel.cpp \
		tables/LangDanishModel.cpp \
		tables/LangEsperantoModel.cpp \
		tables/LangFrenchModel.cpp \
		tables/LangGermanModel.cpp \
		tables/LangSpanishModel.cpp \
		tables/LangTurkishModel.cpp \
		tables/LangVietnameseModel.cpp \
		nsBig5Prober.cpp \
		nsCharSetProber.cpp nsEUCJPProber.cpp nsEUCKRProber.cpp \
		nsEUCTWProber.cpp nsEscCharsetProber.cpp nsEscSM.cpp \
		nsGB2312Prober.cpp nsHebrewProber.cpp nsLatin1Prober.cpp \
		nsMBCSGroupProber.cpp nsMBCSSM.cpp nsSBCSGroupProber.cpp \
		nsSBCharSetProber.cpp nsSJISProber.cpp nsUTF8Prober.cpp \
		nsUniversalDetector.cpp chardet.cpp
libchardet_la_CPPFLAGS = -I../include
