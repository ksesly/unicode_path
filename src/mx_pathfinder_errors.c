#include "../inc/pathfinder.h"

void mx_firstline_error(int file) {
    mx_printerr("error: line 1 is not valid\n");
    close(file);
}


