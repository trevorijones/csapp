#include <stdio.h>
/* Get most significant byte */
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

