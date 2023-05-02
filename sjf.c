#include <stdio.h>
int main()
{
    int n;
    printf("enter the no.of processes: \n");
    scanf("%d", &n);
    int bursttime[n];
    int arrivaltime[n];
    int waitingtime[n];
    int finishtime[n];
    int turnaroundtime[n];
    int waiting = 0;
    int turnaround = 0;
    float avgwaitingtime = 0.0;
    float avgturnaroundtime = 0.0;
    for (int i = 0; i < n; i++)
    {
        printf("enter the burst time of process %d\n", i + 1);
        scanf("%d", &bursttime[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arrivaltime[i] = 0;
    }
    //sorting the process in ascending order acccording to the burst time
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bursttime[i] > bursttime[j])
            {
                int temp;
                temp = bursttime[i];
                bursttime[i] = bursttime[j];
                bursttime[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d", bursttime[i]);
    }
    finishtime[0] = bursttime[0];
    waitingtime[0] = 0;
    turnaroundtime[0] = bursttime[0];

    for (int i = 1; i < n; i++)
    {
        finishtime[i] = finishtime[i - 1] + bursttime[i];
        waitingtime[i] = waitingtime[i - 1] + bursttime[i - 1];
        turnaroundtime[i] = finishtime[i] - arrivaltime[i];
    }
    for (int i = 0; i < n; i++)
    {
        waiting = waiting + waitingtime[i];
        turnaround = turnaround + turnaroundtime[i];
    }
    // printing
    avgturnaroundtime = turnaround / (float)n;
    avgwaitingtime = waiting / (float)n;
    printf("\nSJF DISK SCHEDULING:\n");
    printf("PROCESS NO.\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURNAROUNDTIME\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bursttime[i], arrivaltime[i], waitingtime[i], turnaroundtime[i]);
    }
    printf("\nAVERAGE WAITING TIME OF Sjf IS = %f\n", avgwaitingtime);
    printf("\nAVERAGE TURNAROUND TIME OF sjf IS = %f", avgturnaroundtime);
    return 0;
}
