#define SHELLEXIT 1

int shell_cd(char **args) {
    if (args[1] != NULL)
        chdir(args[1]);
    else 
        if (chdir(args[1]) != 0)
            fprintf(stderr, "failed to change directory");
    return 1;
}

int shell_exit(char **args) {
    exit(SHELLEXIT);
}

