#include "../lib/list.h"

void add_node_at(t_node *add, t_node **head, int position){
    /* Add the new node into the list at the specified position. */
    t_node *h;

    if (head && add) {
        if (position <= 0 || !*head) {
            add_node(add, head);
        } else {
            for (h = *head; position > 1 && h->next; position--, h = h->next)
                ;
            add->next = h->next;
            h->next = add;
        }
    }
}

/* vim: set ts=4:sw=4:et*/
