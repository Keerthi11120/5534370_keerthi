#include <stdio.h>
#include <limits.h>

void miniMaxSum(int arr_count, int* arr) {
    long min = LONG_MAX, max = LONG_MIN, sum = 0;

    for (int i = 0; i < arr_count; i++) {
        long val = arr[i];
        sum += val;
        if (val < min) min = val;
        if (val > max) max = val;
    }

    printf("%ld %ld\n", sum - max, sum - min);
}

int main() {
    int arr[5];

    // Read 5 integers from input
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Call miniMaxSum function
    miniMaxSum(5, arr);

    return 0;
}
