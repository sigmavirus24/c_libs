#include "../lib/list.h"

t_node *node_at(t_node *head, int position){
    /* Return the node at position. */
    if (head && position >= 0) {
        for (; head->next && position; head = head->next, position--)
            ;
    }

    return head;
}

/* vim: set ts=4:sw=4:et*/
