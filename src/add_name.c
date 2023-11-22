#include "../inc/pathfinder.h"

int add_name(t_list** names, char* name, int i_to) {
    if (i_to < 0 || !*names) {
        return 0;
    }

    for (t_list* temp = *names; temp; temp = temp->next) {
        char* name_i = (char*)temp->data;
        if (mx_strcmp(name_i, name) == 0) {
            return 0;
        }
    }

    mx_push_back(names, mx_strdup(name));
    return 1;
}
