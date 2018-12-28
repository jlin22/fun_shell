#define SHELLEXIT 1
#define MAXSTR 1024

int shell_cd(char **args) {
    if (args[1] != NULL)
        chdir(args[1]);
    else 
        if (chdir(args[1]) != 0)
            fprintf(stderr, "failed to change directory\n");
    return 0;
}

int shell_exit(char **args) {
    exit(SHELLEXIT);
}

int shell_ls(char **args) {
    return 0; 
}

int shell_pwd(char **args) {
    char *cwd = malloc(sizeof(char) * (MAXSTR + 1));
    if ((cwd = getcwd(cwd, MAXSTR)) == NULL)
        fprintf(stderr, "failed to get current working directory\n");
    else
        printf("%s\n", cwd);
    return 0;
}
