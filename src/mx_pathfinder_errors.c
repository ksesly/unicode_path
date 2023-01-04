#include "../inc/pathfinder.h"

void mx_firstline_error(int file) {
    mx_printerr("error: line 1 is not valid\n");
    close(file);
    exit(1);
}

void mx_error_line(int str) {
    mx_printerr("error: line");
    char* line = mx_itoa(str);
    mx_printerr(line);
    mx_strdel(&line);
    mx_printerr(" is not valid\n");
    exit(1);
}


