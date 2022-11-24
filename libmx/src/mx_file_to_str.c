#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int temp = open(file, O_RDONLY);
    if (!temp) {
        close(temp);
        return NULL; 
    }
    int size = 0;
    char buf;
    while (read(temp, &buf, 1) > 0) {
        size++;
    }
    close(temp);
    if (size == 0)
        return NULL;
    char *temp_word = mx_strnew(size);
    temp = open(file, O_RDONLY);
    read(temp, temp_word, size);
    temp_word[size++] = '\0';
    return temp_word;
}

// int main (int argc, char *argv[]) {
//     if (argc == 1)
//         return 1;
//     printf("%s", mx_file_to_str(argv[1]));
//     //printf("%i", mx_strlen(mx_file_to_str(argv[1])));
//     return 0;
// }


