#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2){
    if (!s1 || !s2)
        return s1;
    char *newstr = mx_strnew(mx_strlen(s1)+ mx_strlen(s2)+1);
    char *start = newstr;
    while (*s1 != '\0'){
        *newstr = *s1;
        s1++;
        newstr++;
    }

    while (*s2 != '\0') {
        *newstr = *s2;
        newstr++;
        s2++;
    }

    *newstr = '\0';
    return start;
}
