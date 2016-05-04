/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Communicator client code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *                 Jehan <jehan@girinstud.io>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "nsSBCharSetProber.h"
/****************************************************************
ILL: illegal character.
CTR: control character specific to the charset.
RET: carriage/return.
SYM: symbol (punctuation) that does not belong to word.
NUM: 0 - 9.

*****************************************************************/
unsigned char Latin2_HungarianCharToOrderMap[] =
{
CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,RET,CTR,CTR,RET,CTR,CTR, // 00
CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, // 10
SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, // 20
NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,SYM,SYM,SYM,SYM,SYM,SYM, // 30
SYM,  1, 15, 25, 16,  0, 26, 13, 19,  7, 22,  9,  4, 12,  5,  8, // 40
 21, 34,  6,  3,  2, 20, 17, 32, 33, 18, 10,SYM,SYM,SYM,SYM,SYM, // 50
SYM,  1, 15, 25, 16,  0, 26, 13, 19,  7, 22,  9,  4, 12,  5,  8, // 60
 21, 34,  6,  3,  2, 20, 17, 32, 33, 18, 10,SYM,SYM,SYM,SYM,CTR, // 70
CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, // 80
CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, // 90
SYM, 56,SYM, 41,SYM, 54, 43,SYM,SYM, 36, 53, 57, 58,SYM, 44, 59, // a0
SYM, 60,SYM, 41,SYM, 54, 43,SYM,SYM, 36, 53, 61, 62,SYM, 44, 63, // b0
 64, 11, 46, 40, 35, 65, 37, 47, 38, 14, 66, 50, 67, 28, 55, 68, // c0
 39, 48, 49, 23, 51, 27, 24,SYM, 42, 69, 30, 31, 29, 52, 70, 45, // d0
 71, 11, 46, 40, 35, 72, 37, 47, 38, 14, 73, 50, 74, 28, 55, 75, // e0
 39, 48, 49, 23, 51, 27, 24,SYM, 42, 76, 30, 31, 29, 52, 77,SYM, // f0
};

unsigned char win1250HungarianCharToOrderMap[] =
{
CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,RET,CTR,CTR,RET,CTR,CTR, // 00
CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, // 10
SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, // 20
NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,SYM,SYM,SYM,SYM,SYM,SYM, // 30
SYM,  1, 15, 25, 16,  0, 26, 13, 19,  7, 22,  9,  4, 12,  5,  8, // 40
 21, 34,  6,  3,  2, 20, 17, 32, 33, 18, 10,SYM,SYM,SYM,SYM,SYM, // 50
SYM,  1, 15, 25, 16,  0, 26, 13, 19,  7, 22,  9,  4, 12,  5,  8, // 60
 21, 34,  6,  3,  2, 20, 17, 32, 33, 18, 10,SYM,SYM,SYM,SYM,CTR, // 70
SYM,ILL,SYM,ILL,SYM,SYM,SYM,SYM,ILL,SYM, 36,SYM, 43, 78, 44, 79, // 80
ILL,SYM,SYM,SYM,SYM,SYM,SYM,SYM,ILL,SYM, 36,SYM, 43, 80, 44, 81, // 90
SYM,SYM,SYM, 41,SYM, 82,SYM,SYM,SYM,SYM, 53,SYM,SYM,SYM,SYM, 83, // a0
SYM,SYM,SYM, 41,SYM,SYM,SYM,SYM,SYM, 84, 53,SYM, 54,SYM, 54, 85, // b0
 86, 11, 46, 40, 35, 87, 37, 47, 38, 14, 88, 50, 89, 28, 55, 90, // c0
 39, 48, 49, 23, 51, 27, 24,SYM, 42, 91, 30, 31, 29, 52, 92, 45, // d0
 93, 11, 46, 40, 35, 94, 37, 47, 38, 14, 95, 50, 96, 28, 55, 97, // e0
 39, 48, 49, 23, 51, 27, 24,SYM, 42, 98, 30, 31, 29, 52, 99,SYM, // f0
};


/* Model Table:
 * total sequences: 1075
 * first 512 sequences: 0.9744556413335339
 * next 512 sequences (512-1024): 0.025418609410482556
 * rest: 0.00012574925598353784
 */
