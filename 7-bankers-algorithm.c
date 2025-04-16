#include <stdio.h>
#include <stdbool.h>

#define P 5 // Number of processes
#define R 3 // Number of resources

int main() {
    int i, j;

    // Allocation Matrix
    int alloc[P][R] = { {0, 1, 0}, 
                        {2, 0, 0}, 
                        {3, 0, 2}, 
                        {2, 1, 1}, 
                        {0, 0, 2} };

    // Maximum Demand Matrix
    int max[P][R] = { {7, 5, 3}, 
                      {3, 2, 2}, 
                      {9, 0, 2}, 
                      {2, 2, 2}, 
                      {4, 3, 3} };

    // Available Resources
    int avail[R] = {3, 3, 2};

    // Need Matrix
    int need[P][R];
    for (i = 0; i < P; i++)
        for (j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Finish array and safe sequence
    bool finish[P] = {0};
    int safeSeq[P];
    int work[R];

    for (i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < P) {
        bool found = false;

        for (i = 0; i < P; i++) {
            if (!finish[i]) {
                bool canAllocate = true;

                for (j = 0; j < R; j++)
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }

                if (canAllocate) {
                    for (j = 0; j < R; j++)
                        work[j] += alloc[i][j];

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("System is not in a safe state (Deadlock possible)\n");
            return 1;
        }
    }

    // Print safe sequence
    printf("System is in a safe state.\nSafe sequence is: ");
    for (i = 0; i < P; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}


// System is in a safe state.
// Safe sequence is: P1 P3 P4 P0 P2
