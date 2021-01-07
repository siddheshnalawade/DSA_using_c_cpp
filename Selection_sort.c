#include<stdio.h>

int MIN(int A[],int k,int n)
{
	int LOC,j,min;
	min=A[k];
	LOC=k;
	for(j=k+1;j<=n-1;j++)
	{
	
		if(min>A[j])
		{
			min=A[j];
			LOC=j;
		}
	}
	return LOC;
	
}


int main()
{
	int A[]={58,54,8,78,1,0,7,9,101,99},k,temp,i,LOC;
	for(k=0;k<=8;k++)
	{
			LOC=MIN(A,k,10);
			temp=A[k];
			A[k]=A[LOC];
			A[LOC]=temp;
		
	}
	for(i=0;i<=9;i++)
		{
			printf(" %d",A[i]);
		}
}
