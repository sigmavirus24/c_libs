#include "../lib/binary_tree.h"

void insert(void *value, binary_node *root, int (*cmp)(void *, void *)){
    if (cmp(root->value, value) > 0) {
        if (root->r_child)
            insert(value, root->r_child, cmp);
        else
            root->r_child = new_node(value, NULL, NULL);
    } else if (cmp(root->value, value) <= 0) {
        if (root->l_child)
            insert(value, root->l_child, cmp);
        else
            root->l_child = new_node(value, NULL, NULL);
    }
}
