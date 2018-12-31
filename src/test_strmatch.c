#include "strmatch.h"

static void test_str_in_line();
static void test_find_str_in_file();

int main() {
    test_str_in_line();
    //test_find_str_in_file();
}

static void test_str_in_line() {
    printf("%d, ", str_in_line("hello", strlen("hello"), "hello world"));
    printf("should be 1\n");
    printf("%d, ", str_in_line("hello", strlen("hello"), "go to mars"));
    printf("should be 0\n");
}

static void test_find_str_in_file() {
    printf("%d\n", find_str_in_file("main", "main.c"));
}
