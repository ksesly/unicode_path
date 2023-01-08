#include "../inc/pathfinder.h"

void mx_del_matrix(int** arr, int islands) {
    for (int i = 0; i < islands; i++)
        free(arr[i]);

    free(arr);
}

void mx_del_array2d(char** arr, int islands) {
    for (int i = 0; i < islands; i++)
        mx_strdel(&arr[i]);
    free(arr);
}

