#include "../inc/pathfinder.h"


void* get_value_index(t_list* list, int i) {
    int j = 0;
    for (t_list* temp = list; temp; temp = temp->next) {
        if (j == i) {
            return temp->data;
        }
        j++;
    }
    return NULL;
}
