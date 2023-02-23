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

#define MAX_WORDS 100 // Maximum number of words in the input string
#define MAX_LENGTH 50 // Maximum length of each word in the input string

int main() {
    char input_string[MAX_WORDS * MAX_LENGTH]; // Input string
    char** Arr; // Two-dimensional array of strings
    int num_words = 0; // Number of words in the input string
    char* word; // Pointer to a word in the input string

    // Ask the user to enter a string
    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);

    // Count the number of words in the input string
    word = strtok(input_string, " \n");
    while (word != NULL) {
        num_words++;
        word = strtok(NULL, " \n");
    }

    // Dynamically allocate memory for the two-dimensional array of strings
    Arr = (char**) malloc(num_words * sizeof(char*));
    for (int i = 0; i < num_words; i++) {
        Arr[i] = (char*) malloc(MAX_LENGTH * sizeof(char));
    }

    // Copy each word from the input string into the two-dimensional array of strings
    int i = 0;
    word = strtok(input_string, " \n");
    while (word != NULL) {
        strncpy(Arr[i], word, MAX_LENGTH);
        i++;
        word = strtok(NULL, " \n");
    }

    // Print the two-dimensional array of strings
    printf("The two-dimensional array of strings:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", Arr[i]);
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < num_words; i++) {
        free(Arr[i]);
    }
    free(Arr);

    return 0;
}
