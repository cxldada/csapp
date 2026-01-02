#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;
typedef unsigned char byte;

void show_bits(byte_pointer start, size_t len) {
    int i = len - 1;
    int j = 0;
    for (; i >= 0; i--) {
        byte b = start[i];
        for (j = 7; j >= 0; j--) {
            printf("%d", (b >> j) & 1);
            if (j == 4) {
                printf(" ");
            }
        }
        printf(" ");
    }
    printf("\n");
}

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) { show_bytes((byte_pointer)&x, sizeof(int)); }
void show_float(float x) { show_bytes((byte_pointer)&x, sizeof(float)); }
void show_pointer(void *x) { show_bytes((byte_pointer)&x, sizeof(void *)); }