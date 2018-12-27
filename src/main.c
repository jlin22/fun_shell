#include <string.h>
#include "shell.h"

int main() {
    char *c = read_line();
    printf("%s\n", c);
    char **tokens = parse_line(c);
    for (int i = 0; tokens[i]; i++)
        printf("%s\n", tokens[i]); 
    return 0;
}
