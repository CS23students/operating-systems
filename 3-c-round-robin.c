#include <stdio.h>

int main() {
    int i, n, time, remain, flag = 0, tq;
    int wt = 0, tat = 0, bt[10], rt[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    for (time = 0, i = 0; remain != 0;) {
        if (rt[i] <= tq && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= tq;
            time += tq;
        }

        if (flag == 1 && rt[i] == 0) {
            remain--;
            printf("P%d\t%d\t\t%d\n", i + 1, time, time - bt[i]);
            wt += time - bt[i];
            tat += time;
            flag = 0;
        }

        i = (i + 1) % n;
    }

    printf("\nAverage Waiting Time = %.2f", (float)wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)tat / n);

    return 0;
}


// OP:
// Enter number of processes: 3
// Enter burst time for each process:
// P1: 10
// P2: 5
// P3: 8
// Enter time quantum: 2
// Process  Turnaround Time  Waiting Time
// P1       23               13
// P2       10               5
// P3       21               13

// Average Waiting Time = 10.33
// Average Turnaround Time = 18.00
