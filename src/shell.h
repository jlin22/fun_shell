#include "shell.c"

void shell_loop(void);
char *read_line(void);
char **parse_line(char *line);
int launch_shell(char **args);
int shell_execute(char **args);
void print_home(void);
