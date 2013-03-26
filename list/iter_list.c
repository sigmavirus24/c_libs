#include "../lib/list.h"

t_node *iter_list(t_node **head){
    t_node *tmp = NULL;
    if (head && *head) {
        tmp = *head;
        *head = (*head)->next;
    }
    return tmp;
}
