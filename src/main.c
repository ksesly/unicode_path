//Create a program that finds all the shortest paths between all the islands,
//using informationabout the bridges that connect them. 
//The program:
//•reads data from a file. Its name is specified as a command-line argument
//•finds all the shortest paths between each combination of two islands
//•prints the paths using the FIFO (first) rule for the islands to the standard output.
//More examples can be found in the CONSOLE OUTPUT

//Input file description:
//•the first line in the file is the number of islands
//•the remaining lines describe the distance between the two islands
//Input file description:
//•the first line in the file is the number of islands
//•the remaining lines describe the distance between the two islands
//island1-island2,length_of_bridge
//–the names of the islands contain only alphabetic characters and cannot be emptyor identical
//–the length of the bridge contains only numbers, cannot be empty and has a positivevalue
//–the sum of the lengths of all bridges in the file does not exceed INT_MAX

//The output consists of information blocks about a specific shortest path. 
//Each block contains:
//•======================================== - the upper boundary that consists of 40=  characters
//•Path: <island1> -> <island2>t hat shows the initial point and the final destination
//•Route: <island1> -> <all_islands_between> -> <island2> that shows the full routebetween the two islands
//•Distance: <length1> + <length2> = <sum> that shows the distance between everyisland in the route, as well as their sum that indicates the distance to the finaldestination
//•======================================== - the bottom boundary that consists of 40=  characters
//Error handling.
//The program prints errors to the standard error streamstderrin thefollowing order of priority

// •usage: ./pathfinder [filename]if there is an invalid number of command-line arguments
// •error: file [filename] does not existif the file does not exist
// •error: file [filename] is emptyif the file is empty
// •error: line 1 is not validif the first line contains something other than digits orhas a non-positive value
// •error: line [line_number] is not validif one of the remaining lines does not matchthe format above
// •error: invalid number of islandsif the number received in the first line does notmatch with the number of islands
// •error: duplicate bridgesif there is more than one bridge between the islands
// •error: sum of bridges lengths is too bigif the sum of the lengths of all bridges inthe file exceeds INT_MAX

#include "../inc/pathfinder.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    char* filename = argv[1];
    char *path_file = mx_file_to_str(filename);
    char *copy_path_file = path_file;
    printf("rg1\n");
    mx_file_errors(argc, argv, copy_path_file);
   

    int islands = mx_return_number_of_islands(argv[1], copy_path_file);
    //mx_printint(islands);

    printf("rg2\n");
    //printf("%s", path_file);
    //mx_printstr(path_file);
    //printf("%s", copy_path_file);

    //get the names of islands
    char **names_of_islands = mx_names_of_islands_arr(path_file, islands);
    // for (int i = 0; i < islands; i++) {
    //     for (int j = 0; j < islands; j++) {
    //         printf("%c ", names_of_islands[i][j]);
    //     }
    // }
    
    printf("rg3\n");
    for (int i = 0; i < islands; i++) {
            for (int j = 0; j < islands; j++) {
                printf("%c", names_of_islands[i][j]);
            }
        }
    int** matrix = mx_create_matrix(path_file, names_of_islands, islands);
    printf("rg4\n");
    for (int i = 0; i < islands; i++) {
            for (int j = 0; j < islands; j++) {
                printf("%c", names_of_islands[i][j]);
            }
        }
    for (int i = 0; i < islands; i++) {
        for (int j = 0; j < islands; j++) {
            printf("%i ", matrix[i][j]);
        }
    }
    return 0;
}

