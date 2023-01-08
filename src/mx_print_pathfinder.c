#include "../inc/pathfinder.h"

static void mx_delimeter_line(void) {

    for (int i = 0; i < 40; i++ )
        mx_printchar('=');
    mx_printchar('\n');
}

static void mx_print_route(int distance, char** names_of_islands, int* route) {

    mx_printstr("Route: ");    
    for (int i = 1; i < distance + 1; i++) {
        mx_printstr(names_of_islands[route[i]]);    
        if (i + 1 < distance + 1) 
            mx_printstr(" -> ");
    }
    mx_printstr("\n");
}

static void mx_print_distance( int distance, int** matrix, int* route, int sum) {

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
}

void mx_print_output(char** names_of_islands, int* route, int distance, int** matrix) {

    mx_delimeter_line();
    mx_printstr("Path: ");
    mx_printstr(names_of_islands[route[1]]);
    mx_printstr(" -> ");
    mx_printstr(names_of_islands[route[0]]);
    mx_printstr("\n");
    int sum = 0;
    mx_print_route(distance, names_of_islands, route);
    mx_print_distance(distance, matrix, route, sum);
    mx_printstr("\n");
    mx_delimeter_line();
}

void mx_print_pathfinder(int** matrix, int islands, char** names_of_islands) {
    
    int** path = mx_all_pair_shortest_part(matrix, islands);
    int distance;
    int* route =(int *)malloc(sizeof(int) * (islands + 1));
    
    for (int i = 0; i < islands; i++) {
        for (int j = i + 1; j < islands; j++) {
            distance = 1;
            route[0] = j;
            route[1] = i;
            mx_find_route(islands, distance, route, matrix, path, names_of_islands);
        }
    }
    free(route);
    mx_del_matrix(path, islands);
}


