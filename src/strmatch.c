#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXSTR 1024

int str_in_line(char *substring, int substrlen, char *line) {
    int i, j, same;
    for (i = 0; line[i + substrlen] != '\0'; i++)
        same = 1;
        for (j = 0; j < substrlen; j++)
            if (line[i+j] != substring[j]) {
                same = 0;
                break;
            }
        if (same == 1)
            return 1;
    return 0;
}

int find_str_in_file(char *substring, char *filename) {
    FILE *f = fopen(filename, "r");
    char *buffer = (char *)malloc(sizeof(char) * MAXSTR);
    size_t size;
    int line_num, substrlen;
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

