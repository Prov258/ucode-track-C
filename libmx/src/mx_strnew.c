#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    if(size < 0) {
        return NULL;
    }

    char *new_string = (char *) malloc(sizeof(char) * (size + 1));

    if(new_string == NULL) {
        return new_string;
    }

    for(int i = 0; i <= size; i++) {
        new_string[i] = '\0';
    }

    return new_string;
}

