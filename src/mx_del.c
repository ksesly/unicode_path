#include "../inc/pathfinder.h"

void mx_del_matrix(int **adjacency_array, int islands) {
    for (int i = 0; i < islands; i++)
        free(adjacency_array[i]);

    free(adjacency_array);
}

void mx_del_array2d(char **arr, int islands) {
    for (int i = 0; i < islands; i++)
        mx_strdel(&arr[i]);
    free(arr);
}

