#include "../lib/list.h"

void traverse_list(t_node *head, void (*fn)(void *)){
    /* Traverses the list and prints out the value of elem using fn */
    if (head && fn) {
        for (; head; head = head->next)
            fn(head->elem);
    }
}

/* vim: set ts=4:sw=4:et*/
