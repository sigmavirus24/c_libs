#include "../lib/strsearch.h"

int rfind_char(char *str, char c){
    int i;
    int max = -1;
    int len;

    /*
    if (str) {
        for (i = *(&str + 1) - str - 1; i >= 0 && str[i] != c; i--)
            ;
    }
    */

    if (str) {
        len = strlen(str);
        for (i = 0, max = 0; i < len; i++)
            if (str[i] == c)
                max = i;
    }
    return max;
}

/* vim: set ts=4:sw=4:et*/
