#include<stdio.h>  
  void main()  
{        
    int i,process, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avgwt, avgtat;  
    printf(" Total number of process in the system: ");  
    scanf("%d", &process);  
    y = process; 
for(i=0; i<process; i++)  
{  
printf("\n Enter Arrival and Burst time of Process %d\n", i+1);  
printf(" Arrival time is: \t");    
scanf("%d", &at[i]);  
printf(" \nBurst time is: \t"); 
scanf("%d", &bt[i]);  
temp[i] = bt[i];   
}   
printf("Enter the Time Quantum for the process: \t");  
scanf("%d", &quant);  
  
printf("\n Process No \t\t Burst Time \t\t TotalAverageTime \t\t Waiting Time ");  
for(sum=0, i = 0; y!=0; )  
{  
if(temp[i] <= quant && temp[i] > 0) 
{  
    sum = sum + temp[i];  
    temp[i] = 0;  
    count=1;  
    }     
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - quant;  
        sum = sum + quant;    
    }  
    if(temp[i]==0 && count==1)  
    {  
        y--; //decrement the process no.  
        printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
        wt = wt+sum-at[i]-bt[i];  
        tat = tat+sum-at[i];  
        count =0;     
    }  
    if(i==process-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}  
avgwt = wt * 1.0/process;  
avgtat = tat * 1.0/process;  
printf("\n Average Turn Around Time: \t%f", avgwt);  
printf("\n Average Waiting Time: \t%f", avgtat);  
return 0;  
}  
