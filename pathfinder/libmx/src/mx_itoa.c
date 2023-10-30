#include "../inc/libmx.h"

char *mx_itoa(int num) {
    char *str = NULL;
    bool isNegative = false;
    int len = 0;

    if (num == 0) {
        return mx_strdup("0");
    }
    if (num == -2147483648) {
        return mx_strdup("-2147483648");
    }
    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    int temp = num;

    while(temp > 0) {
        len++;
        temp /= 10;
    }

    str = mx_strnew(len);
    int i = 0;

    while (num != 0) {
        str[i++] = num % 10 + '0';
        num /= 10;
    }
 
    if (isNegative) {
        str[i++] = '-';
    }
 
    str[i] = '\0';
 
    mx_str_reverse(str);
 
    return str;
}


