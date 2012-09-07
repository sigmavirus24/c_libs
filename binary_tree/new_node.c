#include "../lib/binary_tree.h"

binary_node *new_node(void *value, binary_node *left, binary_node *right){
    binary_node *node;

    if (value) {
        node = (binary_node *)malloc(sizeof(binary_node));
        node->value = value;
        node->l_child = left;
        node->r_child = right;
    }
}
