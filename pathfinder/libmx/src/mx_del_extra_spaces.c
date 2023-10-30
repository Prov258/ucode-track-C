#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if(str == NULL) {
        return NULL;
    }

    int new_len = 0;
    char *temp = mx_strtrim(str);

    for(int i = 0; i < mx_strlen(temp); i++) {
        if(mx_isspace(temp[i]) && !mx_isspace(temp[i - 1])) {
            new_len++;
        }
        if(!mx_isspace(temp[i])) {
            new_len++;
        }
    }

    char *result = mx_strnew(new_len);
    int j = 0;

    for(int i = 0; i < mx_strlen(temp); i++) {
        if(mx_isspace(temp[i]) && !mx_isspace(temp[i - 1])) {
            result[j] = ' ';
            j++;
        }
        if(!mx_isspace(temp[i])) {
            result[j] = temp[i];
            j++;
        }
    }

    mx_strdel(&temp);
    return result;
}

