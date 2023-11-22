#include "../inc/libmx.h"

int mx_isdigit(int i){
    if (i >= '0' && i <= '9'){
        return 1;
    }
    return 0;
}
