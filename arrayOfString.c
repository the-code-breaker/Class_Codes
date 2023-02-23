// 2.Write a C program to dynamically allocate memory for a two-dimensional array Arr of string.
// Input: Take string from the user and put each word of that string in Arr.
// Output: print 2-D array Arr.
// Test case:
// input
// Hello how are you
// Output:
// Hello
// how
// are
// you


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100], **Arr;
    int i, j, k, len, count = 0;
    
    fgets(str, sizeof(str), stdin);
    
    len = strlen(str);
    
    for (i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\n') {
            count++;
        }
    }
    
    Arr = (char**) malloc(count * sizeof(char*));
    
    j = 0;
    k = 0;
    
    for (i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0') {
            Arr[j] = (char*) malloc((k+1) * sizeof(char));
            strncpy(Arr[j], &str[i-k], k);
            Arr[j][k] = '\0';
            k = 0;
            j++;
        } else {
            k++;
        }
    }
    
    for (i = 0; i < count; i++) {
        printf("%s\n", Arr[i]);
    }
    
    for (i = 0; i < count; i++) {
        free(Arr[i]);
    }
    
    free(Arr);
    
    return 0;
}
