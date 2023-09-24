#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (!str) {
        return NULL;
    }

    int i = 0;
    int beginning_spaces = 0;
    int end_spaces = 0;

    while(mx_isspace(str[i])) {
        beginning_spaces++;
        i++;
    }

    i = mx_strlen(str) - 1;

    while(mx_isspace(str[i])) {
        end_spaces++;
        i--;
    }

    int new_len = mx_strlen(str) - beginning_spaces - end_spaces;
    char *new_string = mx_strnew(new_len);

    mx_strncpy(new_string, str + beginning_spaces, new_len);

    return new_string;
}

