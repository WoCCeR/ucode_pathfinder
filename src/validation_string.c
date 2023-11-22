#include "../inc/pathfinder.h"

int validation_string(char *str, char delimiter, int endChar) {
    int cnt = 0;

    if (!mx_isalpha(str[0])) {
        return 0;
    }

    for (int i = 0; str[i] != endChar; i++) {
        if (str[i] == delimiter) {
            cnt++;
        }

        if (!mx_isalpha(str[i]) && !mx_isalpha(str[i + 1])) {
                return 0;
        }
    }

    if (cnt != 1) {
        return 0;
    }

    return 1;
}
