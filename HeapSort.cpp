#include<iostream>
#include<stdlib.h>

using namespace std;

#define max 100

void heapify(int heap[],int n,int i)
{
	
	while(i<n)
	{
		int parent=i;
		int left=2*i+1;
		int right=2*i+2;
		if(left<n && heap[left]>heap[parent])
		{
			parent=left;
		}
		if(right<n && heap[right]>heap[parent])
		{
			parent=right;
		}
		if(parent!=i)
		{
			swap(heap[i],heap[parent]);
		}
		if(parent==left)
		{
			i=2*i+1;
		}
		else
		{
			i=2*i+2;
		}
	}
}


void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}


void heap_sort(int heap[],int n)
{
	//build heap
	for(int i=n/2-1 ; i>=0 ; i--)
	{
		heapify(heap,n,i);
	}
	//move root to last
	for(int i=n-1;i>0;i--)
	{
	
		swap(heap[0],heap[i]);
		heapify(heap,i,0);
	}
}

int main()
{
	int heap[max]={18,5,78,64,7,1,0,66,98,35};
	int n=10;
	
	heap_sort(heap,n);
	print(heap,n);
	
}

