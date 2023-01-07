#pragma once

#include "../libmx/inc/libmx.h"

#define INFINITY 99999
#define MX_MIN(x, y) (((x) < (y)) ? (x) : (y))


//file errors
void mx_argument_line_error(int argc);
void mx_filename_error(int file, char* filename);
void mx_file_errors(int argc, char* argv[], char* path_file);
void mx_null_file_error(int file, char *filename, char *path_file);

//algorithm error
void mx_firstline_error(int file);
void mx_error_line(int str);
void mx_dup_error(char **file_lines, int lines_count);
void check_nbr_of_islands(char **names_of_islands, int lines, int islands);


int mx_get_number_of_islands(char* path_file);
int mx_return_number_of_islands(char* filename, char* path_file);
//void mx_lines_check(char* path_file);


char** mx_names_of_islands_arr(char *path_file, int islands);

int **mx_create_matrix(char* path_file, char **name_of_islands_arr, int islands);
//char **get_path(char *line);
//int **mx_all_pair_shortest_part(int **matrix, int islands);









