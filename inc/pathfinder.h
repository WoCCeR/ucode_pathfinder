#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"
int mx_atoi(const char* str, int * err);
int validation_string(char * str, char delim, int end);
int lines_dif(char ** b1, char * line2);
int get_index_value(t_list * list, void * value);
int add_name(t_list ** names, char * name, int i_to);
void mx_del_list(t_list **list, bool free_content);
void del_matrix(int ** matrix, int size);
int ** generate_paths_matrix(t_list * names, char ** lines, int l_count);
void handle_error(char * error_message, char * replacement, int free_replacement);
t_list * validation(int argc, char * argv[], int * islands_count, int *** paths);
void* get_value_index(t_list* list, int i);
bool cmp_paths(void *route1, void *route2);
t_list ** create_paths(t_list ** lists, t_list * names, int len, int startnode);
void print_distance(int ** G, int * real, int dist);
void print_path(t_list * names, int * path, int last);
void print_result(int ** G, t_list ** pred_lists, t_list * names, int * distance, int startnode);
void dijkstra(int ** G, t_list * names, int n, int startnode);

#endif


