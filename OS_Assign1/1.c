#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
  int option;
  printf("1. soft link\n");
  printf("2. hard link\n");
  printf("3. fifo\n");
  printf("Enter option:");
  scanf("%d", &option);

  if(option == 1){
    char target_path[1000], link_path[1000];
    printf("Enter the path of the target file: ");
    scanf("%s", target_path);
    printf("Enter the path for the soft link: ");
    scanf("%s", link_path);

    int result = symlink(target_path, link_path);
    if (result == -1) {
        perror("Error creating soft link");
        return 1;
    }
    printf("Soft link created successfully.\n");
  }

  else if(option == 2){
    char target_path[1000], link_path[1000];
    printf("Enter the path of the target file: ");
    scanf("%s", target_path);
    printf("Enter the path for the hard link: ");
    scanf("%s", link_path);

    int result = link(target_path, link_path);
    if (result == -1) {
      perror("Error creating hard link");
      return 1;
    }
    printf("Hard link created successfully.\n");
  }

  else if(option == 3){
    char fifo_path[1000];
    printf("Enter the path for the FIFO (Named Pipe): ");
    scanf("%s", fifo_path);

    int result = mknod(fifo_path, S_IFIFO, 0);
    if (result == -1) {
        perror("Error creating FIFO");
        return 1;
    }
    printf("FIFO (Named Pipe) created successfully.\n");
  }

  else {
    printf("Invalid choice.\n");
  }

  return 0;
}
