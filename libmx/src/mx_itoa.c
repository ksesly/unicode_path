#include "../inc/libmx.h"

char *mx_itoa(int number) {
    char *word = NULL;
    int size = 0;
    long long temp;
    if (number == 0) {
        word = mx_strnew(1);
        word[0] = '0';
        return word;
    }
    temp = number;
    if (temp < 0) {
        size++;
        temp *= -1;;
    }
    while(temp != 0) {
        temp /= 10;
        size++;
    }
    word = mx_strnew(size);
    if (number < 0) {
        word[0] = '-';
        number *= -1;
    }
    word[size - 1] = '\0';
    while (number != 0 && size >= 0 && word[size] != '-') {
        word[size - 1] = (number % 10) + '0';
        number /= 10;
    }
    return word;
}

// int main (void) {
//     char *temp = mx_itoa(1);
//     printf("%s\n", temp);
//     return 0;
// }
