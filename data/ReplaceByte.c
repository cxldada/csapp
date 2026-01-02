#include "isLittleEndian.h"
#include "showbyte.h"
#include <assert.h>
#include <stdio.h>

unsigned replaceByte(unsigned x, int i, unsigned char b) {
    if (isLittleEndian() > 0) {
        printf("little endian\n");
    } else {
        printf("big endian\n");
    }
    unsigned long size = sizeof(x);
    printf("x:");
    show_bytes((byte_pointer)&x, size);
    if (i >= size) {
        printf("i > size[%lu]\n", size);
        assert(0);
    }
    printf("i: %d\n", i);

    unsigned mask = ~(0xFF << (i * 8));
    unsigned ret = x & mask | (b << (i * 8));
    printf("ret:");
    show_bytes((byte_pointer)&ret, size);
    return ret;
}

int main(int argc, char *argv[]) {
    replaceByte(0x12345678, 2, 0xAB);
    printf("=======================\n");
    replaceByte(0x12345678, 0, 0xAB);
    return 0;
}