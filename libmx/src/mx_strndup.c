#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *temp_arr = mx_strnew(n);
    if (temp_arr == NULL)
        return NULL;
    int i = 0;
    for (i = 0; i < (int)n; i++) {
        temp_arr[i] = s1[i];
    }
    temp_arr[i++] = '\0';
    return temp_arr;
}

// int main(void) {
//     char *arr = "Hello";
//     char *arr2 = mx_strndup(arr, 5);
//     printf("%s", arr2);
//     free(arr2);
// }


