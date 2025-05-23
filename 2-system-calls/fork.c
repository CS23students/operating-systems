#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork(); // Create a child process

    if (pid > 0) {
        printf("Parent process (PID: %d)\n", getpid());
    } else if (pid == 0) {
        printf("Child process (PID: %d)\n", getpid());
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}


// Parent process (PID: 1234)
// Child process (PID: 1235)
