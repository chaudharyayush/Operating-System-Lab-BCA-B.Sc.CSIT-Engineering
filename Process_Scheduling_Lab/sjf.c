#include <stdio.h>

int main()
{
    int n, i, j, temp, sum = 0;
    float avg_wt, avg_tat, twt, ttat;
    int bt[20], wt[20], tat[20], p[20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the burst times of processes %d :", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1; // initialize process array in original order
    }

    // sort the burst times in ascending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i]; // sort process array along with burst times array
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // calculate waiting times and turnaround times
    wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        twt += wt[i];
        tat[i] = tat[i - 1] + bt[i];
        ttat += tat[i];
    }

    // print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", twt / n);
    printf("Average turnaround time: %.2f\n", (ttat + tat[0]) / n);

    return 0;
}
