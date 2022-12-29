#include "../inc/pathfinder.h"

void mx_argument_line_error(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}


//!FIX
void mx_filename_error(char* argv[]) {
    if (open(argv[1], O_RDONLY) < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(1);
    }
     
}

