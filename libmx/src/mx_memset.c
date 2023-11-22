#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len){
    unsigned char *mem = b;

    while (len--) {
        *mem++ = (unsigned char)c;
    }

    return b;
}
