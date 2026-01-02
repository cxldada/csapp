#include <stdio.h>

struct SA {
    unsigned int a : 24;
    unsigned int b : 16;
};

struct SA2 {
    unsigned int a : 24;
    long b : 32;
};

struct SA3 {};

int main() {
  struct SA2 sa = {.a = 7, .b = 15};
  printf("long size = %lu bytes\n", sizeof(long));
  printf("sa size = %lu, sa.a = %d, sa.b = %d\n", sizeof(struct SA2), sa.a, sa.b);

  printf("sa3 size = %lu bytes\n", sizeof(struct SA3));

  return 0;
}