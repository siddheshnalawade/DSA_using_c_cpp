#include<stdio.h>

int insertion_sort(int A[], int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=A[i];
		for(j=i-1;j>=0 && temp<A[j];j--)
		{
			A[j+1]=A[j];	
		}
		A[j+1]=temp;

	}
}

void main()
{
	int A[]={41,58,78,1,9},i;
	insertion_sort(A,5);
	for(i=0;i<5;i++)
	{
		printf(" %d",A[i]);
	}
}
