#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    char filename[100];

    printf("Enter file name: ");
    scanf("%s", filename);

    // Remove hard link
    if (unlink(filename) == -1) {
        perror("Error removing hard link");
        return 1;
    } else {
        printf("Hard link removed successfully.\n");
    }

    return 0;
}