#include "../inc/libmx.h"

char *mx_strtrim(const char *str){
    if (str == NULL)
        return NULL;
    const char *start = str;
    while(*start != '\0' && mx_isspace(*start))
    {
        start++;
    }
    const char *end = str;
    const char *trimmed_end = NULL;
    while (*end != '\0') {
        if (!mx_isspace(*end)) {
            trimmed_end = end;
        }
        end++;
    }

    size_t len = 0;
    if (trimmed_end != NULL) {
        len = trimmed_end - start + 1;
    }

    char *trimmed_str = mx_strnew(len);
    if (trimmed_str == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        trimmed_str[i] = start[i];
    }

    return trimmed_str;
}
