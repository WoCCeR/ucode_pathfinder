#include "../inc/pathfinder.h"

void mx_del_list(t_list** list, bool free_content) {
    if (!list || !*list) {
        return;
    }

    t_list* node = *list;
    t_list* temp = node;

    while (temp) {
        temp = node->next;

        if (free_content) {
            free(node->data);
        }

        free(node);

        node = temp;
    }
    free(temp);
    *list = NULL;
}



