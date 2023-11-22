#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n){
    char *dest = dst;
    const char *source = src;

    for (size_t i = 0; i < n; i++) {
        dest[i] = source[i];
    }

    return dst;
}

