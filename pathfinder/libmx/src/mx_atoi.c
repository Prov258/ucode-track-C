#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int sign = 1;
    long long total = 0;
    int i = 0;

    while(mx_isspace(str[i])) {
        i++;
    }

    if(str[i] == '-') {
        sign = -1;
        i++;
    }

    while(str[i] != '\0') {
        if(!mx_isdigit(str[i])) {
            return 0;
        }

        total = total * 10 + str[i] - '0';

        if (total > 2147483647) {
            return sign == 1 ? 2147483647 : -2147483648;
        }

        i++;
    }

    return (int) (total * sign);
}

