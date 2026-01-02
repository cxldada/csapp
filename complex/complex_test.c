#include <stdio.h>
#include <complex.h>

int main() {
  double complex z = 3 + 2 * I;
  double complex rz = 3 - 2 * I;
  double complex ret = z * rz;
  printf("Phase is %f, modulus is %f\n", creal(ret), cimag(ret));
  printf("Phase is %f, modulus is %f\n", carg(z), cabs(z));
  return 0;
}