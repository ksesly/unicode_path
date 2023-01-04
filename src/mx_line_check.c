#include "../inc/pathfinder.h"
#include <stdio.h>

void mx_lines_check(char* path_file) {
    //printf("%i", 7);
    //printf("%c", *path_file);
    int counter = 0;
    for (int i = 0; path_file[i] != '\0'; i++) {
        if (!mx_isdigit(path_file[i])) {
            counter++;
            continue;
        }
    }
    //printf("%i", 7);
    int line = 2;
    int coma_counter = 0;
    int defis_counter = 0;
    bool coma = false;
    for (int i = counter; path_file[i] != '\0'; i++) {
        mx_printint(2);
        if (!mx_isalpha(path_file[i]) && !mx_isdigit(path_file[i]) &&
                                        path_file[i] != ',' &&
                                        path_file[i] != '-' && 
                                        path_file[i] != '\n') {
            mx_strdel(&path_file);
            mx_error_line(line);
            
        }

        if (!mx_isalpha(path_file[i - 1]) && path_file[i] != '-') {
            mx_strdel(&path_file);
            mx_error_line(line);
        }

        if (!mx_isalpha(path_file[i + 1]) && path_file[i] != '-') {
            mx_strdel(&path_file);
            mx_error_line(line);
        }
        
        if (path_file[i] == ',') {
            coma_counter++;
            coma = true;
            i++;
        }

        if (path_file[i] == '-')
            defis_counter++;

        if (!mx_isdigit(path_file[i]) && coma && path_file[i] != '\n') {
            mx_strdel(&path_file);
            mx_error_line(line);
        }
        if (path_file[i] == '\n') {
            coma = false;
            if (defis_counter != 1 || coma_counter != 1) {
                mx_strdel(&path_file);
                mx_error_line(line);
            }
            line++;
            coma_counter = 0;
            defis_counter = 0;
        }
    }

}


