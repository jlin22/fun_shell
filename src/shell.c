#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTR 1024
#define MAXTOKENS 1024
#define TRUE 1
#define FALSE 0

static void append(char **tokens, int token_index, char *line);
static char* slice(char *line, int start, int end);

char *read_line(void) {
    char *buf = malloc(sizeof(char) * (MAXSTR + 1));
    int i, c;
    i = 0;

    if (!buf) {
        fprintf(stderr, "allocation error");
        exit(1);
    }
    
    while (i < MAXSTR && (c = getchar()) != EOF && c != '\n') 
        *(buf + i++) = c;

    if (i >= MAXSTR)
        fprintf(stderr, "overflow");
    else
        *(buf + i) = '\0'; 

    return buf;
} 

char **parse_line(char *line) {
    char **tokens = malloc(sizeof(char *) * (MAXTOKENS + 1));
    int in_space = TRUE;
    int i, token_start, token_index;
    token_index = 0;
    
    for (i = 0; line[i] != '\0'; i++) {
        if (in_space && !isspace(line[i])) {
            in_space = FALSE;
            token_start = i; 
        }
        else if (!in_space && isspace(line[i])) {
            append(tokens, token_index++, slice(line, token_start, i));
            in_space = TRUE;
        }
    }
    if (!in_space)
        append(tokens, token_index++, slice(line, token_start, i+1));

    append(tokens, token_index++, NULL);
        
    return tokens;
}

static void append(char **tokens, int token_index, char *line) {
    tokens[token_index] = line;
}

static char* slice(char *line, int start, int end) {
    char *s = malloc(sizeof(char) * MAXSTR);
    for (int i = start; i < end; i++)
        s[i - start] = line[i]; 
    s[end] = '\0';
    return s;
}
