#include "../inc/libmx.h"

char* mx_strncpy (char*dst, const char*src, int len){
    char *start = dst;
    int i = 0;
    while(*src && i < len) {
        *dst = *src;
        dst++;
        src++;
        i++;
    }
    dst++;
    dst = NULL;
    return start;
}
