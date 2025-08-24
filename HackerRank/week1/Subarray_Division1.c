#include <stdio.h>
#include <stdlib.h>

// Function to count the number of subarrays of length m with sum d
int birthday(int s_count, int* s, int d, int m) {
    int count = 0;
    for (int i = 0; i <= s_count - m; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += s[i + j];
        }
        if (sum == d) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int *s = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    int d, m;
    scanf("%d %d", &d, &m);

    int result = birthday(n, s, d, m);
    printf("%d\n", result);

    free(s);
    return 0;
}
