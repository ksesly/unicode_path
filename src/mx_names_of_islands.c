#include "../inc/pathfinder.h"

char** mx_names_of_islands_arr(char *path_file, int islands) {

    char *buff = mx_strnew(300);
    int i = 0;
    while (path_file[i] != '\n') {
        i++;
    }
    char **name_arr = (char**) malloc((islands * sizeof(char*)) + 1);
    for(int i = 0; i < islands; i++) {
        name_arr[i] = NULL;
    }


    bool temp = false;
    int counter = 0;
    int buff_counter = 0;
    
    for (int i = 0; i < mx_strlen(path_file); i++) {

        if (path_file[i] != '-' && path_file[i] != ',' && path_file[i] != '\n' && !mx_isdigit(path_file[i])) {
            buff[buff_counter] = path_file[i];
            buff_counter++;
        }

        if (path_file[i] == '-' || path_file[i] == ',') {
            for (int j = 0; j < counter; j++) {
                if (mx_strcmp(name_arr[j], mx_strdup(buff)) == 0) {
                    temp = true;
                    for (int j = 0; j < buff_counter; j++) {
                        buff[j] = '\0';
                    }
                    buff_counter = 0;
                }
            }
            if (!temp) {
                name_arr[counter] = mx_strdup(buff);
                for (int j = 0; j < buff_counter; j++) {
                    buff[j] = '\0';
                }
                buff_counter = 0;
                counter++;
            }
        }
        temp = false;
    }
    mx_strdel(&buff);

    return name_arr;
}


