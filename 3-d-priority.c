#include <stdio.h>

int main() {
    int n, i, j, temp;
    int bt[20], p[20], pr[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d (Burst Time, Priority): ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
        p[i] = i + 1;
    }

    // Sorting based on priority
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}



// OP
// Enter number of processes: 4
// Enter burst time and priority for each process:
// P1 (Burst Time, Priority): 10 3
// P2 (Burst Time, Priority): 1 1
// P3 (Burst Time, Priority): 2 4
// P4 (Burst Time, Priority): 1 2
// Process  Burst Time  Priority  Waiting Time  Turnaround Time
// P2       1           1         0             1
// P4       1           2         1             2
// P1       10          3         2             12
// P3       2           4         12            14

// Average Waiting Time = 3.75
// Average Turnaround Time = 7.25
