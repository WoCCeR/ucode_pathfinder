#include "../inc/pathfinder.h"

int main(int argc, char * argv[]) {
    int count;
    int ** paths;
    t_list * names = validation(argc, argv, &count, &paths);

    for (int i = 0; i < count - 1; i++) {
        dijkstra(paths, names, count, i);
    }

    del_matrix(paths, count);
    mx_del_list(&names, true);

    return 0;
}


