#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

void listFiles(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                printf("Directory: %s/%s\n", path, entry->d_name);
                char new_path[1024];
                snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);
                listFiles(new_path);
            }
        } else {
            printf("File: %s/%s\n", path, entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    listFiles(argv[1]);
    return 0;
}
