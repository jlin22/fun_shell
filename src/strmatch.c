#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXSTR 1024
#define EXISTS 1

int str_in_line(char *substring, int substrlen, char *line) {
    int i, j, same;
    for (i = 0; line[i + substrlen] != '\0'; i++) {
        same = 1;
        for (j = 0; j < substrlen && same != 0; j++)
            same &= (line[i + j] == substring[j]);
        if (same == 1)
            return EXISTS;
    }
    return !EXISTS;
}

//Returns the line, -1 if it doesn't exist
int find_str_in_file(char *substring, char *filename) {
    FILE *f;
    char *buffer;
    size_t size;
    int line_num, substrlen;

    f = fopen(filename, "r");
    buffer = (char *)malloc(sizeof(char) * MAXSTR);
    line_num = 0;
    substrlen = strlen(substring);

    while (getline(&buffer, &size, f) != -1) {
        if (str_in_line(substring, substrlen, buffer))
            return line_num;
        line_num++;  
    }
    
    fclose(f);
    return -1;
}

