#include "../inc/pathfinder.h"

void print_path(t_list * nodes, int * path, int last_index) {
    int j = 0;
    mx_printstr("Path: ");
    mx_printstr(get_value_index(nodes, path[0]));
    mx_printstr(" -> ");
    mx_printstr(get_value_index(nodes, path[last_index]));
    mx_printstr("\nRoute: ");

    for (; path[j + 1] != -1; j++) {
        mx_printstr(get_value_index(nodes, path[j]));
        mx_printstr(" -> ");
    }

    mx_printstr(get_value_index(nodes, path[j]));
}
