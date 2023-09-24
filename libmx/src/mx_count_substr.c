#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -1;
    }
    if (mx_strlen(sub) == 0) {
        return 0;
    }

    int count = 0;
    char *a = mx_strstr(str, sub);

    while (*a != '\0') {
        count++;
        a = mx_strstr(a + mx_strlen(sub), sub);
    }

    return count;
}

