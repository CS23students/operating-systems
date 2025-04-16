#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Declare semaphore
sem_t mutex;

// Shared data
int counter = 0;

// Function executed by each thread
void* thread_func(void* arg) {
    int id = *((int*)arg);

    // Entry section
    sem_wait(&mutex);

    // Critical section
    printf("Thread %d entering critical section...\n", id);
    counter++;
    printf("Thread %d updated counter to %d\n", id, counter);
    sleep(1); // Simulate some work
    printf("Thread %d exiting critical section.\n", id);

    // Exit section
    sem_post(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3];

    // Initialize semaphore to 1 (binary semaphore)
    sem_init(&mutex, 0, 1);

    // Create threads
    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&mutex);

    printf("Final Counter Value: %d\n", counter);

    return 0;
}


// Thread 1 entering critical section...
// Thread 1 updated counter to 1
// Thread 1 exiting critical section.
// Thread 2 entering critical section...
// Thread 2 updated counter to 2
// Thread 2 exiting critical section.
// Thread 3 entering critical section...
// Thread 3 updated counter to 3
// Thread 3 exiting critical section.
// Final Counter Value: 3
