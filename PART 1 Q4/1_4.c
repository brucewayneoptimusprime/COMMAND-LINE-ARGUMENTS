#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    int totalLines = 0;

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Error opening %s\n", argv[i]);
            return 1;
        }

        int lines = 0;
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            if (ch == '\n') {
                lines++;
            }
        }

        fclose(file);
        printf("File: %s, Lines: %d\n", argv[i], lines);
        totalLines += lines;
    }

    printf("Total Lines: %d\n", totalLines);
    return 0;
}
