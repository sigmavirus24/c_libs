#include "../lib/list.h"

t_node *filter_list(t_node *head, int (*fn)(void *)){
    t_node *new_list = NULL;

    if (!fn)
        return NULL;

    for (; head; head = head->next) {
        if (fn(head->elem)) {
            append(new_node(head->elem, NULL), &new_list);
        }
    }
    return new_list;
}
