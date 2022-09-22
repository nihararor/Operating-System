#include<stdio.h>
int main()
{
      int bursttime[20], process[20], waitingtime[20], turnaroundtime[20], priority[20];
      int i, j, limit, sum = 0, position, temp;
      float averagewaittime, averageturnaroundtime;
      printf("Enter Total Number of Processes:\t");
      scanf("%d", &limit);
      printf("\nEnter Burst Time and Priority For %d Processes\n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nProcess %d\n", i + 1);
            printf("Process Burst Time:\t");
            scanf("%d", &bursttime[i]);
            printf("Process Priority:\t");
            scanf("%d", &priority[i]);
            process[i] = i + 1;
      }
      for(i = 0; i < limit; i++)
      {
            position = i;
            for(j = i + 1; j < limit; j++)
            {
                  if(priority[j] < priority[position])
                  {
                        position = j;
                  }
            }
            temp = priority[i];
            priority[i] = priority[position];
            priority[position] = temp; 
            temp = bursttime[i];
            bursttime[i] = bursttime[position];
            bursttime[position] = temp;
            temp = process[i];
            process[i] = process[position];
            process[position] = temp;
      }
      waitingtime[0] = 0;
      for(i = 1; i < limit; i++)
      {
            waitingtime[i] = 0;
            for(j = 0; j < i; j++)
            {
                  waitingtime[i] = waitingtime[i] + bursttime[j];
            }
            sum = sum + waitingtime[i];
      }
      averagewaittime = sum / limit;
      sum = 0;
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < limit; i++)
      {
            turnaroundtime[i] = bursttime[i] + waitingtime[i];
            sum = sum + turnaroundtime[i];
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], bursttime[i], waitingtime[i], turnaroundtime[i]);
      }
      averageturnaroundtime = sum / limit;
      printf("\nAverage Waiting Time:\t%f", averagewaittime);
      printf("\nAverage Turnaround Time:\t%f\n", averageturnaroundtime);
      return 0;
}
