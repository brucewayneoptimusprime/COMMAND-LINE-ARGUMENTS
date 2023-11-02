#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num1> <num2> <num3> ...\n", argv[0]);
        return 1;
    }

    double sum = 0;
    for (int i = 1; i < argc; i++) {
        sum += atof(argv[i]);
    }

    double average = sum / (argc - 1);
    printf("Average: %f\n", average);

    return 0;
}
