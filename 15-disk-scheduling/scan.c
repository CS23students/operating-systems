#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n, head, i, j, size, seek = 0, dir;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n + 1];
    printf("Enter the requests: ");
    for (i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter direction (0 for left, 1 for right): ");
    scanf("%d", &dir);

    req[n] = head;
    qsort(req, n + 1, sizeof(int), compare);

    for (i = 0; i <= n; i++) if (req[i] == head) break;

    if (dir == 1) {
        for (j = i + 1; j <= n; j++) {
            seek += abs(req[j] - head);
            head = req[j];
        }
        seek += abs((size - 1) - head);
        head = size - 1;
        for (j = i - 1; j >= 0; j--) {
            seek += abs(req[j] - head);
            head = req[j];
        }
    } else {
        for (j = i - 1; j >= 0; j--) {
            seek += abs(req[j] - head);
            head = req[j];
        }
        seek += head;
        head = 0;
        for (j = i + 1; j <= n; j++) {
            seek += abs(req[j] - head);
            head = req[j];
        }
    }

    printf("Total Seek Time: %d\n", seek);
    return 0;
}



// SAMPLE ONLY (MAY BE INCORRECT)
// Enter number of requests: 4
// Enter the requests: 98 183 37 122
// Enter initial head position: 53
// Total Seek Time: 379
