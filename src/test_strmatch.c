#include "strmatch.h"

static void test_str_in_line();
static void test_find_str_in_file();

int main() {
    test_str_in_line();
    test_find_str_in_file();
}

static void test_str_in_line() {
    printf("%d, should be 1\n", str_in_line("hello", strlen("hello"), "hello world"));
    printf("%d, should be 0\n", str_in_line("hello", strlen("hello"), "go to mars"));
}

static void test_find_str_in_file() {
    printf("%d, should be 2\n", find_str_in_file("main", "main.c"));
    printf("%d, should be -1\n", find_str_in_file("python", "main.c"));
}
