#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  // For sleep()

// Function to be executed by threads
void* thread_function(void* arg) {
    int thread_num = *((int*)arg); // Convert argument to integer
    printf("Thread %d: Running\n", thread_num);
    sleep(1);  // Simulate some work
    printf("Thread %d: Completed\n", thread_num);
    return NULL;
}

int main() {
    int num_threads = 3; // Number of threads
    pthread_t threads[num_threads];
    int thread_args[num_threads];

    // Creating threads
    for (int i = 0; i < num_threads; i++) {
        thread_args[i] = i + 1; // Assign thread number
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            printf("Error creating thread %d\n", i + 1);
            return 1;
        }
    }

    // Waiting for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished execution.\n");
    return 0;
}


// Thread 1: Running
// Thread 2: Running
// Thread 3: Running
// Thread 1: Completed
// Thread 2: Completed
// Thread 3: Completed
// All threads finished execution.
