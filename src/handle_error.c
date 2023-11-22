#include "../inc/pathfinder.h"

void handle_error(char * error_message, char * replacement, int free_replacement) {

    if (replacement) {
        char * new_message = mx_replace_substr(error_message, "?", replacement);
        if (free_replacement) free(replacement);
        mx_printerr(new_message);
        free(new_message);
    } else {
        mx_printerr(error_message);
    }
    exit(0);
}
