#include "../lib/list.h"

void remove_node_at(t_node **head, int position){
    /* Removes item at position from the list */
    t_node *h, *p;

    if (head && *head) {
        if (position <= 0)
            remove_node(head);
        else {
            for (h = *head; h->next->next && position > 1; h = h->next, position--)
                ;
            p = h->next; /* Item to be removed. */
            h->next = p->next;
            free(p);
        }
    }
}

/* vim: set ts=4:sw=4:et*/
