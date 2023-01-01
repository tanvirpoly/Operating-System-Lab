#include<stdio.h>
int main()
{
    int bt[10]= {0},at[10]= {0},tat[10]= {0},wt[10]= {0},ct[10]= {0};
    int n,sum=0;
    float totalTAT=0,totalWT=0;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    printf("Enter Arrival Time and Burst Time for Each Process\n");
    int i, j, k;
    for(i=1; i <= n ; i++)
    {
        printf("\nArrival Time of Process[%d]\t",i);
        scanf("%d",&at[i]);
        printf("Burst Time of Process[%d]\t",i);
        scanf("%d",&bt[i]);
    }
    ct[1] = bt[1];
    for(i=2; i <= n ; i++)
    {
        ct[i] = ct[i-1] + bt[i];
    }
    tat[1] = bt[1];
    totalTAT = totalTAT + tat[1];
    for(i=2; i <= n ; i++)
    {
        tat[i] = tat[i-1] + bt[i] - 1;
        totalTAT = totalTAT + tat[i];
    }
    wt[1] = 0;
    for(i=2; i <= n ; i++)
    {
        wt[i] = tat[i-1] - 1;
        totalWT = totalWT + wt[i];
    }
    printf("Solution:\n\n");
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    for(i=1; i <= n; i++)
    {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Turnaround Time: %f\n",totalTAT/n);
    printf("Average Waiting Time: %f\n",totalWT/n);
    return 0;
}
