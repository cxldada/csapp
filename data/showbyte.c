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

void show_float_bit(float *x) {}

int main(int argc, char *argv[]) {
  int x = 1234567;
  show_int(x);

  float f = 1234567.0;
  // printf("%f: ", f);
  show_float(f);

  show_pointer(&x);

  // printf("%f: ", f);
  // show_bits((byte_pointer)&f, sizeof(float));

  // float f2 = 1.08;
  // printf("%f2: ", f2);
  // show_float(f2);
  // printf("%f2: ", f2);
  // show_bits((byte_pointer)&f2, sizeof(float));

  // unsigned int *x = (unsigned int *)&f;
  // unsigned int *t = (unsigned int *)&f2;
  // printf("i = %d\n", *x - *t);
  // // while (*x != *t) {
  // //   *x -= 1;
  // //   printf("%f: ", f);
  // //   show_int(*x);
  // //   printf("%f: ", f);
  // //   show_bits((byte_pointer)x, sizeof(unsigned int));
  // // }

  // printf("%u\n", *x & 0x007fffff);
  // printf("%u\n", *t & 0x007fffff);

  // unsigned int z = 0x3f80000f;
  // printf("%f\n", *((float *)&z));
  // show_bits((byte_pointer)&z, sizeof(unsigned int));

  // z = 0x3fffffff;
  // printf("%f\n", *((float *)&z));
  // show_bits((byte_pointer)&z, sizeof(unsigned int));

  // z = 0x7f800000;
  // printf("%f\n", *((float *)&z));
  // show_bits((byte_pointer)&z, sizeof(unsigned int));

  // void *p = malloc(sizeof(int));
  // show_pointer(p);
  return 0;
}
