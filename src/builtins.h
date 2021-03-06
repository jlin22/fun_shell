#include "builtins.c"

#define num_builtins sizeof(builtin_str) / sizeof(char *)
#define shell_func(cmd) shell_ ## cmd

char *builtin_str[] = {
    "cd",
    "exit",
    "ls",
    "pwd",
    "square",
    "cat",
    "strmatch"
};

int shell_cd(char **args);
int shell_exit(char **args);
int shell_ls(char **args);
int shell_pwd(char **args);
int shell_cat(char **args);
int shell_square(char **args);
int shell_strmatch(char **args);

int (*builtin_func[])(char **) = {
    shell_cd,
    shell_exit,
    shell_ls,
    shell_pwd,
    shell_square,
    shell_cat,
    shell_strmatch
};
