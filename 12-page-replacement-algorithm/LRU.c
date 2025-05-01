#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages[30], frames[10], time[10], n, f, i, j, pos, faults = 0, counter = 0, flag1 = 0, flag2 = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for (i = 0; i < n; ++i) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; ++i) frames[i] = -1;

    printf("\nPage\tFrames\n");
    for (i = 0; i < n; ++i) {
        flag1 = flag2 = 0;

        for (j = 0; j < f; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (!flag1) {
            for (j = 0; j < f; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (!flag2) {
            pos = findLRU(time, f);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < f; ++j) {
            if (frames[j] != -1) printf("%d ", frames[j]);
            else printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}


// Enter no. of pages: 8
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
