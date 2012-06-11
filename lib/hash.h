#ifndef __HASH_H__
#define __HASH_H__

#include <stdlib.h>

typedef struct __s_hash_elem {
    void *elem;
    unsigned long int key;
} __t_hash_elem;

typedef struct s_hash_table t_hash;
struct s_hash_table {
    __t_hash_elem *table;
    unsigned long int size;
    unsigned long int numb;
    unsigned long int (*hash_fn)(unsigned long int, t_hash *);
};

void add(void *, unsigned long int, t_hash *);
void empty_hash(t_hash *);
void *get(t_hash *, int);
void hash(unsigned long int, void *);
t_hash *initialize_hash(unsigned long int,
        unsigned long int (*fn)(unsigned long int, t_hash *));
void is_empty(t_hash *);
void is_in_hash(t_hash *, unsigned long int);
void remove(t_hash *, unsigned long int);
void set_hash_function(t_hash *,
        unsigned long int (*fn)(unsigned long int, t_hash *));

#endif
