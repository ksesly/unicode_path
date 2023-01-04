#include "../inc/pathfinder.h"

int **mx_all_pair_shortest_part(int **matrix, int islands) {

    int **dist = (int **)malloc(islands * sizeof(int));
    for (int i = 0; i < islands; i++) {
        dist[i] = (int *)malloc(islands * sizeof(int));
        for (int j = 0; j < islands; j++) {
            dist[i][j] = matrix[i][j];
        }
    }

    //the all pair shortest path algorithm
    for (int k = 0; k < islands; k++) {
        for (int i = 0; i < islands; i++) {
            for (int j = 0 ; j < islands; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            }
        }
    }

    for (int m = 0; m < islands; m++) {
        for (int n = 0; n < islands; n++) {
            if (dist[m][n] == ???) {
                dist[m][n] = 0;
            }
        }
    }

    



}