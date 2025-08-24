#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* timeConversion(char* s) {
    // Allocate memory for the result
    char* result = malloc(9 * sizeof(char)); // HH:MM:SS + '\0'
    int hour, min, sec;
    char period[3]; // AM or PM

    // Parse the input string
    sscanf(s, "%2d:%2d:%2d%2s", &hour, &min, &sec, period);

    // Convert hour to 24-hour format
    if (strcmp(period, "AM") == 0) {
        if (hour == 12) hour = 0; // 12 AM -> 00
    } else if (strcmp(period, "PM") == 0) {
        if (hour != 12) hour += 12; // 1 PM -> 13, etc.
    }

    // Format the output
    sprintf(result, "%02d:%02d:%02d", hour, min, sec);
    return result;
}

int main() {
    char s[11]; // HH:MM:SSAM or HH:MM:SSPM
    scanf("%s", s);

    char* convertedTime = timeConversion(s);
    printf("%s\n", convertedTime);

    free(convertedTime);
    return 0;
}
