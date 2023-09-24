#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    int new_len = len1 + len2;    

    for (int i = 0; i < len2; i++) {
        s1[len1 + i] = s2[i];
    }

    s1[new_len] = '\0';

    return s1;
}

