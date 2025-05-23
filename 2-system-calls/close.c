#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
    
    if (fd < 0) {
        printf("File opening failed!\n");
        return 1;
    }
    
    printf("File opened with descriptor: %d\n", fd);
    
    close(fd);  // Close the file descriptor
    
    printf("File closed successfully.\n");
    return 0;
}

// File opened with descriptor: 3
// File closed successfully.

