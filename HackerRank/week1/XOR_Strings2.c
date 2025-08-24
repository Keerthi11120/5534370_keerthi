#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n;
    
    // Read the size of the array
    printf("Enter number of elements: ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Invalid input.\n");
        return 1;
    }
    
    int *arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Read array elements
    printf("Enter %d integers: ", n);
    for(int i = 0; i < n; i++){
        if(scanf("%d", &arr[i]) != 1){
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }
    
    // Compute sum
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    
    // Print result
    printf("Sum of the array elements: %d\n", sum);
    
    free(arr); // Free allocated memory
    return 0;
}
