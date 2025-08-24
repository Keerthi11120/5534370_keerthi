#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

// Function to safely parse unsigned long long from string
uint32_t parse_uint32(const char *str) {
    char *endptr;
    unsigned long value = strtoul(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        // invalid input
        fprintf(stderr, "Invalid input\n");
        exit(EXIT_FAILURE);
    }

    if (value > 0xFFFFFFFF) {
        fprintf(stderr, "Input out of range for 32-bit unsigned int\n");
        exit(EXIT_FAILURE);
    }

    return (uint32_t)value;
}

// Function to flip bits of a 32-bit unsigned integer
uint32_t flippingBits(uint32_t n) {
    return ~n;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        fprintf(stderr, "Failed to read number of test cases\n");
        return 1;
    }

    for (int i = 0; i < t; i++) {
        char buffer[50];
        if (scanf("%s", buffer) != 1) {
            fprintf(stderr, "Failed to read input\n");
            return 1;
        }

        uint32_t n = parse_uint32(buffer);
        uint32_t flipped = flippingBits(n);
        printf("%" PRIu32 "\n", flipped);
    }

    return 0;
}
