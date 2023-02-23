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
    int n, k, i, j, temp, *arr;
    
    scanf("%d", &n);
    
    arr = (int*) malloc(n * sizeof(int)); 
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);
    
    arr = (int*) realloc(arr, (n+k) * sizeof(int)); 
    
    for (i = n; i < n+k; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < n+k-1; i++) {
        for (j = i+1; j < n+k; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    for (i = 0; i < n+k; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    
    return 0;
}
