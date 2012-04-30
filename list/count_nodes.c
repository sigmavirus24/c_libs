#include "../lib/list.h"

int count_nodes(t_node *head){
    /* Return the length of the list */
    int i = 0;

    if (head) {
        for (; head; head = head->next, i++)
            ;
    }

    return i;
}

/* vim: set ts=4:sw=4:et*/