char HungarianLangModel[] = 
{
3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,2,2,3,3,0,2,2,0,0,
2,2,3,3,3,3,3,3,2,3,3,2,3,3,2,3,3,3,3,3,3,3,3,2,1,3,3,0,2,2,2,2,
3,3,3,3,3,3,3,3,3,3,2,3,3,2,3,3,2,3,3,3,3,2,3,3,3,2,2,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,2,3,2,3,3,3,2,3,2,3,2,3,3,3,3,2,
3,3,3,3,3,3,2,3,3,3,2,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,2,2,
3,3,3,3,3,3,2,3,3,3,3,3,2,3,3,3,3,2,3,2,3,2,2,2,3,3,3,3,2,2,2,2,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,2,3,2,3,3,2,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,0,3,3,3,2,3,2,3,3,0,2,2,2,2,
2,2,3,3,3,3,3,2,2,3,3,2,3,3,0,3,3,3,2,3,3,3,2,2,0,3,3,0,1,0,0,0,
3,3,3,3,3,3,3,3,3,3,2,3,2,2,3,3,1,2,2,2,3,2,3,3,3,2,2,2,3,3,2,2,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,2,2,3,3,2,3,3,2,2,3,3,3,2,2,
1,2,3,3,3,3,3,2,2,3,3,0,3,3,2,3,3,3,0,2,2,3,3,0,0,3,2,0,2,0,0,0,
3,3,3,2,3,2,2,3,3,2,3,3,3,2,3,3,2,2,2,2,3,3,2,2,2,2,2,0,3,2,2,3,
3,3,3,3,3,3,3,3,3,3,2,3,2,3,3,3,2,3,3,3,3,2,3,3,3,2,3,2,3,2,2,2,
2,2,3,3,3,3,3,2,2,3,3,0,3,3,2,3,3,3,0,2,0,3,2,0,0,2,0,0,2,2,0,0,
3,3,2,3,3,2,3,3,3,2,1,3,2,0,3,3,2,0,2,2,3,2,2,3,2,2,2,3,2,2,2,2,
3,3,3,3,2,3,3,3,3,3,2,3,3,2,3,2,3,3,2,2,3,2,3,3,3,2,2,3,3,2,2,2,
3,3,2,2,2,2,2,3,3,2,0,3,2,2,3,2,2,2,2,2,2,0,3,2,2,2,2,3,3,2,2,2,
3,3,3,3,2,3,2,3,3,2,3,3,3,2,3,3,2,3,0,3,3,2,2,2,2,2,2,2,3,2,2,3,
3,3,2,2,2,3,2,3,3,2,2,3,2,0,3,2,2,2,2,2,3,2,0,2,2,2,0,2,3,2,2,2,
3,2,3,3,3,3,3,2,2,3,2,3,3,3,2,3,3,2,2,2,2,2,2,0,0,2,2,2,0,0,0,0,
3,3,3,3,3,2,3,3,3,2,3,3,2,2,3,2,2,3,2,2,3,3,3,2,2,3,2,2,3,3,2,0,
3,3,3,2,3,3,2,2,3,2,2,3,2,2,3,2,3,2,2,1,3,2,2,3,2,2,2,2,2,2,3,2,
2,2,3,3,3,3,3,3,2,3,3,2,3,3,2,3,3,2,0,2,2,3,3,0,2,3,2,0,0,2,2,0,
2,0,3,3,3,3,3,0,0,3,3,0,2,3,0,3,3,3,0,2,2,2,2,0,0,2,0,0,0,0,0,0,
3,3,2,3,2,2,2,3,3,3,2,2,2,0,3,2,2,2,2,3,2,0,0,2,2,2,2,0,3,0,0,0,
3,3,2,2,2,2,3,3,3,1,0,2,2,2,3,2,2,0,2,0,3,1,2,2,3,2,2,3,0,3,2,2,
2,2,3,3,3,2,3,3,2,3,3,2,2,2,2,3,3,3,0,2,0,2,3,0,1,2,2,2,2,2,0,0,
1,2,3,2,2,3,3,2,2,2,3,0,3,3,0,2,2,3,0,0,2,2,3,0,0,2,0,0,0,0,0,0,
0,0,2,2,3,3,2,0,0,3,2,0,2,3,0,1,2,2,0,1,0,0,1,0,0,2,2,0,0,0,0,0,
1,2,3,3,3,3,2,1,0,2,2,0,1,3,0,2,2,2,0,2,0,2,3,0,2,2,2,0,0,0,0,0,
2,2,2,3,2,2,3,2,0,3,2,0,2,2,0,2,0,3,0,2,2,0,2,0,0,0,2,0,0,0,0,0,
};


SequenceModel Latin2HungarianModel = 
{
  Latin2_HungarianCharToOrderMap,
  HungarianLangModel,
  32,
  (float)0.9744556413335339,
  PR_FALSE,
  "ISO-8859-2"
};

SequenceModel Win1250HungarianModel = 
{
  win1250HungarianCharToOrderMap,
  HungarianLangModel,
  32,
  (float)0.9744556413335339,
  PR_FALSE,
  "WINDOWS-1250"
};
