#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, seek = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the requests: ");
    for (i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
    }

    printf("Total Seek Time: %d\n", seek);
    return 0;
}


// Enter number of requests: 4
// Enter the requests: 98 183 37 122
// Enter initial head position: 53
// Total Seek Time: 379
