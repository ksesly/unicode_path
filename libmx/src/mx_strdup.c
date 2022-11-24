#include "../inc/libmx.h"


char *mx_strdup(const char *str) {
    int length = mx_strlen(str);
    char *temp_arr = mx_strnew(length);
    int i = 0;
    for (i = 0; i < length; i++) {
        temp_arr[i] = str[i];
    }
    temp_arr[i] = '\0';
    return temp_arr;
}

// int main(void) {
//     char *arr = "Hello";
//     char *arr2 = mx_strdup(arr);
//     printf("%s", arr2);
//     free(arr2);
// }



