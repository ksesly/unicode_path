#include "../inc/pathfinder.h"



int **mx_create_matrix(char* path_file, char **name_of_islands_arr, int islands) {

    char **file_lines = mx_strsplit(path_file, '\n');
    int **matrix = (int **) malloc(islands * sizeof(int *));

    for (int i = 0; i < islands; i++) {
        matrix[i] = (int *)malloc(islands * sizeof(int));
    }
   
    for(int i = 0; i < islands; i++) {
        for(int j = 0; j < islands; j++) {
            matrix[i][j] = INFINITY;
        }
    }

    for (int i = 0; file_lines[i]; i++) {
        printf("%s\n", file_lines[i]);
    }

    for (int i = 1; file_lines[i]; i++) {

        char **temp = (char **)malloc(4 * sizeof(char *));
        for (int i = 0; i <= 3; i++) {
            temp[i] = NULL;
        }

        temp[0] = mx_strndup(file_lines[i], mx_get_char_index(file_lines[i], '-'));
        file_lines[i] += mx_get_char_index(file_lines[i], '-') + 1;
        temp[1] = mx_strndup(file_lines[i], mx_get_char_index(file_lines[i], ','));
        file_lines[i] += mx_get_char_index(file_lines[i], ',') + 1;
        temp[2] = mx_strndup(file_lines[i], mx_get_char_index(file_lines[i], '\n'));
         
        int from = -1;
        for (int i = 0; name_of_islands_arr[i]; i++) {
            if (mx_strcmp(name_of_islands_arr[i], temp[0]) == 0) {
                from = i;
            }
        }

        int to = -1;
        for (int i = 0; name_of_islands_arr[i]; i++) {
            if (mx_strcmp(name_of_islands_arr[i], temp[1]) == 0) {
                to = i;
            }
        }
    
        matrix[from][to] = mx_atoi(temp[2]);
        matrix[to][from] = mx_atoi(temp[2]);
    }

    return matrix;

}

