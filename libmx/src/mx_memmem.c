#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (little_len > big_len)
        return NULL;

    const unsigned char *ubig = big;
    const unsigned char *ulittle = little;

    for (size_t i = 0; i <= big_len - little_len; i++) {
        if (mx_memcmp(ubig + i, ulittle, little_len) == 0)
            return (void *)(ubig + i);
    }

    return NULL;
}
