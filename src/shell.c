#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isspace
#include <unistd.h> // for exec
#include <sys/types.h> // for fork
#include <sys/wait.h> // for waitpid
#include "builtins.h"

#define MAXTOKENS 1024
#define TRUE 1
#define FALSE 0
#define BUFFERERROR 2
#define CHILDSTATUS 3

static void append(char **tokens, int token_index, char *line);
static char* slice(char *line, int start, int end);

char *read_line(void) {
    char *buf = malloc(sizeof(char) * (MAXSTR + 1));
    int i, c;
    i = 0;

    if (!buf) {
        fprintf(stderr, "allocation error");
        exit(BUFFERERROR);
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

int launch_shell(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) { // child
        if (execvp(args[0], args) == -1)
            fprintf(stderr, "shell failed to run");
        exit(CHILDSTATUS);
    }
    else if (pid < 0) 
        fprintf(stderr, "failed to fork");
    else { // parent
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

int shell_execute(char **args) {
    int i;

    if (args[0] == NULL)
        return 1;

    for (i = 0; i < num_builtins; i++)
        if (strcmp(args[0], builtin_str[i]) == 0)
            return (*builtin_func[i])(args);

    return launch_shell(args);
}

void shell_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("$ ");
        line = read_line();
        args = parse_line(line);
        status = shell_execute(args);
        free(line);
        free(args);
    } while (status);
}
