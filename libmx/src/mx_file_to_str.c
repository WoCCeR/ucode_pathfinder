#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        return NULL;
    }

    char *str = NULL;
    size_t file_size = 0;
    size_t buffer_size = 1024;

    while (1) {
        if (file_size + buffer_size > file_size) {
            buffer_size *= 2;
            str = mx_realloc(str, buffer_size);
            if (str == NULL) {
                close(fd);
                return NULL;
            }
        }

        ssize_t bytes_read = read(fd, str + file_size, buffer_size - file_size);
        if (bytes_read == -1) {
            mx_strdel(&str);
            close(fd);
            return NULL;
        }

        if (bytes_read == 0) {
            str[file_size] = '\0';
            break;
        }

        file_size += bytes_read;
    }

    close(fd);

    return str;
}
