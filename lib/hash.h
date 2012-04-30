#ifndef __HASH_H__
#define __HASH_H__

#include <stdlib.h>

typedef struct s_hash {
    void *elem;
} t_hash;

void hash(unsigned long int, t_hash *);
void *hash_elem_at(t_hash *, int);
void add(/* Key, value */);
void find(/* Based on value */);
void get(/* Based on key */);
void remove_if(/* Fn pointer - comparison, removes if fn(void *)->true */);
void is_empty(t_hash);

/* Initialize && teardown */

#endif
