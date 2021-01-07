#include<stdio.h>


void bubble_sort(int A[],int n)
{
	int i,round,temp;
	for(round=1;round<=n-1;round++)
	{
		for(i=0;i<=n-1-round;i++)
		{
			if(A[i]>A[i+1])
			{
			temp=A[i];
			A[i]=A[i+1];
			A[i+1]=temp;
		}	
		}
	}
	
}


void main()
{
	int A[]={41,73,8,23,1},i;
	bubble_sort(A,5);
	for(i=0;i<5;i++)
	{
		printf(" %d",A[i]);
	}
}


