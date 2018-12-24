#include <stdio.h>
#include <stdlib.h>

#define BASE_BUF 64

void shell_loop(void) {

}

void resize(char *buffer, int new_size) {
    buffer = realloc(buffer, new_size);
    if (buffer == NULL) {
        fprintf(stderr, "allocation error\n");
        exit(1);
    }
}
char * read_line(void) {
    char *buffer;
    int c, index, current_size;
    current_size = 1024;
    buffer = (char *)malloc(BASE_BUF * sizeof(char));
    index = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        /*Double size if necessary*/
        if (index >= current_size) {
            current_size *= 2;
            resize(buffer, current_size);
        } 
        *(buffer + index++) = c;
    }
}
