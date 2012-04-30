#include "../lib/list.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#ifndef PROFILE_ITERATIONS
#define PROFILE_ITERATIONS 500000
#endif

int _assert_ok(char *func){
    printf("%s: OK\n", func);
    return 0;
}

int _assert_pointer_mismatch(char *func, void *expected, void *found){
    printf("%s: expected: %p, found: %p\n", func, expected, found);
    return 1;
}

int _assert_pointer_match(char *func, void *expected, void *found){
    printf("%s: expected different pointers, found %p == %p.\n", func, 
            expected, found);
    return 1;
}

int _assert_int_mismatch(char *func, int expected, int found){
    printf("%s: expected: %d, found: %d\n", func, expected, found);
    return 1;
}

int _assert_null_found(char *func){
    printf("%s: NULL elem found.\n", func);
    return 1;
}

int assert_list_length(t_node *list, int length){
    int count = count_nodes(list);
    char func[] = "assert_list_length";

    if (length == count)
        return _assert_ok(func);
    else
        return _assert_int_mismatch(func, length, count);
}

int assert_equal_int(void *elem, int expected){
    int *e;
    char func[] = "assert_equal_int";

    if (elem) {
        e = (int *)elem;
        if (expected == *e)
            return _assert_ok(func);
        else
            return _assert_int_mismatch(func, expected, *e);
    } else {
        return _assert_null_found(func);
    }
}

int assert_null(void *p){
    char func[] = "assert_null";

    if (!p)
        return _assert_ok(func);
    else
        return _assert_pointer_mismatch(func, NULL, p);
}

int assert_not_null(void *p){
    char func[] = "assert_not_null";

    if (p)
        return _assert_ok(func);
    else
        return _assert_null_found(func);
}

int assert_equal_node(t_node *found, t_node *expected){
    char func[] = "assert_equal_node";

    if (found && expected) {
        if (found == expected)
            return _assert_ok(func);
        else
            return _assert_pointer_mismatch(func, expected, found);
    } else {
        return _assert_null_found(func);
    }
}

int assert_not_equal_node(t_node *found, t_node *expected){
    char func[] = "assert_not_equal_node";
    
    if (found && expected) {
        if (found != expected)
            return _assert_ok(func);
        else
            return _assert_pointer_match(func, expected, found);
    } else {
        return _assert_null_found(func);
    }
}

void dump_elem_int(void *elem){
    int *e;

    if (elem) {
        e = (int *)elem;
        printf("%d\n", *e);
    }
}

int test_library_calls(void){
    int tmp = 0;
    int count = 0;
    t_node *head = NULL;
    t_node *node = NULL;

    count += assert_list_length(head, 0);
    /* Start add and new_node functions */
    /* Test add_elem with a NULL head */
    add_elem(&tmp, &head); /* Length = 1 */
    count += assert_list_length(head, 1);
    count += assert_equal_int(elem_at(head, 0), tmp);
    /* Test add_elem with a non-NULL head */
    add_elem(&tmp, &head); /* Length = 2 */
    count += assert_list_length(head, 2);
    node = new_node(&tmp, NULL);
    count += assert_list_length(node, 1);
    count += assert_equal_int(elem_at(node, 0), tmp);
    /* Test append with a non-NULL head */
    append(node, &head); /* Length = 3 */
    count += assert_list_length(head, 3);
    count += assert_equal_int(elem_at(head, 2), tmp);
    count += assert_equal_node(node_at(head, 2), node);
    count += assert_null(elem_at(head, 3));
    count += assert_not_null(node_at(head, 3));
    node = new_node(&tmp, NULL);
    /* Test add_node with a non-NULL head */
    add_node(node, &head); /* Length = 4 */
    count += assert_equal_node(head, node);
    count += assert_list_length(head, 4);
    node = new_node(&tmp, NULL);
    /* Test add_node_at with a non-NULL head */
    add_node_at(node, &head, 2); /* Length = 5 */
    count += assert_list_length(head, 5);
    count += assert_equal_node(node_at(head, 2), node);
    /* Make sure nothing is printed. */
    traverse_list(head, NULL);
    traverse_list(NULL, dump_elem_int);
    /* Test remove_node with NULL */
    node = NULL;
    remove_node(&node);
    /* Test remove_node with non-NULL list */
    node = head;
    remove_node(&head); /* Length = 4 */
    count += assert_not_equal_node(head, node);
    count += assert_list_length(head, 4);
    /* Test remove_node_at with non-NULL list and positive position */
    node = node_at(head, 2);
    remove_node_at(&head, 2); /* Length = 3 */
    count += assert_not_equal_node(node_at(head, 2), node);
    count += assert_list_length(head, 3);
    /* Test remove_last with non-NULL list */
    node = node_at(head, 2);
    remove_last(&head); /* Length = 2 */
    count += assert_not_equal_node(node_at(head, 2), node);
    count += assert_list_length(head, 2);
    /* Test remove_node_at with non-NULL list and negative position */
    node = head;
    remove_node_at(&head, -1); /* Length = 1 */
    count += assert_not_equal_node(head, node);
    count += assert_list_length(head, 1);
    /* Clean-up */
    empty_list(&head);
    /* Assert that the clean-up worked */
    count += assert_list_length(head, 0);
    head = NULL;
    /* Test remove_node with NULL list */
    remove_node(&head);
    /* Test remove_node_at with NULL list */
    remove_node_at(&head, 2);
    /* Test remove_last with NULL list */
    remove_last(&head);
    /* Test add_node with NULL head */
    node = new_node(&tmp, NULL);
    add_node(node, &head); /* Length = 1 */
    count += assert_list_length(head, 1);
    count += assert_equal_node(head, node);
    /* Test remove_last on singleton list */
    remove_last(&head);
    count += assert_list_length(head, 0);
    /* Test add_node_at with NULL list. */
    node = new_node(&tmp, NULL);
    add_node_at(node, &head, 2);
    count += assert_list_length(head, 1);
    /* Test add_node_at with negative index */
    node = new_node(&tmp, NULL);
    add_node_at(node, &head, -1);
    count += assert_list_length(head, 2);
    count += assert_equal_node(head, node);
    /* Test add_node_at with ridiculously large index */
    node = new_node(&tmp, NULL);
    add_node_at(node, &head, 100);
    count += assert_list_length(head, 3);
    count += assert_equal_node(node_at(head, 2), node);
    count += assert_equal_node(node_at(head, 20), node);
    empty_list(&head);

    return count;
}

