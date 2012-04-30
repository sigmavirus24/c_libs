#include "../lib/list.h"

void append(t_node *add, t_node **head){
    /* Add the node at the end of the list. */
    static t_node *last = NULL;
    /* Last saves the last node that was added to make appending to the list
     * faster. If you have a huge list, this saves a lot of time.
     */
    t_node *h;

    if (head) {
        if (*head) {
            if (!last) {
                for (h = *head; h->next; h = h->next)
                    ;
                last = h;
            }
            last->next = add;
            last = add;
        } else {
            *head = add;
        }
    }
}

/* vim: set ts=4:sw=4:et*/
