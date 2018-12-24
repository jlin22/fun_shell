#include <stdio.h>
#include "shell.h"

int main() {
    char *c = read_line();
    printf("%s\n", c);
    return 0;
}
