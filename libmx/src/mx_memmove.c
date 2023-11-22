#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *udst = dst;
    const unsigned char *usrc = src;

    if (udst > usrc) {
        for (size_t i = len; i > 0; i--)
            mx_memcpy(udst + i - 1, usrc + i - 1, 1);
    } else {
        mx_memcpy(udst, usrc, len);
    }


    return dst;
}
