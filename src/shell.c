#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

char *read_line(void) {
    // + 1 for '\0'
    char *buf = malloc(sizeof(char) * (BUFSIZE + 1));
    int i, c;
    i = 0;

    if (!buf) {
        fprintf(stderr, "allocation error");
        exit(1);
    }
    
    while (i < BUFSIZE && (c = getchar()) != EOF && c != '\n') 
        *(buf + i++) = c;

    if (i >= BUFSIZE)
        fprintf(stderr, "overflow");
    else
        *(buf + i) = '\0'; 

    return buf;
} 

char **parse_line(char *line) {
    char **tokens = malloc(sizeof(char *) * BUFSIZE);
}
