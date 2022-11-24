#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
    if (s == NULL)
        return NULL;
    int n = mx_count_words(s, c);
    char **str = (char **)malloc(n * 8);
    int j = 0;
    for (int i = 0; i < n; i++) {
        int left = 0;
        int word = 0;
        for (j = 0; s[j]; j++) {
            if (s[j] != c) {
                word++;
                if (left == 0)
                    left = j;
            } else if ( word && s[j] == c) 
                break;
        }    
        char *res_word = mx_strnew(word);
        for (int t = 0; left < j; t++) {
            res_word[t] = s[left];
            left++;
        }
        str[i] = res_word;
    }
    str[n] = NULL;
    return str;

}

/*int main (void) {
    char *s = "**Good bye,**Mr.Anderson.****";
    char **s2 = mx_strsplit(s, '*');
    for (int i = 0;  i < 2; i++) 
        printf("%s", s2[i]);
}*/


