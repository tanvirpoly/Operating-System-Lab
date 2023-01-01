#include <stdio.h>
int main()
{
    int p[20], bt[20], at[20], su[20], wt[20], ct[20] = {0}, tat[20], i, j, k, n, temp, sum = 0;
    float wtavg, tatavg;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        p[i]=i;
        printf("Enter the Brust-Time of processes %d : ",i);
        scanf("%d", &bt[i]);
        printf("Enter the arrival-Time of processes %d : ",i);
        scanf("%d", &at[i]);
        printf("System/User processes (0/1) ? : ");
        scanf("%d", &su[i]);
    }
    for(i = 0; i < n; i++)
    {
        for(k=i+1; k < n; k++)
        {
            if( su[i]>su[k] )
            {
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                //Interchange brust time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                //Interchange system/user
                temp = su[i];
                su[i] = su[k];
                su[k] = temp;
            }
        }
    }
    wtavg = 0;
    tatavg = 0;
    for(j=0; j<n; j++)
    {
        sum=sum+ bt[j];
        ct[j] = ct[j]+ sum;
    }
    for(i=0; i<n; i++)
    {
        tat[i] = ct[i]-at[i];
        tatavg = tatavg+tat[i];
    }
    for(i=0; i<n; i++)
    {
        wt[i] = tat[i]-bt[i];
        wtavg = wtavg+wt[i];
    }
    wtavg=wtavg/n;
    tatavg=tatavg/n;
    printf("\nprocess\t system/User process\tBrust Time\t Complete-Time\t Waiting-Time\t Turn-Around-Time \n\n");
    for(i=0; i<n; i++)
    {
        printf("\n %d \t\t  %d \t\t  %d \t\t  %d \t\t  %d \t\t  %d",p[i],su[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time =%f\n",wtavg);
    printf("\nAverage Turnaround time =%f\n",tatavg);

}
