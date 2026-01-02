#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned int x = 1;
    char *c = (char*)&x;
    if (*c) {
        printf("Little Endian\n");
        return 1;
    } else {
        printf("Big Endian\n");
        return 0;
    }
    return 0;
}