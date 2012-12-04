#ifndef __MY_UNITTEST_H__
#define __MY_UNITTEST_H__

/* This is a very lazy way of pulling generic tests out of specific test 
 * files.
 * TODO(Ian) make this into an actual library or just use Google's:
 *   https://meekrosoft.wordpress.com/2009/11/09/unit-testing-c-code-with-the-googletest-framework/
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>

#ifndef PROFILE_ITERATIONS
#define PROFILE_ITERATIONS 50000
#endif

#ifdef VERBOSE
#define OK(a) a
#define FAIL(a) a
#else
#define OK(a) printf(".");
#define FAIL(a) printf("F");
#endif

int _assert_ok(char *func){
    OK(printf("%s: OK\n", func);)
    return 0;
}

int _assert_pointer_mismatch(char *func, void *expected, void *found){
    FAIL(printf("%s: expected: %p, found: %p\n", func, expected, found);)
    return 1;
}

int _assert_pointer_match(char *func, void *expected, void *found){
    FAIL(printf("%s: expected different pointers, found %p == %p.\n", func, 
            expected, found);)
    return 1;
}

int _assert_int_mismatch(char *func, int expected, int found){
    FAIL(printf("%s: expected: %d, found: %d\n", func, expected, found);)
    return 1;
}

int _assert_null_found(char *func){
    FAIL(printf("%s: NULL elem found.\n", func);)
    return 1;
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

int assert_equal_ints(int received, int expected){
    char func[] = "assert_equal_ints";

    if (received == expected)
        return _assert_ok(func);
    else {
        FAIL(printf("%s: Expected %d but received %d.\n", func, expected,
                    received);)
        return 1;
    }
}

#endif /* __MY_UNITTEST_H__ */
