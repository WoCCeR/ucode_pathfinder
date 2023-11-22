#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data){
    t_list *back = mx_create_node(data);

    if (!back)
        return;

    if (!*list)
    {
        *list = back;
        return;
    }

    t_list *cur = *list;

    while (cur->next)
        cur = cur->next;

    cur->next = back;
}
