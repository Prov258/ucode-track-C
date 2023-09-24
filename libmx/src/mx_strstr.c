#include "../inc/libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    char *a = mx_strchr(s1, s2[0]);

    while(*a != '\0') {
        if(mx_strncmp(a, s2, mx_strlen(s2)) == 0) {
            return a;
        }

        a = mx_strchr(a + 1 , s2[0]);
    }

    return a;
}

