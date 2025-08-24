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

// Function to read a line from input
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    if (!data) exit(EXIT_FAILURE);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;

        alloc_length *= 2;
        data = realloc(data, alloc_length);
        if (!data) exit(EXIT_FAILURE);
    }

    if (data_length > 0 && data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    } else {
        data[data_length] = '\0';
    }

    return data;
}

// Function to check if string is pangram
char* pangrams(char* s) {
    bool letters[26] = {0};

    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) {
            letters[tolower(s[i]) - 'a'] = true;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!letters[i]) {
            return "not pangram";
        }
    }
    return "pangram";
}

// Main function
int main() {
    char* s = readline();
    char* result = pangrams(s);
    printf("%s\n", result);

    free(s);
    return 0;
}
