#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>  // For fork()
#include <sys/wait.h> // ✅ Add this for wait()

// Message Queue Structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("msgfile", 65);  // Unique key for message queue
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create message queue
    struct msg_buffer message;

    // Fork Process
    pid_t pid = fork();

    if (pid > 0) {  // Parent Process (Sender)
        printf("Parent Process (Sender)\n");

        // Send Message
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from Message Queue!");
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Sent to Message Queue: %s\n", message.msg_text);

        // ✅ Wait for child to finish
        wait(NULL);

        // Cleanup Message Queue
        msgctl(msgid, IPC_RMID, NULL);  
    } 
    else if (pid == 0) {  // Child Process (Receiver)
        sleep(1); // Small delay to ensure parent writes first
        printf("\nChild Process (Receiver)\n");

        // Receive Message
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Received from Message Queue: %s\n", message.msg_text);
    } 
    else {
        printf("Fork failed!\n");
        exit(1);
    }

    return 0;
}

// Parent Process (Sender)
// Sent to Message Queue: Hello from Message Queue!

// Child Process (Receiver)
// Received from Message Queue: Hello from Message Queue!
