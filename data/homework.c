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

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int)x >> k;
    return xsra & (~0U >> k);
}

int sra(int x, int k) {
    size_t w = sizeof(x) << 3;
    int xsrl = (unsigned)x >> k;
    unsigned sign = x >> (w - 1);
    unsigned mask = sign << (w - k);
    return xsrl | mask;
}

void test2_63() {
    unsigned a = 0x12345678;
    unsigned ret = srl(a, 0);
    printf("%u >> %d = %u\n", a, 0, ret);
    show_bits((byte_pointer)&a, sizeof(unsigned));
    show_bits((byte_pointer)&ret, sizeof(unsigned));
    a = 0xFF123456;
    ret = srl(a, 4);
    printf("%u >> %d = %u\n", a, 4, ret);
    show_bits((byte_pointer)&a, sizeof(unsigned));
    show_bits((byte_pointer)&ret, sizeof(unsigned));

    int b = 0x12345678;
    int ret2 = sra(b, 2);
    printf("%d >> %d = %d\n", b, 2, ret2);
    show_bits((byte_pointer)&b, sizeof(unsigned));
    show_bits((byte_pointer)&ret2, sizeof(unsigned));
    b = 0xFF123456;
    ret2 = sra(b, 4);
    printf("%d >> %d = %d\n", b, 4, ret2);
    show_bits((byte_pointer)&b, sizeof(unsigned));
    show_bits((byte_pointer)&ret2, sizeof(unsigned));
}

int any_odd_one(unsigned x) { return !!(x & 0xAAAAAAAA); }

int odd_ones(unsigned x) {}

int main(int argc, char *argv[]) {
    START("2.61");
    ex2_61();
    END();

    START("2.62");
    int_shifts_are_arithmetic();
    END();

    START("2.63");
    test2_63();
    END();

    START("2.64");
    unsigned x = 0x00000002;
    printf("any_odd_one(0x%.2x) = %d", x, any_odd_one(x));
    END();

    // START("2.65");
    // odd_ones(0xFFFF0000);
    // END();

    return 0;
}