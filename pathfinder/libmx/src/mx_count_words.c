#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    if (str == NULL) {
        return -1;
    }

    int count = 0;
    int is_blank = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter && is_blank == 0) {
            count++;
            is_blank = 1;
        }
        else if (str[i] != delimiter && is_blank == 1) {
            is_blank = 0;
        }
    }

    if (is_blank == 0) {
        count++;
    }

    return count;
}

