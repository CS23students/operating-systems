#include <stdio.h>
#include <stdbool.h>

#define P 5 // Number of processes
#define R 3 // Number of resource types

int main() {
    int alloc[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 3},
        {2, 1, 1},
        {0, 0, 2}
    };

    int request[P][R] = {
        {0, 0, 0},
        {2, 0, 2},
        {0, 0, 0},
        {1, 0, 0},
        {0, 0, 2}
    };

    int avail[R] = {1, 0, 0};

    bool finish[P] = {false};
    int work[R];
    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;

    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool canFinish = true;
                for (int j = 0; j < R; j++) {
                    if (request[i][j] > work[j]) {
                        canFinish = false;
                        break;
                    }
                }

                if (canFinish) {
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[i][k];

                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found)
            break; // No process could proceed
    }

    // Check if deadlock exists
    bool deadlock = false;
    for (int i = 0; i < P; i++) {
        if (!finish[i]) {
            deadlock = true;
            printf("Process P%d is in deadlock.\n", i);
        }
    }

    if (!deadlock)
        printf("No deadlock detected. System is in a safe state.\n");

    return 0;
}


// Process P1 is in deadlock.
// Process P3 is in deadlock.
// Deadlock detected.
