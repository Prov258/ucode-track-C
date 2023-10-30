#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) {
        return -2;
    }

    char *test = mx_strstr(str, sub);
    
    if (mx_strcmp(test, "\0") == 0) {
        return -1;
    }

    return (test - str) / sizeof(char);
}

