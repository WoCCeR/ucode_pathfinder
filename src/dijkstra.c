#include "../inc/pathfinder.h"

void dijkstra(int ** weights, t_list * node_names, int num_nodes, int start_node)
{
    int shortest_distances[num_nodes];
    int predecessor_array[200];
    int count_predecessors = 0;
    t_list ** predecessors_lists = malloc(num_nodes * sizeof(t_list *));
    int visited[num_nodes], count, min_distance, next_node, i, j;

    for (i = 0; i < num_nodes; i++)
        for (j = 0; j < num_nodes; j++)
            if (weights[i][j] == 0)
                weights[i][j] = 2147483647;

    for (i = 0; i < num_nodes; i++)
    {
        shortest_distances[i] = weights[start_node][i];
        int t = start_node;
        predecessors_lists[i] = mx_create_node((void *)&t);
        visited[i] = 0;
    }

    shortest_distances[start_node] = 0;
    visited[start_node] = 1;
    count = 1;

    while (count < num_nodes - 1)
    {
        min_distance = 2147483647;

        for (i = 0; i < num_nodes; i++)
        {
            if (shortest_distances[i] < min_distance && !visited[i])
            {
                min_distance = shortest_distances[i];
                next_node = i;
            }
        }

        visited[next_node] = 1;

        for (i = 0; i < num_nodes; i++)
        {
            if (!visited[i])
            {
                if (min_distance + weights[next_node][i] < shortest_distances[i] &&
                    min_distance + weights[next_node][i] > 0)
                {
                    predecessor_array[count_predecessors] = next_node;
                    shortest_distances[i] = min_distance + weights[next_node][i];
                    mx_del_list(&predecessors_lists[i], false);
                    predecessors_lists[i] = mx_create_node((void *)(&predecessor_array[count_predecessors++]));
                }
                else if (min_distance + weights[next_node][i] == shortest_distances[i] &&
                         min_distance + weights[next_node][i] > 0)
                {
                    predecessor_array[count_predecessors] = next_node;
                    mx_push_front(&predecessors_lists[i], (void *)(&predecessor_array[count_predecessors++]));
                }
            }
        }

        count++;
    }

    print_result(weights, predecessors_lists, node_names, shortest_distances, start_node);
}


