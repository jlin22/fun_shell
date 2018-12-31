#include <dirent.h>
#include "strmatch.c"

#define SHELLEXIT 1

/* TODO:
    grep
        * make it print out the line number and the line itself
        * use a more efficient algorithm
        * create a regular expression parser
    test programs
    redirection (>, <, and |)
*/

int shell_cd(char **args) {
    if (args[1] != NULL)
        chdir(args[1]);
    else 
        if (chdir(args[1]) != 0)
            fprintf(stderr, "failed to change directory\n");
    return 1;
}

int shell_exit(char **args) {
    exit(SHELLEXIT);
}

int shell_ls(char **args) {
    DIR *dp;
    struct dirent *ep;
    
    if ((dp = opendir("./")) == NULL)
        fprintf(stderr, "failed to open directory");
    else {
        while (ep = readdir(dp))
            printf("%s\n", ep->d_name);
    }
    return 1;
}

int shell_pwd(char **args) {
    char *cwd = malloc(sizeof(char) * (MAXSTR + 1));
    if ((cwd = getcwd(cwd, MAXSTR)) == NULL)
        fprintf(stderr, "failed to get current working directory\n");
    else {
        printf("%s\n", cwd);
        free(cwd);
    }
    return 1;
}

int shell_cat(char **args) {
    int i, c;
    FILE *file;
    
    for (i = 1; args[i] != NULL; i++) {
        if ((file = fopen(args[i], "r")) == NULL)  {
            fprintf(stderr, "failed to open %s\n", args[i]);
            return 2;
        }
        else 
            while ((c = getc(file)) != EOF) 
                putchar(c);
    }
    return 1;
}

int shell_square(char **args) {
    char s[4][5] = {"****", "*  *", "*  *", "****"};
    for (int i = 0; i < 4; i++)
        printf("%s\n", s[i]);
    return 1;
}

int shell_strmatch(char **args) {
    FILE *file;
    int line, i;
    char *substring;

    substring = args[1];

    for (i = 2; args[i] != NULL; i++) {
        if ((file = fopen(args[i], "r")) == NULL)  {
            fprintf(stderr, "failed to open %s\n", args[i]);
            return 2;
        }
        else {
            if ((line = find_str_in_file(substring, args[i])) != -1)
                printf("%s: line %d\n", args[i], line);
        }
   }
   return 1;
}
