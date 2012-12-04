#include "../lib/string_search.h"
#include "unittest.h"

int test_not_in_string(void){
    char find[] = "Not in string";
    char text_to_search[] = "I didn't know you had a cousin Penelope, Bill!";
    /* Above text courtesy of fortune */

    return assert_equal_ints(find_string(text_to_search, find), -1);
}

int test_library_calls(void){
    int count = 0;

    count += test_not_in_string();

    return count;
}

int main(int argc, char **argv){
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
