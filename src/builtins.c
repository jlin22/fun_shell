int shell_cd(char **args) {
    if (args[1] != 0)
        if (chdir("~") != 0)
            fprintf(stderr, "failed to change directory");
    else 
        if (chdir(args[1]) != 0)
            fprintf(stderr, "failed to change directory");
    return 1;
}

int shell_exit(char **args) {
    return 1;
}

