#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *dest = dst;
    const char *source = src;

    for (size_t i = 0; i < n; i++) {
        dest[i] = source[i];

        if (source[i] == c) {
            return &dest[i + 1];
        }
    }

    return NULL;
}
