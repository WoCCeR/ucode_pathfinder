#include "../inc/libmx.h"
unsigned long mx_hex_to_nbr(const char *hex){
    int i = 0;
    unsigned long cnt = 0;
    while (hex[i] != '\0'){
        cnt*=16;
        if (hex[i] >= 'a' && hex[i] <= 'f')
            cnt += hex[i]-'a'+10;
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            cnt += hex[i]-'A'+10;
        else
            cnt += hex[i]-'0';
        i++;
    }
    return cnt;
}
