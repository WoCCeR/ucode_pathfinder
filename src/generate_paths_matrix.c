#include "../inc/pathfinder.h"

int **generate_paths_matrix(t_list *names, char **lines, int lineCount) {
    int size = mx_list_size(names);
    int **roads = malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++) {
        roads[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            roads[i][j] = 0;
        }
    }

    int fromIndex;
    int toIndex;
    for (int i = 1; i < lineCount; i++) {
        char **lineTokens = mx_strsplit(lines[i], ',');
        char **pathEndpoints = mx_strsplit(lineTokens[0], '-');
        int distance = mx_atoi(lineTokens[1], NULL);
        fromIndex = get_index_value(names, pathEndpoints[0]);
        toIndex = get_index_value(names, pathEndpoints[1]);

        if (fromIndex != -1 && toIndex != -1) {
            roads[fromIndex][toIndex] = distance;
            roads[toIndex][fromIndex] = distance;
        } else {
            mx_del_strarr(&lineTokens);
            mx_del_strarr(&pathEndpoints);
            del_matrix(roads, size);
            return NULL;
        }

        mx_del_strarr(&lineTokens);
        mx_del_strarr(&pathEndpoints);
    }

    return roads;
}

