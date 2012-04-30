#include "../lib/list.h"

void empty_list(t_node **head){
    /* Clear out the list in use. */
    while (head && *head)
        remove_node(head);
}

/* vim: set ts=4:sw=4:et*/
