#include <stdio.h>

int main() {
    int pages[30], n, frames[10], f, i, j = 0, k, flag = 0, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) frames[i] = -1;

    printf("\nPage\tFrames\n");
    for (i = 0; i < n; i++) {
        flag = 0;
        for (k = 0; k < f; k++) {
            if (frames[k] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            frames[j] = pages[i];
            j = (j + 1) % f;
            faults++;
        }

        printf("%d\t", pages[i]);
        for (k = 0; k < f; k++) {
            if (frames[k] != -1) printf("%d ", frames[k]);
            else printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}


// Reference String: 7 0 1 2 0 3 0 4
// Frames: 3
// Page    Frames
// 7       7 - -
// 0       7 0 -
// 1       7 0 1
// 2       0 1 2
// 0       0 1 2
// 3       1 2 3
// 0       2 3 0
// 4       3 0 4

// Total Page Faults = 7
