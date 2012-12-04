#include "../lib/string_search.h"

int find_char(char *str, char c){
    int i = -1;

    if (str) {
        for (i = 0; *str && *str != c; str++, i++)
            ;

        if (!*str)
            i = -1;
    }
    return i;
}

/* vim: set ts=4:sw=4:et*/
