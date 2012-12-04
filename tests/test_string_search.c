#include "../lib/strsearch.h"
#include "unittest.h"

char text_to_search[47] = "I didn't know you had a cousin Penelope, Bill!";
/* Above text courtesy of fortune */

/* find_string tests */
int test_string_not_in_string(void){
    char find[14] = "Not in string";

    return assert_equal_ints(find_string(text_to_search, find), -1);
}

int test_string_in_string(void){
    char find[7] = "didn't";

    return assert_equal_ints(find_string(text_to_search, find), 2);
}

int test_equal_strings(void){
    return assert_equal_ints(find_string(text_to_search, text_to_search), 0);
}

int test_string_at_beginning_of_string(void){
    char find[9] = "I didn't";

    return assert_equal_ints(find_string(text_to_search, find), 0);
}

/* find_char tests */
int test_char_not_in_string(void){
    return assert_equal_ints(find_char(text_to_search, 'z'), -1);
}

int test_char_in_string(void){
    return assert_equal_ints(find_char(text_to_search, 'a'), 19);
}

int test_char_at_beginning_of_string(void){
    return assert_equal_ints(find_char(text_to_search, 'I'), 0);
}

int test_library_calls(void){
    int count = 0;

    /* find_string tests */
    count += test_string_not_in_string();
    count += test_string_in_string();
    count += test_equal_strings();
    count += test_string_at_beginning_of_string();

    /* find_char tests */
    count += test_char_not_in_string();
    count += test_char_in_string();
    count += test_char_at_beginning_of_string();

    return count;
}

int main(void){
    int count = 0;
    time_t start;
    time_t end;
    double diff;

    setbuf(stdout, NULL); /* Removes any buffering when using printf. */
    puts("--------libstrsearch tests start--------\n");
    start = time(NULL);
    count += test_library_calls();
    puts("\n---------libstrsearch tests end---------");
    puts("------libstrsearch profiling start------\n");
    printf("%d iterations in each test.\n", PROFILE_ITERATIONS);
    puts("\n-------libstrsearch profiling end-------");
    end = time(NULL);
    diff = difftime(end, start);
    printf("Time taken: %fs\n", diff);
    printf("ERRORS: %d\n\n", count);

    return count;
}
