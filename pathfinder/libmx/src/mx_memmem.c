#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (little_len <= 0 || big_len <= 0 || little_len > big_len) {
        return NULL;
    }

    unsigned char *haystack = (unsigned char *) big;
    unsigned char *needle = (unsigned char *) little;
    unsigned char *s = mx_memchr(haystack, needle[0], big_len);

    while (s != NULL) {
        if (mx_memcmp(s, needle, little_len) == 0) {
            return s;
        }

        haystack = s + 1;
        big_len -= haystack - (s + 1);
        s = mx_memchr(haystack, needle[0], big_len);
    }

    return NULL;
}

