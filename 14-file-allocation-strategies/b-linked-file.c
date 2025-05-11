#include <stdio.h>

int main() {
    int files, n, i, j, block[100], used[100] = {0};

    printf("Enter number of files: ");
    scanf("%d", &files);

    for (i = 0; i < files; i++) {
        printf("\nEnter number of blocks for file %d: ", i + 1);
        scanf("%d", &n);
        printf("Enter block numbers: ");
        for (j = 0; j < n; j++) {
            scanf("%d", &block[j]);
            if (used[block[j]]) {
                printf("Block %d already used!\n", block[j]);
                break;
            }
            used[block[j]] = 1;
        }

        if (j == n) {
            printf("File %d is allocated using linked allocation: ", i + 1);
            for (j = 0; j < n - 1; j++)
                printf("%d -> ", block[j]);
            printf("%d\n", block[n - 1]);
        }
    }

    return 0;
}


// Enter number of files: 1

// Enter number of blocks for file 1: 4
// Enter block numbers: 2 5 8 10
// File 1 is allocated using linked allocation: 2 -> 5 -> 8 -> 10
