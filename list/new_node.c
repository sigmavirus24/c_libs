#include "../lib/list.h"

t_node *new_node(void *elem, t_node *next){
    /* Create a new node and return its pointer */
    t_node *new = NULL;

    if (elem) {
        new = (t_node *)malloc(sizeof(t_node));
        new->elem = elem;
        new->next = next;
    }

    return new;
}

/* vim: set ts=4:sw=4:et*/
