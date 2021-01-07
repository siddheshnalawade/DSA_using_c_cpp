#include<stdio.h>


int counting_sort(int A[],int B[],int N,int K)
{
	int i,j;
	int C[K];
	for(i=0;i<K;i++)
	{
		C[i]=0;
	}
	
	for(j=0;j<N;j++)
	{
		C[A[j]]=C[A[j]]+1;
	}
	
	for(i=1;i<K;i++)
	{
		C[i]=C[i]+C[i-1];
	}
	
	for(j=N-1;j>=0;j--)
	{
		B[C[A[j]]-1]=A[j];
		C[A[j]]=C[A[j]]-1;
	}
}
void main()
{
	int A[]={5,9,4,5,3,6,8,5,4,8,7,4,6,9,7},N=15,K=10,i;
	int B[N];
	counting_sort(A,B,N,K);
	for(i=0;i<N;i++)
	{
		printf(" %d",B[i]);
	}
	
}
