//Q3. File Creation and Descriptor Printing: 

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    char file[1000];
    printf("File name: ");
    scanf("%s", file);
    // creat() function creates the file with the permissions 0744(rwxr--r--), and returns a file descriptor(fd).
    int fd = creat(file, 0744);
    
    // file descriptors 0-standard input (stdin), 1-standard output (stdout), and 2-standard error (stderr) and any new file descriptor assigned value will be the lowest available like 3,4,etc
    printf("File descriptor value: %d\n", fd);
}
