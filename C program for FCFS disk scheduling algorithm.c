#include<stdio.h>
int main()
{
    int queue[20],n,head,i,j,k,seek=0,diff;
    float avg;
    printf("Enter the head position: \n");
    scanf("%d",&head);
    printf("Enter the size of Disk queue: \n");
    scanf("%d",&n);
    printf("Enter the queue of disk positions to be read/write: \n");
    for(i=1; i<=n; i++)
        scanf("%d",&queue[i]);
    queue[0]=head;
    for(j=0; j<=n-1; j++)
    {
        diff=abs(queue[j+1]-queue[j]);
        seek+=diff;
    }
    printf("Total seek time is %d\n",seek);
    avg=seek/(float)n;
    printf("Average seek time is %f\n",avg);
    return 0;
}
