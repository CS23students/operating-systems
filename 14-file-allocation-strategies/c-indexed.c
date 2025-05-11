#include <stdio.h>

int main() {
    int files, index, n, i, j, blocks[50];

    printf("Enter number of files: ");
    scanf("%d", &files);

    for (i = 0; i < files; i++) {
        printf("\nEnter index block for file %d: ", i + 1);
        scanf("%d", &index);

        printf("Enter number of blocks: ");
        scanf("%d", &n);

        printf("Enter blocks: ");
        for (j = 0; j < n; j++)
            scanf("%d", &blocks[j]);

        printf("File %d indexed at block %d with blocks: ", i + 1, index);
        for (j = 0; j < n; j++)
            printf("%d ", blocks[j]);
        printf("\n");
    }

    return 0;
}


// Enter number of files: 1

// Enter index block for file 1: 4
// Enter number of blocks: 3
// Enter blocks: 5 7 9
// File 1 indexed at block 4 with blocks: 5 7 9
