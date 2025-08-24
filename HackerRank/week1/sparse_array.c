#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Windows-compatible readline
char* readline() {
    char buffer[1024]; // adjust size if needed
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return NULL;

    // Remove newline character if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';

    // Allocate memory for the string to return
    char* line = malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(line, buffer);
    return line;
}

// Function to count matching strings
int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries) {
    int* result = malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++) {
        int count = 0;
        for (int j = 0; j < strings_count; j++) {
            if (strcmp(strings[j], queries[i]) == 0) {
                count++;
            }
        }
        result[i] = count;
    }

    return result;
}

int main() {
    int n, q;
    scanf("%d", &n);
    getchar(); // consume newline

    char** strings = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        strings[i] = readline();
    }

    scanf("%d", &q);
    getchar(); // consume newline

    char** queries = malloc(q * sizeof(char*));
    for (int i = 0; i < q; i++) {
        queries[i] = readline();
    }

    int* results = matchingStrings(n, strings, q, queries);

    for (int i = 0; i < q; i++) {
        printf("%d\n", results[i]);
    }

    // Free memory
    for (int i = 0; i < n; i++) free(strings[i]);
    for (int i = 0; i < q; i++) free(queries[i]);
    free(strings);
    free(queries);
    free(results);

    return 0;
}
