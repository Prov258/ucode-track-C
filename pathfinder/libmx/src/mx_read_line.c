#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size == 0 || fd < 0) {
        return -2;
    }

    *lineptr = mx_realloc(*lineptr, buf_size);
    mx_memset(*lineptr, '\0', buf_size);
    size_t size = 0;
    char c = '\0';
    int read_res;

    while (1) {
        if (size > buf_size) {
            *lineptr = mx_realloc(*lineptr, size);
        }

        read_res = read(fd, &c, 1);
        if (read_res == 0) {
            return -1;
        }
        if (read_res == -1) {
            return -2;
        }
        if (c == delim || c == '\n') {
            break;
        }

        (*lineptr)[size++] = c;
    }

    *lineptr = mx_realloc(*lineptr, size);
    (*lineptr)[size] = '\0';

    return size;
}


