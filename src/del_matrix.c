#include "../inc/pathfinder.h"

void del_matrix(int ** matrix, int size){
    if (!matrix) {
        return;
    }
    for (int j = 0; j < size; j++) {
        if (matrix[j]) {
            free(matrix[j]);
            matrix[j] = NULL;
        }
    }
    free(matrix);
}
