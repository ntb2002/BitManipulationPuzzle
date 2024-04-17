/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
int test_bitAnd(int x, int y)
{
  return (x&y);
}
int test_bitImply(int x, int y)
{
  int result = 0;
  int i;
  int curXBit = 0;
  int curYBit = 0;
  int implyResult = 0;
  for (i = 0; i < 32; i++){
    curXBit = (x >> i) & 0x1;
    curYBit = (y >> i) & 0x1;
    if (curXBit == 1 && curYBit == 0){
      implyResult = 0;
    }else{
      implyResult = 1;
    }
    result |= implyResult << i;
  }
  return result;
}
int test_fourthBits() {
    return -2004318072;
}
int test_getByte(int x, int n) {
  char* bp = (char*) &x;
  return bp[n] & 0xFF;
}
int test_replaceByte(int x, int n, int c){
  char* bp = (char*) &x;
  bp[n] = (char)(c & 0xFF);
  return x;
}
int test_isNotEqual(int x, int y) {
  return x == y ? 0 : 1;
}
/*int test_isCapitalizedLetter(int x){
  return x >= 'A' && x <= 'Z' ? 1 : 0;
}
int test_shortSignMag2TwosComp(int x){
  x = x & 0xFFFF;
  int abs = x & 0x7FFF;
  int sign = x >= 0x8000 ? 1 : 0;
  return sign ? -abs : abs;
}*/
