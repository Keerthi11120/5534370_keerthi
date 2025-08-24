#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line of input of arbitrary length
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    if (!data) exit(EXIT_FAILURE);

    while (1) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length *= 2;
        data = realloc(data, alloc_length);
        if (!data) exit(EXIT_FAILURE);
    }

    if (data_length > 0 && data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length + 1);
    if (!data) exit(EXIT_FAILURE);

    return data;
}

int main() {
    printf("Enter a string: ");
    char* input = readline();
    printf("You entered: %s\n", input);
    free(input);
    return 0;
}
