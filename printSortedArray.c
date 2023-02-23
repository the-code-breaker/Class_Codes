// 1.Write a C program to dynamically allocate memory for an array of n integers. Take k elements from the users and insert them into the array. Print the sorted array ascending order.
// Test case:
// input
// n=4
// 2 5 8 9
// k=3
// 4 6 2
// Output: 2 2 4 5 6 8 9


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, i, j, temp;

    // Ask the user to enter the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*) malloc(n * sizeof(int));

    // Ask the user to enter k elements and insert them into the array
    printf("Enter %d elements:\n", k);
    for (i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in ascending order using bubble sort algorithm
    for (i = 0; i < k-1; i++) {
        for (j = 0; j < k-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print the sorted array in ascending order
    printf("The sorted array in ascending order:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
