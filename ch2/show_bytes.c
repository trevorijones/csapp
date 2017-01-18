#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer x, size_t len) {
    int i;
    for(i = 0; i < len; i++) 
        printf(" %.2X", x[i]);
    printf("\n");

}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

int is_little_endian() {
    return 0;
}


void main() {
    show_int(1);
    show_int(15);
    show_int(16);
    //when byte_pointer is a char *, this is printed as FFFFFFFF 00 00 00
    show_int(255);
    show_int(256);
}


