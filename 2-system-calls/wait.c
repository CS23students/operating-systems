#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        printf("Parent waiting for child to finish...\n");
        wait(NULL);  // Parent waits for child process
        printf("Child finished execution.\n");
    } else if (pid == 0) {
        printf("Child process executing...\n");
        sleep(2); // Simulating some task
        printf("Child process done.\n");
    }

    return 0;
}


// Parent waiting for child to finish...
// Child process executing...
// Child process done.
// Child finished execution.
