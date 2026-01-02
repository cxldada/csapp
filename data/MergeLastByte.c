#include <stdio.h>

typedef unsigned char *byte_pointer;
typedef unsigned int word;

int isLittleEndian() {
    unsigned int x = 1;
    char *c = (char *)&x;
    return *c;
}

void showBytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

word mergeLastByte(word x, word y) {
    word ret = (x & 0x000000FF) | (y & 0xFFFFFF00);
    printf("x:\t");
    showBytes((byte_pointer)&x, sizeof(word));
    printf("y:\t");
    showBytes((byte_pointer)&y, sizeof(word));
    printf("ret:\t");
    showBytes((byte_pointer)&ret, sizeof(word));
    return ret;
}

int main(int argc, char *argv[]) {
    word x = 0x89ABCDEF;
    word y = 0x76543210;
    word ret = mergeLastByte(x, y);
    return 0;
}