void _profile_info(char *func, double seconds, double sec_per_iter){
    printf("%13s: %14.9f seconds, %14.9f seconds/iteration\n", func, seconds,
            sec_per_iter);
}

void profile_add_elem(void){
    time_t start;
    time_t end;
    double diff;
    int i;
    t_node *head = NULL;

    start = time(NULL);
    for (i = 0; i < PROFILE_ITERATIONS; i++)
        add_elem(&i, &head);
    end = time(NULL);
    diff = difftime(end, start);
    _profile_info("add_elem", diff, diff/PROFILE_ITERATIONS);
    empty_list(&head);
}

void profile_add_node(void){
    time_t start;
    time_t end;
    double diff;
    int i;
    t_node *head = NULL;
    t_node *node = NULL;

    start = time(NULL);
    for (i = 0; i < PROFILE_ITERATIONS; i++) {
        node = new_node(&i, NULL);
        add_node(node, &head);
    }
    end = time(NULL);
    diff = difftime(end, start);
    _profile_info("add_node", diff, diff/PROFILE_ITERATIONS);
    empty_list(&head);
}

void profile_add_node_at(void){
    time_t start;
    time_t end;
    double diff;
    int i;
    t_node *head = NULL;
    t_node *node = NULL;

    for (i = 0; i < PROFILE_ITERATIONS; i++) {
        node = new_node(&i, NULL);
        append(node, &head);
    }

    start = time(NULL);
    for (i = 0; i < PROFILE_ITERATIONS; i++) {
        node = new_node(&i, NULL);
        add_node_at(node, &head, i);
    }
    end = time(NULL);
    diff = difftime(end, start);
    _profile_info("add_node_at", diff, diff/PROFILE_ITERATIONS);
    empty_list(&head);
}

void profile_append(void){
    time_t start;
    time_t end;
    double diff;
    int i;
    t_node *head = NULL;
    t_node *node = NULL;

    start = time(NULL);
    for (i = 0; i < PROFILE_ITERATIONS; i++) {
        node = new_node(&i, NULL);
        append(node, &head);
    }
    end = time(NULL);
    diff = difftime(end, start);
    _profile_info("append", diff, diff/PROFILE_ITERATIONS);
    empty_list(&head);
}

void profile_elem_at(void){
    time_t start;
    time_t end;
    double diff;
    int i;
    t_node *head = NULL;
    t_node *node = NULL;

    /* Build list for testing on */
    for (i = 0; i < PROFILE_ITERATIONS; i++) {
        node = new_node(&i, NULL);
        append(node, &head);
    }

    start = time(NULL);
    for (i = 0; i < PROFILE_ITERATIONS; i++) {
        (void)elem_at(head, i);
    }
    end = time(NULL);
    diff = difftime(end, start);
    _profile_info("elem_at", diff, diff/PROFILE_ITERATIONS);
    empty_list(&head);
}

int main(int argc, char **argv){
    int count = 0;
    time_t start;
    time_t end;
    double diff;
    
    setbuf(stdout, NULL); /* Removes any buffering when using printf. */
    puts("--------liblist tests start--------\n");
    start = time(NULL);
    count += test_library_calls();
    puts("\n---------liblist tests end---------");
    puts("------liblist profiling start------\n");
    printf("%d iterations in each test.\n", PROFILE_ITERATIONS);
    profile_add_elem();
    profile_add_node();
    profile_add_node_at();
    profile_append();
    profile_elem_at();
    puts("\n-------liblist profiling end-------");
    end = time(NULL);
    diff = difftime(end, start);
    printf("Time taken: %fs\n", diff);
    printf("ERRORS: %d\n\n", count);

    return count;
}
