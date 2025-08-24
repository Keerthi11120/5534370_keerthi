#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform counting sort
void countingSort(int arr_count, int* arr) {
    int count[100] = {0}; // As values are in 0-99
    for(int i = 0; i < arr_count; i++) {
        count[arr[i]]++;
    }

    // Print the frequency array
    for(int i = 0; i < 100; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) exit(EXIT_FAILURE);

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(n, arr);

    free(arr);
    return 0;
}
