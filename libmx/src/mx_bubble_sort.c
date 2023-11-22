#include "../inc/libmx.h"

int mx_bubble_sort (char**arr, int size){
    int cnt = 0;
    for (int i = 0; i < size-1; i++)
        for (int j = i+1; j < size; j++)
            if (mx_strcmp(arr[i], arr[j]) > 0)
            {
                char *temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                cnt++;
            }
    return cnt;
}
