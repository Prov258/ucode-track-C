#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) {
        return NULL;
    }

    int substr_count = mx_count_substr(str, sub);
    int len = mx_strlen(str) - substr_count
              * mx_strlen(sub) + substr_count
              * mx_strlen(replace);
    
    char *new_str = mx_strnew(len);
    char *result = new_str;

    char *substr = mx_strstr(str, sub);
    while(mx_strcmp(substr, "\0") != 0) {
        mx_strncpy(new_str, str, substr - str);
        new_str += substr - str;

        mx_strcat(new_str, replace);
        new_str += mx_strlen(replace);

        str = substr + mx_strlen(replace);
        substr = mx_strstr(str, sub);
    }

    return result;
}


