#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>  // For fork()
#include <sys/wait.h> // ✅ Add this for wait()

int main() {
    key_t key = ftok("shmfile", 75);  // Unique key for shared memory
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); // Create shared memory
    char *shm_data = (char*) shmat(shmid, (void*)0, 0); // Attach shared memory

    // Fork Process
    pid_t pid = fork();

    if (pid > 0) {  // Parent Process (Writer)
        printf("Parent Process (Writer)\n");

        // Write to Shared Memory
        strcpy(shm_data, "Hello from Shared Memory!");
        printf("Written to Shared Memory: %s\n", shm_data);

        // ✅ Wait for child to complete
        wait(NULL);

        // Cleanup Shared Memory
        shmctl(shmid, IPC_RMID, NULL);  
    } 
    else if (pid == 0) {  // Child Process (Reader)
        sleep(1); // Small delay to ensure parent writes first
        printf("\nChild Process (Reader)\n");

        // Read from Shared Memory
        printf("Read from Shared Memory: %s\n", shm_data);
    } 
    else {
        printf("Fork failed!\n");
        exit(1);
    }

    return 0;
}


// Parent Process (Writer)
// Written to Shared Memory: Hello from Shared Memory!

// Child Process (Reader)
// Read from Shared Memory: Hello from Shared Memory!
