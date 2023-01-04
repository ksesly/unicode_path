#pragma once

#include "../libmx/inc/libmx.h"

//file errors
void mx_argument_line_error(int argc);
void mx_filename_error(int file, char* filename);
void mx_file_errors(int argc, char* argv[], char* path_file);
void mx_null_file_error(int file, char *filename, char *path_file);

//algorithm error
void mx_firstline_error(int file);
void mx_error_line(int str);



int mx_get_number_of_islands(char* path_file);
int mx_return_number_of_islands(char* filename, char* path_file);
void mx_lines_check(char* path_file);



