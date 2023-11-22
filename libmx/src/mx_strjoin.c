#include "../inc/libmx.h"

char* mx_strjoin(const char* s1, const char* s2) {
    char* result;
    if(s1 == NULL && s2 == NULL) {
        return NULL;
    }
    if(s1 == NULL) {
        result = mx_strdup(s2);

        return result;
    }
    if(s2 == NULL) {
        result = mx_strdup(s1);
        return result;
    }
    result = mx_strdup(s1);
    char* out = mx_strcat(result, s2);
    mx_printchar('s');
    return out;
}
