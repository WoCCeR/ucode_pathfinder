#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void*, void*)){
    t_list *ptr;
    t_list *lptr = NULL;
    int size = 0;

    if (lst == NULL)
        return NULL;

    for (t_list *node = lst; node; node = node->next)
        size++;

    for (int i = 0; i < size; i++)
    {
        ptr = lst;

        while (ptr->next != lptr)
        {
            if (cmp(ptr->data, ptr->next->data))
            {
                void *tmp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = tmp;
            }

            ptr = ptr->next;
        }

        lptr = ptr;
    }

    return lst;
}
