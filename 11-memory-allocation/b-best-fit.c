#include <stdio.h>
#include <string.h>

int main() {
    int blockSize[30], processSize[30], allocation[30];
    int blocks, processes;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);
    printf("Enter size of each block:\n");
    for (int i = 0; i < blocks; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter size of each process:\n");
    for (int i = 0; i < processes; i++)
        scanf("%d", &processSize[i]);

    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < processes; i++) {
        int best = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (best == -1 || blockSize[j] < blockSize[best])
                    best = j;
            }
        }
        if (best != -1) {
            allocation[i] = best;
            blockSize[best] -= processSize[i];
        }
    }

    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d (Size %d) -> ", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("Block %d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}


// Enter number of memory blocks: 5
// Enter size of each block:
// 100 500 200 300 600
// Enter number of processes: 4
// Enter size of each process:
// 212 417 112 426
// Best Fit Allocation:
// Process 1 (Size 212) -> Block 3
// Process 2 (Size 417) -> Block 5
// Process 3 (Size 112) -> Block 1
// Process 4 (Size 426) -> Not Allocated
