#include "../lib/list.h"

void remove_last(t_node **head){
    /* Removes the tail from the list */
    t_node *h;

    if (head && *head) {
        for (h = *head; h->next && h->next->next; h = h->next)
            ;
        if (h->next) {
            free(h->next);
            h->next = NULL;
        } else if (h == *head) {
            free(h);
            *head = NULL;
        }
    }
}

/* vim: set ts=4:sw=4:et*/
