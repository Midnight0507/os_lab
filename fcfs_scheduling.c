#include <stdio.h>

int main() {
    int bt[10] = {0}, at[10] = {0}, tat[10] = {0}, wt[10] = {0}, ct[10] = {0};
    int n, sum = 0;
    float totalTAT = 0, totalWT = 0;
    
    // Hardcoded values for the example
    n = 5;
    int arrivalTimes[] = {0, 20, 10, 20, 50};
    int burstTimes[] = {80, 20, 10, 20, 50};
    
    // Use hardcoded values for this problem
    for (int i = 0; i < n; i++) {
        at[i] = arrivalTimes[i];
        bt[i] = burstTimes[i];
    }

    // Calculate finish times for FCFS scheduling
    for (int j = 0; j < n; j++) {
        if (j == 0) {
            ct[j] = bt[j];
        } else {
            ct[j] = ct[j - 1] + bt[j];
        }
    }

    // Calculate turnaround time and waiting time
    for (int k = 0; k < n; k++) {
        tat[k] = ct[k] - at[k];
        totalTAT += tat[k];
    }

    for (int k = 0; k < n; k++) {
        wt[k] = tat[k] - bt[k];
        totalWT += wt[k];
    }

    // Print the Gantt chart and results
    printf("Gantt Chart:\n");
    printf("| ");
    for (int i = 0; i < n; i++) {
        printf("P%d | ", i + 1);
    }
    printf("\n");

    printf("0 ");
    for (int i = 0; i < n; i++) {
        printf("  %d ", ct[i]);
    }
    printf("\n");

    printf("Solution:\n\n");
    printf("JOBNO\t AT\t BT\t FT\t TAT\t WT\t\n\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %f\n", totalTAT / n);
    printf("Average Waiting Time = %f\n\n", totalWT / n);

    // Specific turnaround time for process P3 (index 2)
    printf("Turnaround Time for Process P3 = %d\n", tat[2]);

    return 0;
}
