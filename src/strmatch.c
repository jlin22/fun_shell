#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXSTR 1024

int str_in_line(char *substring, char *line) {
    return 0;
}

int find_str_in_file(char *substring, char *filename) {
    FILE *f = fopen(filename, "r");
    char *buffer = (char *)malloc(sizeof(char) * MAXSTR);
    size_t size;
    int line_num = 0;
    while (getline(&buffer, &size, f) != -1) {
        if (str_in_line(substring, buffer))
            return 
        line_num++;  
    }
    
    fclose(f);
    return -1;
}

