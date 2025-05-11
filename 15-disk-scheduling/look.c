#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int i, n, head, dir, seek = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n + 1];

    printf("Enter the requests: ");
    for (i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0 for left, 1 for right): ");
    scanf("%d", &dir);

    req[n] = head;
    n++;
    qsort(req, n, sizeof(int), compare);

    int idx;
    for (i = 0; i < n; i++) if (req[i] == head) { idx = i; break; }

    if (dir == 1) {
        for (i = idx + 1; i < n; i++) {
            seek += abs(req[i] - head);
            head = req[i];
        }
        for (i = idx - 1; i >= 0; i--) {
            seek += abs(req[i] - head);
            head = req[i];
        }
    } else {
        for (i = idx - 1; i >= 0; i--) {
            seek += abs(req[i] - head);
            head = req[i];
        }
        for (i = idx + 1; i < n; i++) {
            seek += abs(req[i] - head);
            head = req[i];
        }
    }

    printf("Total Seek Time: %d\n", seek);
    return 0;
}


// SAMPLE ONLY (MAY BE INCORRECT)
// Enter number of requests: 5
// Enter the requests: 95 180 34 119 11
// Enter initial head position: 50
// Enter disk size: 200
// Total Seek Time: 382
