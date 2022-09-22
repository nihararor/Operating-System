#include<stdio.h>
void main()
{
	int blsize[10], psize[10], blno, pno, flags[10], allocation[10], i, j;
	for(i = 0; i < 10; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}
	printf("Enter no. of blocks: ");
	scanf("%d", &blno);
	printf("\nEnter size of each block: ");
	for(i = 0; i < blno; i++)
		scanf("%d", &blsize[i]);
	printf("\nEnter no. of processes: ");
	scanf("%d", &pno);
	printf("\nEnter size of each process: ");
	for(i = 0; i < pno; i++)
		scanf("%d", &psize[i]);
	for(i = 0; i < pno; i++)        
		for(j = 0; j < blno; j++)
			if(flags[j] == 0 && blsize[j] >= psize[i])
			{
				allocation[j] = i;
				flags[j] = 1;
				break;
			}
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < blno; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, blsize[i]);
		if(flags[i] == 1)
			printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
		else
			printf("Not allocated");
	}
}
