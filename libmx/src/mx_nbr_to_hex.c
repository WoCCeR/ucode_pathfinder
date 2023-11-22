#include "../inc/libmx.h"
char *mx_nbr_to_hex(unsigned long nbr){
    char *result;
    int i = nbr, size = 0;
    while (i > 0){
        i /= 16;
        size++;
    }
    result = mx_strnew(size);
    while (nbr > 0){
        if (nbr % 16 < 10){
            result[size - i - 1] = '0' + nbr % 16;
        }
        else{
            result[size - i - 1] = 'a' + nbr % 16 - 10;
        }
        nbr/= 16;
        i++;
    }
    return result;
}
