#include "../lib/list.h"

void add_node(t_node *add, t_node **head){
    /* Add a new node at the head of the list. */
    if (add && head) {
        add->next = *head;
        *head = add;
    }
}

/* vim: set ts=4:sw=4:et*/
