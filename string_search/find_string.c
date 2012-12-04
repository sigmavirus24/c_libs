#include "../lib/strsearch.h"

int find_string(char *str, char *find){
    int find_len;
    int str_len;
    int pos = -1;
    int i;
    char *p;

    if (str && find) {
        find_len = strlen(find);
        str_len = strlen(str);

        if (find_len <= str_len) {
            p = str + find_len - 1;
            pos = find_len - 1;

            while (pos < str_len) {
                if (*p == *(find + find_len - 1)) {
                    i = find_len - 1;

                    for (; (i > 0) && (*(p--) == *(find + i)); i--)
                        ;

                    if (!i && *p == *find)
                        break;
                } else
                    i = rfind_char(find, *p);

                pos += (i < 0) ? find_len : find_len - (i + 1);
                p = str + pos;
            }

            if (pos > str_len)
                pos = -1;
            else
                pos -= find_len - 1;

        } else if (find_len == str_len) {
            if (!strcmp(str, find))
                pos = 0;
        }
    }

    return pos;
}


/* This is an implementation of the the Boyer-Moore fast string search. This
 * library is excerpted from the work I did on the No Agenda Bat Signal. This
 * code was originally licensed under the GPLv2 so the licensing is no issue.
 */

/* vim: set ts=4:sw=4:et*/
