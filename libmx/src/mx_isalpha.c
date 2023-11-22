#include "../inc/libmx.h"

int mx_isalpha(int ch){
    if ((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <='Z'))
        return 1;
    return 0;
}
