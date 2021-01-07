#include<stdio.h>


void bubble_sort(int A[],int n)
{
	int i,round,temp,flag;
	for(round=1;round<=n-1;round++)
	{	
		flag=0;
		for(i=0;i<=n-1-round;i++)
		{
			if(A[i]>A[i+1])
			{
				flag=1;
				temp=A[i];
				A[i]=A[i+1];
				A[i+1]=temp;
			}	
		}
		if(flag==0)
		{
			printf("Rounds:%d\n",round);
			return;
		}
	}
	
}


void main()
{
	int A[]={15,24,25,85,1},i;
	bubble_sort(A,5);
	for(i=0;i<5;i++)
	{
		printf(" %d",A[i]);
	}
}


