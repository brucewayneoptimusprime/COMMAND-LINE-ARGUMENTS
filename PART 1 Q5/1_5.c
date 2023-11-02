#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidDate(char *date) {
    // Assuming date format is "YYYY-MM-DD"
    if (strlen(date) != 10) {
        return false;
    }

    // Check if the hyphens are in the correct positions
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year, month, day;
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3) {
        return false;
    }

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    // Additional logic to check for valid months and days can be added here

    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <date (YYYY-MM-DD)>\n", argv[0]);
        return 1;
    }

    if (isValidDate(argv[1])) {
        printf("Valid date: %s\n", argv[1]);
    } else {
        printf("Invalid date: %s\n", argv[1]);
    }

    return 0;
}
