#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    int i=0;
    while(s[i] != 000)
        i++;
    return i;
}
