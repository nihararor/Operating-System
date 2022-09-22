#include<stdio.h>
#include<string.h>
int main()
{
    char p[100][100],t[100];
    int arr[100],bur[100],star[100],finish[100],tat[100],wt[100],i,j,n,temp;
    int totalw=0,totaltat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the ProcessName, Arrival Time& Burst Time:");
        scanf("%s%d%d",&p[i],&arr[i],&bur[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                temp=bur[i];
                bur[i]=bur[j];
                bur[j]=temp;
                strcpy(t,p[i]);
                strcpy(p[i],p[j]);
                strcpy(p[j],t);
            }
 
        }
    }
    for(i=0; i<n; i++)
    {
        if(i==0)
            star[i]=arr[i];
        else
            star[i]=finish[i-1];
        wt[i]=star[i]-arr[i];
        finish[i]=star[i]+bur[i];
        tat[i]=finish[i]-arr[i];
    }
    printf("\nProcessName Arrtime Burtime WaitTime Start TurnAroundTime Finish");
    for(i=0; i<n; i++)
    {
        printf("\n%s\t%3d\t%3d\t%3d\t%3d\t%6d\t%6d",p[i],arr[i],bur[i],wt[i],star[i],tat[i],finish[i]);
        totalw+=wt[i];
        totaltat+=tat[i];
    }
    printf("\nAverage Waiting time:%f\n",(float)totalw/n);
    printf("Average Turn Around Time:%f",(float)totaltat/n);
    return 0;
}
