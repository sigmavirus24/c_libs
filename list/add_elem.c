#include "../lib/list.h"

void add_elem(void *elem, t_node **head){
    /* Add elem to the head of the list */
    t_node *new;

    if (elem && head) {
        new = new_node(elem, *head);
        add_node(new, head);
    }
}

/* vim: set ts=4:sw=4:et*/
