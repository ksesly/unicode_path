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

    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(names_of_islands[route[1]]);
    mx_printstr(" -> ");
    mx_printstr(names_of_islands[route[0]]);
    mx_printstr("\n");
    
    mx_printstr("Route: ");    
    for (int i = 1; i < distance + 1; i++) {
        mx_printstr(names_of_islands[route[i]]);
        
        if (i + 1 < distance + 1) 
            mx_printstr(" -> ");
    }
    mx_printstr("\n");
        int sum = 0;
    
    mx_printstr("Distance: ");
    for (int i = 1; i < distance; i++) {
        mx_printint(matrix[route[i]][route[i + 1]]);
        sum += matrix[route[i]][route[i + 1]];
        
        if (i < distance - 1) 
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
    mx_printstr("========================================\n");
}





