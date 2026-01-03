#include "showbyte.h"
#include <stdio.h>

#define START(str) printf("%s\n", str)
#define END() printf("\n====================\n")

void ex2_61() {
    int x = 0;
    int bitSize = sizeof(int) << 3;

    // A ======================
    {
        printf("A:\n");
        x = ~0;
        show_bits((byte_pointer)&x, sizeof(int));
        printf("x[%d] is all 1? [%d]\n", x, (!(~x)));

        x = 100;
        show_bits((byte_pointer)&x, sizeof(int));
        printf("x[%d] is all 1? [%d]\n", x, (!(~x)));
    }

    // B ======================
    {
        printf("B:\n");
        x = 0;
        show_bits((byte_pointer)&x, sizeof(int));
        printf("x[%d] is all 1? [%d]\n", x, (!x));

        x = 100;
        show_bits((byte_pointer)&x, sizeof(int));
        printf("x[%d] is all 1? [%d]\n", x, (!x));
    }

    // C ======================
    {
        printf("C:\n");
        x = 0x123456FF;
        int temp = ~x << ((sizeof(int) - 1) << 3);
        show_bits((byte_pointer)&x, sizeof(int));
        show_bits((byte_pointer)&temp, sizeof(int));
        printf("x[%d] is all 1? [%d]\n", x, (!temp));

        x = 0x12345678;
        temp = ~x << ((sizeof(int) - 1) << 3);
        show_bits((byte_pointer)&x, sizeof(int));
        show_bits((byte_pointer)&temp, sizeof(int));
        printf("x[%d] is all 1? [%d]\n", x, (!temp));
    }

    // D ======================
    {
        printf("D:\n");
        x = 0x00123456;
        int temp = x >> ((sizeof(int) - 1) << 3);
        show_bits((byte_pointer)&x, sizeof(int));
        show_bits((byte_pointer)&temp, sizeof(int));
        printf("x[%d] is all 1? [%d]\n", x, (!temp));

        x = 0x12345678;
        temp = x >> ((sizeof(int) - 1) << 3);
        show_bits((byte_pointer)&x, sizeof(int));
        show_bits((byte_pointer)&temp, sizeof(int));
        printf("x[%d] is all 1? [%d]\n", x, (!temp));
    }
}

int main(int argc, char *argv[]) {
    START("2.61");
    ex2_61();
    END();

    return 0;
}