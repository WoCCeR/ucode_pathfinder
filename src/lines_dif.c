#include "../inc/pathfinder.h"

int lines_dif(char **b1, char *line2) {
    char **namesCount = mx_strsplit(line2, ',');
    char **bnames = mx_strsplit(namesCount[0], '-');

    int result = 1;

    if ((!mx_strcmp(b1[0], bnames[0]) && !mx_strcmp(b1[1], bnames[1])) ||
        (!mx_strcmp(b1[0], bnames[1]) && !mx_strcmp(b1[1], bnames[0]))) {
        result = 0;
    }

    mx_del_strarr(&namesCount);
    mx_del_strarr(&bnames);

    return result;
}
