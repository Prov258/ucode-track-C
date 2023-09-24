#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *p = b;

    for (size_t i = 0; i < len; i++) {
        p[i] = (unsigned char) c;
    }

    return b;
}

