#include "../inc/pathfinder.h"

void mx_firstline_error(void) {
    mx_printerr("error: line 1 is not valid\n");
    //close(file);
    exit(1);
}

void mx_error_line(int str) {
    mx_printerr("error: line ");
    char* line = mx_itoa(str);
    mx_printerr(line);
    mx_strdel(&line);
    mx_printerr(" is not valid\n");
    exit(1);
}

void mx_first_line_checker(char* path_file) {
    for (int i = 0; path_file[i] != '\n'; i++) {
        if (!mx_isdigit(path_file[i])) {
            mx_firstline_error();
        }
    }
}

void mx_print_invalide_island(void) {
    mx_printerr("error: invalide number of islands\n");
    exit(1);
}

void mx_invalid_islands(int counter, int islands) {
    if (islands < 2) {
        mx_print_invalide_island();
    }
    if (counter != islands) {
        mx_print_invalide_island();
    }
}

void mx_to_many_bridges(char** temp) {
    if (mx_atoi(temp[2]) >= __INT_MAX__) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(1);
    }
}




