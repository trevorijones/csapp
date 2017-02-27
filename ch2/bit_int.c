#include <stdio.h>
/* Commented solutions to the Bit-Level Integer Coding Rule 
   
   This is structured in sections aligned to exercices numbers.

   Assumptions:

   * Integers are represented in two's-complement form.
      || The most significant bit carries a wright and a sign.
   * Right shift of signed data is performed arithmetically.
      || 1000 >> 1 => 1100
      || 1000 >> 2 => 1110
      || 1000 >> 3 => 1111 
      || The sign is preserved
    * Data type int is w bit size. For some problems, you wil be given a specific 
      value for w, but otherwise your code should work as long as w is a multiple of 8.
      You can use the expression size(int) << 3 to compute w
      || size(int) is given in bytes ( of 8 bit )
      || size(int) << 3 => s * 2 * 2 * 2 => s * 8

    Forbidden:

    * Conditionals, loops, switch statements, function calls and  macro invocation
    * Division, modulos and multiplication.
    * Relative comparision operators ( <, >, <=, => )

    Allowed operations: 
    
    * All bit-level and logic operations.
      || bit-level: 
      ||  * bit and: &
      ||  * bit or : |
      ||  * bit not: ~
      ||  * bit xor: ^
      ||
      || logic:
      ||  * and: &&
      ||  *  or: ||
      ||  * not:  !
      || The logic operations treats the operands as integral values.
      ||  * 0 is FALSE
      ||  * Any other value is TRUE
      || The result is an integral value of 0 or 1:
      ||  * 0 is FALSE
      ||  * 1 is TRUE
      || Commonly used to normalize values:
      ||  * !!x is 1 if and only if x is not 0 

*/

/*   Get most significant byte */
int get_msb(int x) {
    //0x12345678 -> 0x12
    //0x12345678 -rs-> 0x11123456 -rs-> 0x11111234 -rs-> 0x11111112
    // ( size(int) - 1 ) * 8
    //0x11111112 & 0x000000FF -> 0x00000012
    return ( x >> ( ( sizeof(int) - 1 ) << 3 ) ) & 0x00FF;
}

int main() {
  printf("%.2X \n", get_msb(0x12345678));
  printf("%.2x \n", get_msb(0x78563412));
  //2.61

  int x;
  //Any bit of x equals 1 <=>  all bits of x is 0 (false) <=> !!x
  x=0xff;
  //!x is 0 if any bit is 1
  //!!x is 1 if !x is 0
  printf("%d\n",!!0x12345678);
  printf("%d\n",!!1);
  printf("%d\n",!!(1 << 2));
  printf("%d\n",!!0);

  //Any bit of x is 0 <=> not all bits of x is 1 <=> !!~x is true
  //~x is 0 if all bit are 1. x is all 1 => ~x is all 0
  printf("%d\n", !!~(0));
  printf("%d\n", !!~(0xFFFFFFFF));

  //Any bit in the least significant byte is 1
  x = 0x12345678;
  printf("%d\n", !!(x & 0xFF));
  x = 0xFF000000;

  printf("%d\n", !!(x & 0xFF));
  //
  //Any bit in the least significant byte is 0
}

