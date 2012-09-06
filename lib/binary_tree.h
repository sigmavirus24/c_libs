#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef struct __bin_tree_node binary_node;
struct __bin_tree_node {
    void *value;
    binary_node *l_child;
    binary_node *r_child;
};

void insert(void *, binary_node **);
int search(void *, binary_node *, int (*cmp)(void *, void *));
void bfs_walk(binary_node *, void (*print)(void *));
void dfs_walk(binary_node *, void (*print)(void *));
void in_order(binary_node *, void (*print)(void *));
void pre_order(binary_node *, void (*print)(void *));
void post_order(binary_node *, void (*print)(void *));

#endif /* __BINARY_TREE_H__ */
