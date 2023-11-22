#include "../inc/pathfinder.h"

int get_index_value(t_list * list, void * value){
    int i = 0;
    for (t_list * temp = list; temp; temp = temp->next, i++){
        if (!mx_strcmp(value, temp->data)) return i;
    }
    return -1;
}
