#include "../inc/libmx.h"

int mx_binary_search(char**arr, int size, const char *s, int *count){
    int right = size-1, left = 0;
    int guess;
    int mid;
    while (left <= right) {
        (*count)+=1;
        mid = left + (right - left)/2;
        guess = mx_strcmp(s, arr[mid]);
        if (guess < 0)
            right = mid-1;
        else
            left = mid+1;
        if (guess == 0)
            return mid;
    }
        (*count) = 0;
        return -1;
}
