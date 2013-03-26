#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

typedef struct s_node {
    void *elem;
    struct s_node *next;
} t_node;

void add_elem(void *, t_node **);
void add_node(t_node *, t_node **);
void add_node_at(t_node *, t_node **, int);
void append(t_node *, t_node **);
int count_nodes(t_node *);
void *elem_at(t_node *, int);
void empty_list(t_node **);
t_node *new_node(void *, t_node *);
t_node *node_at(t_node *, int);
void remove_last(t_node **);
void remove_node(t_node **);
void remove_node_at(t_node **, int);
void traverse_list(t_node *, void (*fn)(void *));
t_node *iter_list(t_node **);
t_node *filter_list(t_node *, int (*fn)(void *));

#endif
