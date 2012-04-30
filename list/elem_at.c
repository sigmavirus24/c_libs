#include "../lib/list.h"

void *elem_at(t_node *head, int position){
    /* Return the element in the node at position */
    if (position >= 0) {
        for (; position && head; head = head->next, position--)
            ;
    }

    if (head)
        return head->elem;

    return NULL;
}

/* vim: set ts=4:sw=4:et*/
