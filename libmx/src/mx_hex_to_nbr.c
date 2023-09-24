#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if(hex == NULL) {
        return 0;
    }

    unsigned long result = 0;
    int len = 0;

    for(int i = 0; hex[i] != '\0'; i++) {
        len++;
    }

    for(int i = 0; i < len; i++) {
        unsigned long base = 1;

        for(int j = 1; j < len - i; j++) {
            base *= 16;
        }

        if(hex[i] >= '0' && hex[i] <= '9') {
            result += (hex[i] - '0') * base;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'z') {
            result += (hex[i] - 'a' + 10) * base;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'Z') {
            result += (hex[i] - 'A' + 10) * base;
        }

        if(!(hex[i] >= 'A' && hex[i] <= 'Z') && !(hex[i] >= 'a' && hex[i] <= 'z') && !(hex[i] >= '0' && hex[i] <= '9')) {
            return 0;
        }
    }

    return result;
}


