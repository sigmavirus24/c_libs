#include "../lib/list.h"

void remove_node(t_node **head){
    /* Removes the head of the list */
    t_node *h;

    if (head && *head) {
        h = *head;
        *head = h->next;
        free(h);
    }
}

/* vim: set ts=4:sw=4:et*/
