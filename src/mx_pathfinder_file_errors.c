#include "../inc/pathfinder.h"

void mx_argument_line_error(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}

void mx_filename_error(int file, char* filename) {
    if (file <= 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        close(file);
        exit(1);
    }
}

void mx_file_errors(int argc, char* argv[]) {
    mx_argument_line_error(argc);
    int file = open(argv[1], O_RDONLY);
    char* filename = argv[1];
    mx_filename_error(file, filename);
}

