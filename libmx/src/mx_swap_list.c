#include "../inc/libmx.h"

void mx_swap_list(t_list **a, t_list **b){
    t_list *temp = *a;

    *a = *b;
    *b = temp;
}
