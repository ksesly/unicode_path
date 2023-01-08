#include "../inc/pathfinder.h"

void mx_find_route(int islands, int distance, int* route, int** matrix, int** matrix_of_paths, char** names_of_islands) {

    for (int k = 0; k < islands; k++) {
        if (k == route[distance]) continue;
        if (k != route[distance] && 
        (matrix[route[distance]][k] == matrix_of_paths[route[distance]][route[0]] - matrix_of_paths[k][route[0]])) {
            distance++;
            route[distance] = k;
            mx_find_route(islands, distance, route, matrix, matrix_of_paths, names_of_islands);
            distance--;
        }
    }
    if (route[distance] != route[0]) return;

    mx_print_output(names_of_islands, route, distance, matrix);
}


