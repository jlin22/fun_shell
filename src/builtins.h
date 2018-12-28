#include "builtins.c"

#define num_builtins sizeof(builtin_str) / sizeof(char *)

char *builtin_str[] = {
    "cd",
    "exit",
    "ls"
};

int shell_cd(char **args);
int shell_exit(char **args);
int shell_ls(char **args);

int (*builtin_func[])(char **) = {
    &shell_cd,
    &shell_exit,
    &shell_ls
};


