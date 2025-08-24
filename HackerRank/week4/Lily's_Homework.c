#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
    int index;
} Pair;

int cmpAsc(const void* a, const void* b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

int cmpDesc(const void* a, const void* b) {
    return ((Pair*)b)->value - ((Pair*)a)->value;
}

int countSwaps(int* arr, int n, int ascending) {
    Pair* temp = (Pair*)malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        temp[i].value = arr[i];
        temp[i].index = i;
    }

    if (ascending)
        qsort(temp, n, sizeof(Pair), cmpAsc);
    else
        qsort(temp, n, sizeof(Pair), cmpDesc);

    bool* visited = (bool*)calloc(n, sizeof(bool));
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || temp[i].index == i)
            continue;

        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = temp[j].index;
            cycle_size++;
        }
        if (cycle_size > 1)
            swaps += cycle_size - 1;
    }

    free(temp);
    free(visited);
    return swaps;
}

int lilysHomework(int n, int* arr) {
    int ascSwaps = countSwaps(arr, n, 1);
    int descSwaps = countSwaps(arr, n, 0);
    return ascSwaps < descSwaps ? ascSwaps : descSwaps;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = lilysHomework(n, arr);
    printf("%d\n", result);

    free(arr);
    return 0;
}