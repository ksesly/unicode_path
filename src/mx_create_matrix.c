#include "../inc/pathfinder.h"

//remake
char **get_path(char *file_lines) {
    printf("rg3.4\n");
        printf("rg3.3.1\n");
        char **temp = (char **)malloc(4 * sizeof(char *));
        for (int i = 0; i <= 3; i++) {
            temp[i] = NULL;
        }
        printf("rg3.3.2\n");
        temp[0] = mx_strndup(file_lines, mx_get_char_index(file_lines, '-'));
        printf("%s", temp[0]);
        file_lines += mx_get_char_index(file_lines, '-') + 1;
        temp[1] = mx_strndup(file_lines, mx_get_char_index(file_lines, ','));
        printf("%s", temp[1]);
        file_lines += mx_get_char_index(file_lines, ',') + 1;
        temp[2] = mx_strndup(file_lines, mx_get_char_index(file_lines, '\n'));
        printf("%s", temp[2]);
     
    return temp;
}

int mx_get_strarr_index(char **strarr, char *str) {
    printf("heello");
    for (int i = 0; strarr[i]; i++) {
        if (mx_strcmp(strarr[i], str) == 0) {
            return i;
        }
    }
    return -1;
}


//remake
int **mx_create_matrix(char* path_file, char **name_of_islands_arr, int islands) {

    char **file_lines = mx_strsplit(path_file, '\n');
    printf("rg3.1\n");

    int **matrix = (int **) malloc(islands * sizeof(int *));
    for (int i = 0; i < islands; i++) {
        matrix[i] = (int *)malloc(islands * sizeof(int));
    }
    printf("rg3.2\n");
    for(int i = 0; i < islands; i++) {
        for(int j = 0; j < islands; j++) {
            matrix[i][j] = INFINITY;
        }
    }
    printf("rg3.3\n");
    // for (int i = 0; file_lines[i]; i++) {
    //     printf("%s", file_lines[i]);
    // }
    for (int i = 1; file_lines[i]; i++) {

        char **temp = get_path(file_lines[i]);
        
        if (mx_atoi(temp[2]) >= __INT_MAX__) {
            printf("rg3.4.1\n");
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(0);
        }
        printf("rg3.5\n");
        
        for (int i = 0; i < islands; i++) {
            for (int j = 0; j < islands; j++) {
                printf("%c", name_of_islands_arr[i][j]);
            }
        }
        int from = mx_get_strarr_index(name_of_islands_arr, temp[0]);
        mx_printint(from);
        int to = mx_get_strarr_index(name_of_islands_arr, temp[1]);
        mx_printint(from);
        matrix[from][to] = mx_atoi(temp[2]);
        matrix[to][from] = mx_atoi(temp[2]);
    
        mx_del_strarr(&temp);

    }

    return matrix;

}

