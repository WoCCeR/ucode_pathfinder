#include "../inc/pathfinder.h"


void print_distance(int ** weights, int * path_nodes, int min_distance)
{
    bool print_plus = false;
    mx_printstr("Distance: ");
    int i = 0;
    int j = 1;
    mx_printint(weights[path_nodes[i++]][path_nodes[j++]]);

    for (; path_nodes[j] != -1; i++, j++) {
        mx_printstr(" + ");
        mx_printint(weights[path_nodes[i]][path_nodes[j]]);
        print_plus = true;
    }

    if (print_plus) {
        mx_printstr(" = ");
        mx_printint(min_distance);
    }

    mx_printstr("\n");
}
