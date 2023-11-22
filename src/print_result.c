#include "../inc/pathfinder.h"

void print_result(int **adjacencyMatrix, t_list **predLists, t_list *names, int *distance, int startNode) {

    int numVertices = mx_list_size(names);
    int j = 0;

    t_list **paths = create_paths(predLists, names, numVertices, startNode);

    for (int i = 1; paths[i]; i++) {
        if (i != startNode) {
            mx_sort_list(paths[i], cmp_paths);
            for (t_list *path = paths[i]; path; path = path->next) {
                int *way = path->data;
                for (j = 0; way[j + 1] != -1; j++);

                if (way[j] > startNode) {
                    mx_printstr("========================================\n");
                    print_path(names, way, j);
                    mx_printstr("\n");
                    print_distance(adjacencyMatrix, way, distance[i]);
                    mx_printstr("========================================\n");
                }
            }
        }
    }

    for (int i = 0; i < numVertices; i++) {
        if (i != startNode) {
            t_list *temp = paths[i];
            mx_del_list(&temp, true);
        }
    }

    for (int p = 0; p < numVertices; p++) {
        mx_del_list(&predLists[p], false);
    }

    free(paths);
    free(predLists);
}
