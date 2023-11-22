#include "../inc/libmx.h"

int mx_sqrt(int x) {
    int right = 46341, left = 0;
    int guess;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        guess = mid * mid;
        if (guess > x)
            right = mid - 1;
        else
            left = mid + 1;
        if (guess == x)
            return mid;
    }
    return 0;
}
