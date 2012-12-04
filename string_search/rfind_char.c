#include "../lib/strsearch.h"

/* str must be malloc'd */
int rfind_char(char *str, char c){
    int i = -1;

    if (str) {
        for (i = *(&str + 1) - str - 1; i >= 0 && str[i] != c; i--)
            ;
    }

    return i;
}

/* vim: set ts=4:sw=4:et*/
