#include "../inc/pathfinder.h"

static void calculate_paths(t_list **resultPaths, t_list **adjacencyLists, t_list *names, int *buffer, int bufferIndex, const int current, int startNode) {
    if (current == startNode) {
        buffer[bufferIndex++] = startNode;
        int i = 0;
        int j = 0;
        int *reverseArray = malloc(bufferIndex * sizeof(int));

        for (i = bufferIndex - 2; i >= 0; i--) {
            reverseArray[j++] = buffer[i];
        }

        mx_push_back(&resultPaths[buffer[1]], reverseArray);
    } else {
        for (t_list *temp = adjacencyLists[current]; temp; temp = temp->next) {
            buffer[bufferIndex++] = *(int *)temp->data;
            calculate_paths(resultPaths, adjacencyLists, names, buffer, bufferIndex, *(int *)temp->data, startNode);
            bufferIndex--;
        }
    }
}

t_list ** create_paths(t_list ** lists, t_list * names, int len, int startnode)
{
    int nums[200];
    t_list ** ways = malloc((len+1) * sizeof(t_list*));
    for (int i = 0; i < len; i++){
        ways[i] = mx_create_node(malloc(1));
    }
    ways[len] = NULL;
    for (int i = 0; i < len; i++){
        if (i != startnode){
            nums[0] = -1;
            nums[1] = i;
            calculate_paths(ways, lists, names, nums, 2, i, startnode);
            free(ways[i]->data);
            mx_pop_front(&ways[i]);
        }
    }
    free(ways[startnode]->data);
    free(ways[startnode]);
    return ways;
}




