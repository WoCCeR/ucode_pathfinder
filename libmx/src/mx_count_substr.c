#include "../inc/libmx.h"

int mx_count_substr(const char*str, const char*sub){
    if (str == NULL || sub == NULL)
        return -1;
    int cnt = 0;
    const char *temp = str;
    size_t sub_len = mx_strlen(sub);
    while ((temp = mx_strstr(temp, sub))) {
        temp += sub_len;
        cnt++;
    }
    return cnt;
}
