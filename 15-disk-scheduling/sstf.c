#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}

int main() {
    int n, i, j, head, seek = 0, min, pos;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n], done[n];
    printf("Enter the requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        done[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++) {
        min = 1e9;
        for (j = 0; j < n; j++) {
            if (!done[j] && abs_diff(req[j], head) < min) {
                min = abs_diff(req[j], head);
                pos = j;
            }
        }
        seek += abs_diff(req[pos], head);
        head = req[pos];
        done[pos] = 1;
    }

    printf("Total Seek Time: %d\n", seek);
    return 0;
}

// SAMPLE ONLY (MAY BE INCORRECT)
// Enter number of requests: 4
// Enter the requests: 98 183 37 122
// Enter initial head position: 53
// Total Seek Time: 379
