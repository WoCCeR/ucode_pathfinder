#include "../inc/libmx.h"

char *mx_itoa(int number){
    if (number == -2147483648)
        return "-2147483648";
    else if (number == 0)
        return "0";
    int size = 0;
    int i = number;
    if (i < 0){
        size++;
        i*=-1;
    }
    while (i > 0) {
        i /= 10;
        size++;
    }
    char *result = mx_strnew(size);
    if (number < 0){
        number *= -1;
        result[0] = '-';
    }
    while (number > 0) {
        result[size - i - 1] = '0' + number % 10;
        i++;
        number/=10;
    }
    return result;

}
