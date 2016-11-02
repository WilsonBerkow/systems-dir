#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main() {
    DIR* stream = opendir(".");
    struct dirent* entry = readdir(stream);
    long int tot_size = 0;
    printf("Contents of . directory:\n");
    while (entry) {
        printf("- %s", (*entry).d_name);
        if (entry->d_type == DT_DIR) {
            printf(" (directory)");
        } else {
            struct stat buf;
            stat((*entry).d_name, &buf);
            printf(" (%li bytes)", buf.st_size);
            tot_size += buf.st_size;
        }
        printf("\n");
        entry = readdir(stream);
    }
    closedir(stream);
    printf("Size of all regular files in directory: %li bytes\n", tot_size);
    return 0;
}
