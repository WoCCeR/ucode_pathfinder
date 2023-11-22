#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const char *p = (const char *)s + n;
    c = (unsigned char)c;

    while (n-- > 0) {
        if (*--p == c)
            return (void *)p;
    }
    return NULL;
}
