#include "isLittleEndian.h"

int isLittleEndian() {
    unsigned int x = 1;
    char *c = (char *)&x;
    return *c;
}