#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int i = 0;
    int hex_len = 0;
    unsigned long temp = nbr;

    while (temp > 0)
    {
        hex_len++;
        temp /= 16;
    }

    char *hex_string = mx_strnew(hex_len);

    if (hex_string == NULL)
    {
        return NULL;
    }

    while (nbr > 0)
    {
        int remainder = nbr % 16;

        if(remainder < 10) {
            hex_string[i++] = remainder + 48;
        }
        else {
            hex_string[i++] = remainder - 10 + 97;
        }

        nbr /= 16;
    }

    hex_string[i] = '\0';

    for (int j = 0; j < hex_len / 2; j++)
    {
        char temp = hex_string[j];
        hex_string[j] = hex_string[hex_len - j - 1];
        hex_string[hex_len - j - 1] = temp;
    }

    return hex_string;
}

