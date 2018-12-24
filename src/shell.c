#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BASE_BUF 1024

void shell_loop(void) {

}

void resize(char *buffer, int new_size) {
    buffer = realloc(buffer, new_size);
    if (buffer == NULL) {
        fprintf(stderr, "allocation error\n");
        exit(1);
    }
}

char *read_line(void) {
    char *buffer;
    int c, index, current_size;
    current_size = BASE_BUF;
    buffer = (char *)malloc(BASE_BUF * sizeof(char));
    index = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        *(buffer + index++) = c;
        /*Double size if necessary*/
        if (index >= current_size) {
            current_size *= 2;
            resize(buffer, current_size);
        } 
    }
    *(buffer + index) = '\0';
}

char **split_line(char *line) {
    /*Array of char*, each string length BASE_BUF, and array length sizeof(char*))*/
    char **tokens = malloc(BASE_BUF * sizeof(char *));
    char *current = malloc(BASE_BUF * sizeof(char));

    while (*line) {
        if (isspace(*line));
            line++;
    }
}
