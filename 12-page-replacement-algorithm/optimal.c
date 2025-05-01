#include <stdio.h>

int search(int key, int fr[], int f) {
    for (int i = 0; i < f; i++) if (fr[i] == key) return 1;
    return 0;
}

int predict(int pages[], int fr[], int n, int index, int f) {
    int res = -1, farthest = index;
    for (int i = 0; i < f; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (fr[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n) return i;
    }
    return (res == -1) ? 0 : res;
}

int main() {
    int n, f, pages[100], fr[10], faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);
    int cnt = 0;

    printf("\nPage\tFrames\n");
    for (int i = 0; i < n; i++) {
        if (search(pages[i], fr, cnt)) {
            // Hit
        } else {
            if (cnt < f) fr[cnt++] = pages[i];
            else {
                int j = predict(pages, fr, n, i + 1, f);
                fr[j] = pages[i];
            }
            faults++;
        }

        printf("%d\t", pages[i]);
        for (int j = 0; j < cnt; j++) printf("%d ", fr[j]);
        for (int j = cnt; j < f; j++) printf("- ");
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
// 3       0 2 3
// 0       0 2 3
// 4       0 3 4

// Total Page Faults = 6
