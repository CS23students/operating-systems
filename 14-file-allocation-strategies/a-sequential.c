#include <stdio.h>

int main() {
    int files, start, len, i, j, blocks[100] = {0};
    printf("Enter number of files: ");
    scanf("%d", &files);

    for (i = 0; i < files; i++) {
        printf("\nEnter start block and length of file %d: ", i + 1);
        scanf("%d %d", &start, &len);
        
        int flag = 0;
        for (j = start; j < start + len; j++) {
            if (blocks[j] == 1) {
                flag = 1;
                break;
            }
        }

        if (flag)
            printf("Block already allocated, file %d cannot be stored.\n", i + 1);
        else {
            for (j = start; j < start + len; j++)
                blocks[j] = 1;
            printf("File %d allocated from block %d to %d\n", i + 1, start, start + len - 1);
        }
    }
    return 0;
}


// Enter number of files: 2

// Enter start block and length of file 1: 5 3
// File 1 allocated from block 5 to 7

// Enter start block and length of file 2: 6 2
// Block already allocated, file 2 cannot be stored.
