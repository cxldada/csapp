#pragma once
#include <stddef.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char *byte_pointer;
typedef unsigned char byte;

void show_bits(byte_pointer start, size_t len);
void show_bytes(byte_pointer start, size_t len);

#ifdef __cplusplus
}
#endif