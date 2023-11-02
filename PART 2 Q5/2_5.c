#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Error opening %s\n", argv[i]);
            return 1;
        }

        int lines = 0, words = 0, characters = 0;
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            characters++;

            if (ch == '\n') {
                lines++;
            }

            if (ch == ' ' || ch == '\n' || ch == '\t') {
                words++;
            }
        }

        fclose(file);
        printf("File: %s\nLines: %d\nWords: %d\nCharacters: %d\n", argv[i], lines, words, characters);
    }

    return 0;
}
