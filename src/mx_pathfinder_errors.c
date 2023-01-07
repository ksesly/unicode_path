#include "../inc/pathfinder.h"

void mx_firstline_error(int file) {
    mx_printerr("error: line 1 is not valid\n");
    close(file);
    exit(1);
}

void mx_error_line(int str) {
    mx_printerr("error: line");
    char* line = mx_itoa(str);
    mx_printerr(line + 1);
    //mx_strdel(&line);
    mx_printerr(" is not valid\n");
    exit(1);
}

//remake
void mx_dup_error(char **file_lines, int lines_count) {

    char **temp = (char **)malloc((lines_count + 1) * sizeof(char *));
    for (int i = 0; i < lines_count; i++) {
        temp[i] = mx_strndup(file_lines[i], mx_get_char_index(file_lines[i], ','));
    }
    temp[lines_count] = NULL;
    
    for (int i = 0; i < lines_count; i++) {
        for (int j = 0; j < lines_count; j++) {
            if (temp[j][0] == '\0' || j == i) {
                continue;
            }
            if (mx_strcmp(temp[i], temp[j]) == 0) {
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }    
        }
    }

    mx_del_strarr(&temp);
    
}

void check_nbr_of_islands(char **names_of_islands, int lines, int islands) {
    int count = 0;
    for (int i = 0; i < lines; i++) {
        if (names_of_islands[i][0] != ' ') {
            count++;
        }
    }
    if (count != islands) {
        mx_del_strarr(&names_of_islands);
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
}


