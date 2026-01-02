#include <stdarg.h>
#include <stdio.h>

struct Point {
    int x;
    int y;
};

int print_args(int number, ...) {
  va_list ap;
  va_start(ap, number);

  struct Point p = va_arg(ap, struct Point);
  printf("Point.x = %d, Point.y = %d", p.x, p.y);

  //   for (int i = 0; i < number; ++i) {
  //     printf("%d -- %lf\n", i + 1, va_arg(ap, Point));
  //   }
  va_end(ap);
  return 0;
}

int main(int argc, char *argv[]) {
//   print_args(3, 1, 2, 3);

struct Point p = {1, 2};
print_args(1, p);
return 0;
}