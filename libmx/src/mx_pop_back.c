#include "../inc/libmx.h"

void mx_pop_back(t_list **head){
    if (!head || !*head)
        return;

    t_list *temp = *head;
    if (!(*head)->next)
    {
        free(*head);
        *head = NULL;
        return;
    }

    while (temp->next->next)
        temp = temp->next;

    free(temp->next);

    temp->next = NULL;
}
