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

int int_shifts_are_arithmetic() {
    int ret = 0;
    int mask = ~0;
    ret = (mask >> 8 == mask);
    printf("int shifts are arithmetic: [%d]\n", ret);
    return ret;

    // 用无符号模拟逻辑右移
    // unsigned test = ~0;
    // ret = (test >> 8 == test);
    // printf("int shifts are arithmetic: [%d]\n", ret);
    // return ret;
}

int main(int argc, char *argv[]) {
    START("2.61");
    ex2_61();
    END();

    START("2.62");
    int_shifts_are_arithmetic();
    END();

    return 0;
}