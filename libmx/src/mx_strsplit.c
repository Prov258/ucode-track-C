#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
    if(s == NULL) {
        return NULL;
    }

    int arr_len = mx_count_words(s, c);
    char **arr = (char **) malloc(sizeof(char *) * (arr_len + 1));
    int j = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] != c) {
            int start = i;
            int len = 1;

            while(s[i + 1] != c && s[i + 1] != '\0') {
                len++;
                i++;
            }

            char *str = mx_strnew(len);
            mx_strncpy(str, s + start, len);
            arr[j] = str;
            j++;
        }
    }

    arr[j] = NULL;
    return arr;
}

