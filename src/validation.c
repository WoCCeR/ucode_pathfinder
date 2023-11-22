#include "../inc/pathfinder.h"

t_list *validation(int argc, char *argv[], int *islands_count, int ***paths) {
    if (argc != 2) {
        handle_error("usage: ./pathfinder [filename]\n", NULL, 0);
    }
    char *file_str = mx_file_to_str(argv[1]);
    if (file_str == NULL) {
        handle_error("error: file ? does not exist\n", argv[1], 0);
    } else if (mx_strlen(file_str) == 0) {
        handle_error("error: file ? is empty\n", argv[1], 0);
    }
    int err = 0;
    char **lines = mx_strsplit(file_str, '\n');
    (*islands_count) = mx_atoi(lines[0], &err);
    int dists_sum = 0;
    int name_i = 0;
    int dup_isl_error = 0;
    int len_sum_error = 0;
    int dist;
    char **names_lines;
    char **names_count;
    int file_lines_count = mx_count_words(file_str, '\n');
    t_list *names = mx_create_node(malloc(sizeof(char)));
    free(file_str);
    if (err || (*islands_count) <= 0) {
        mx_del_strarr(&lines);
        mx_del_list(&names, 1);
        handle_error("error: line 1 is not valid\n", NULL, 0);
    }
    for (int i = 1; i < file_lines_count; i++) {
        dist = 0;
        names_lines = NULL;
        names_count = NULL;
        if (mx_get_char_index(lines[i], ',') != -1 &&
            validation_string(lines[i], '-', ',')) {
            names_count = mx_strsplit(lines[i], ',');
            if (names_count) {
                names_lines = mx_strsplit(names_count[0], '-');
            }
        }
        if (names_lines && names_count &&
            mx_strcmp(names_lines[0], names_lines[1])) {
            dist = mx_atoi(names_count[1], &err);
        }
        if (err || dist <= 0) {
            mx_del_strarr(&lines);
            mx_del_strarr(&names_count);
            mx_del_strarr(&names_lines);
            mx_del_list(&names, 1);
            handle_error("error: line ? is not valid\n", mx_itoa(i + 1), 1);
        }

        for (int j = 1; j < file_lines_count; j++) {
            if (validation_string(lines[j], '-', ',')) {
                if (i != j && !lines_dif(names_lines, lines[j])) {
                    dup_isl_error = 1;
                }
            }
        }

        name_i += add_name(&names, names_lines[0], name_i);
        name_i += add_name(&names, names_lines[1], name_i);
        dists_sum += dist;
        if (dists_sum < 0) len_sum_error = 1;
        mx_del_strarr(&names_lines);
        mx_del_strarr(&names_count);
    }
    free(names->data);
    mx_pop_front(&names);
    int names_len = mx_list_size(names);
    if (names_len != *islands_count ||
        dup_isl_error || len_sum_error) {
        mx_del_list(&names, true);
        mx_del_strarr(&lines);
        if (names_len != *islands_count)
            handle_error("error: invalid number of islands\n", NULL, 0);
        else if (dup_isl_error)
            handle_error("error: duplicate bridges\n", NULL, 0);
        else
            handle_error("error: sum of bridges lengths is too big\n", NULL, 0);
    }
    *paths = generate_paths_matrix(names, lines, file_lines_count);
    mx_del_strarr(&lines);
    return names;
}


