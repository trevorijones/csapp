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

// returns 1 if the system is little endian or 0 if big endian
int is_little_endian() {
    // int is 4 bytes either on 32 and 64 bits systems
    unsigned int x = 1;
    // 01 00 00 00 in little endian
    // 00 00 00 01 in big endian
    // grab 1rst byte
    return *((byte_pointer) &x);
}


void main() {
    show_int(1);
    show_int(15);
    show_int(16);
    //when byte_pointer is a char * instead of unsigned char *, this is printed as FFFFFFFF 00 00 00
    //there is a sign extention when FF is considered signed to int.
    show_int(255);
    show_int(256);
    printf("little endian: %d\n", is_little_endian());
    
    //2.59
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    //   => 0x765432EF
    int z;
    int *pz = &z;
    byte_pointer bpz = (byte_pointer) pz;
    byte_pointer bpy = (byte_pointer) &y;
    if (is_little_endian()) {
        *bpz = *((byte_pointer) &x);
        *++bpz = *++bpy;
        *++bpz = *++bpy;
        *++bpz = *++bpy;
    }

    printf("%X\n", z);

    show_int(z);
}


