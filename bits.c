/* 
 * CS:APP Data Lab 
 * 
 * Nathan Walzer - nwalzer
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
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
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  //utilizes DeMorgan's Law:
  //"the complement of the union of two sets is the same as the intersection of their
  //complements" - Wikipedia
  return (~x&~y);
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  //Compare left and right halfs until only 8 bits remain, then & with 0x55
  //if all even bits are 1 then x^0x55 returns 0x0, so running ! with it returns 1
  x = x&(x>>16);
  x = x&(x>>8);

  x = x&0x55;
  return !(x^0x55);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  //Stores in y the value of the n byte ^ m byte,
  //then shifts those bytes back over and xors them again, swapping n and m
  int y;
  int n2 = n << 3; //gets 8*number
  int m2 = m << 3;
  
  y = ((x>>n2) ^ (x>>m2)) & 0xFF;
  x = x ^ (y<<m2);
  x = x ^ (y<<n2);
  
  return x;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  //if the number is less than 0x30 then low will be negative. If the number
  //is greater than 0x39 then high will be negative. If either high or low
  //is negative then it will return false, or 0;
  int negSign = 1 << 31;
  int low = ~0x30;
  int high = ~(negSign | 0x39);

  low = (low+1+x) >> 31;
  high = (high+x) >> 31;
  return !(low | high);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  //shift x to the right by n. Then change all of the 1s that were just added
  //and turn them into 0s
  return (x >> n) & ~(((0x01 << 31) >> n) << 1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  //keep checking halves and shifting the number. Essentially locate the index(+1) of
  //the first 1 bit to appear in the number (left -> right). Include sign if needed
  int hold;
  int numBits = 1;
  int tempBits;
  int mask = 2;
  int mask2 = 0xC;
  int mask3 = 0xF0;
  int mask4 = 0xFF << 8;
  int mask5 = (mask4 | 0xFF) << 16;

  hold = x^(x>>31);

  tempBits = (!!(hold & mask5)) << 4;
  numBits += tempBits;
  hold = hold >> tempBits;

  tempBits = (!!(hold & mask4)) << 3;
  numBits += tempBits;
  hold = hold >> tempBits;

  tempBits = (!!(hold & mask3)) << 2;
  numBits += tempBits;
  hold = hold >> tempBits;
  
  tempBits = (!!(hold & mask2)) << 1;
  numBits += tempBits;
  hold = hold >> tempBits;

  tempBits = (!!(hold & mask));
  numBits += tempBits;
  hold = hold >> tempBits;
  return numBits + (hold&1);
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    //if X is 0, !!x will give 0 and return 0. If x is 1 or -1 then !!x yields 1.
    //Using arithmetic right shifting, if we compare 1 to all 0s (pos) then we get
    //1, if we compare 1 to all 1s (neg) then we get -1
    return (!!x) | (x>>31);
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  //if x and y are different, x^y will be true. If x and y are the same, x^y will be false.
  //return the opposite of x^y
  return !(x^y);
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
  //shift x to the right by n. Replace all of the newly added 1s with 0s. Combine
  //x>>n with x<<(32-n) to make a rotated number
  int y = n^31; //31 - n
  int max = ((x >> 31) << 31) >> n << 1;
  int final = (x >> n) ^ max;
  int wrap = x << (y+1);
  return final | wrap;
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
  int mask = x>>31;
  int mask2 = 1&mask;
  return ((((x^mask)+mask2)&(~(((~0)>>31)<<n)))^mask)+mask2;
}
/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x) {
  int hold = x;
  int num1s;
  int toShift;
  int sign = !(~x);

  num1s = !(~(hold>>16)) << 4;//look at left half of number, if all are 1 then we have minimum 16 1s and need to look at 
  //other half, if any of the left 16 are 0 then we look further to the left
  hold = hold << num1s;//look at right half if all 1s, otherwise still look at left half

  toShift = !(~(hold>>24)) << 3;//look at left half of previous shift. If all 1s then minimum 8 ones, otherwise need to look
  //at the other half. If any on the left 8 are 0 then look further left
  hold = hold << toShift;
  num1s = num1s | toShift;//similar function as (num1s + toShift)

  toShift = !(~(hold>>28)) << 2;//continue pattern of looking left repeatedly until a 0 bit is found
  hold = hold << toShift;
  num1s = num1s | toShift;

  toShift = !(~(hold>>30)) << 1;
  hold = hold << toShift;
  num1s = num1s | toShift;

  num1s = num1s ^ (0x1&(hold>>31));
  return num1s + sign;//add sign bit if it's negative
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
  //determine if there is OF by comparing signs. If there is overflow then we will return TMax or TMin depending on the direction result took
  int result = x + y;
  int isOF = ((result^x) & (result^y)) >> 31; //if the sign of the sum is different from both x and y then overflow occurred
  int sum2EB = result & ~isOF;//is result if no overflow, 0 otherwise
  int maxAmount = isOF & ((1<<31) + (result>>31));//is 0 if no overflow, otherwise will be TMax or TMin, depending on which overflow occurs
  return sum2EB | maxAmount;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 //if uf is NaN then just return it, otherwise return the same bits but with a negative sign
 int y = 0x7FFFFFFF & uf;
 if(y > 0x7F800000){
   return uf;
 }
 return uf^0x80000000;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
   //If NaN then return argument. If exponent is 0 or 1 then normalize the fraction. Otherwise just subtract 1 from the exponent
   int sign = 0x80000000 & uf;
   int exp = 0x7F800000 & uf;
   int fraction = 0x007FFFFF & uf;
   if(exp == 0x7F800000){
     return uf;
   }
   if((exp == 0x00800000) || !exp){ //if exp is 0 or 1
      fraction = (uf&0x00FFFFFF) >> 1;
      fraction += (uf & 1) & ((uf&3) >> 1);
      return sign|fraction;//
   }
   return sign|fraction|((exp - 1) & 0x7F800000);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  //if x is 0 or -1 then we know the representation. Otherwise make x positive. Determine exp by subtracting the number of left shifts from 158
  //Calculate and normalize the fraction then add everything together
  int expB4Bias = 158;//158 because 127(bias) + 31(max shifts) = 158
  int signMask = 0x80000000;
  int isNeg = x&signMask;
  int fraction;

  if(x == 0x80000000){//if x is -1 then we already know its float representation
    return 0xCF000000;
  }
  if(!x){//if x is 0, return 0
    return 0;
  }

  if(isNeg){//make x positive since we already have the sign preserved
    x = -x;
  }

  while(!(x&signMask)){//shift x to the left until a 1 is in the sign position
    x = x << 1;
    expB4Bias--;//at most 31 shifts are performed, this will represent the exponent before the machine subtracts the bias
  }

  fraction = (x&0x7FFFFFFF) >> 8;//shift x out of the exponent area
  if(x&0x80 && (((x&0x7F) > 0x00)|| fraction&0x01)){
    fraction++;
  }

  expB4Bias = expB4Bias << 23;
  return (isNeg | expB4Bias) + fraction;
}
