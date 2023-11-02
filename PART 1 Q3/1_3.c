#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    int length = strlen(argv[1]);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", argv[1][i]);
    }

    return 0;
}
