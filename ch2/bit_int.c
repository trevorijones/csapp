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
}
