#include "../inc/pathfinder.h"

int mx_get_number_of_islands(char* path_file) {
    int length = 0;
    for (int i = 0; path_file[i] != '\0'; length++) 
        if ((char) path_file[i++] == '\n') 
            break;
    char *line = mx_strnew(length);
    line[length] = '\0';
    for (int i = 0; i < length; i++) 
        line[i] = path_file[i];
    int number_of_islands = mx_atoi(line);
    mx_strdel(&line);
    mx_strdel(&path_file);
    //mx_printint(number_of_islands);
    return number_of_islands;
}

int mx_return_number_of_islands(char* filename, char* path_file) {
    int file = open(filename, O_RDONLY);
    int islands = mx_get_number_of_islands(path_file);
    if (islands <= 0) 
        mx_firstline_error(file);
    close(file);
    return islands;
}


