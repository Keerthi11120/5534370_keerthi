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

// Function to parse string to int safely
int parse_int(const char* str) {
    char* endptr;
    long value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        // Input is not a valid integer
        fprintf(stderr, "Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    // Check for overflow/underflow
    if (value > INT_MAX || value < INT_MIN) {
        fprintf(stderr, "Integer overflow/underflow.\n");
        exit(EXIT_FAILURE);
    }

    return (int)value;
}

// Main function for testing
int main() {
    printf("Enter an integer: ");
    char* input = readline();
    int number = parse_int(input);
    printf("You entered: %d\n", number);
    free(input);
    return 0;
}
