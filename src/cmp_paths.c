#include "../inc/pathfinder.h"

bool cmp_paths(void *route1, void *route2) {
    int *a = (int *) route1;
    int *b = (int *) route2;

    int i = 0;
    while (a[i] != -1 && b[i] != -1) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
        i++;
    }

    return a[i] > b[i];
}
