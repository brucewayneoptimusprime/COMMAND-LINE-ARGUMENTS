#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <mathematical expression>\n", argv[0]);
        return 1;
    }

    double result;
    if (sscanf(argv[1], "%lf", &result) == 1) {
        printf("Result: %f\n", result);
        return 0;
    }

    // If sscanf fails, try evaluating the expression
    result = atof(argv[1]);
    printf("Result: %f\n", result);
    return 0;
}
