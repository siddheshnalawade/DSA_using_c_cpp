#include<stdio.h>

void merge(int *a,int s,int e)
{
	int mid=(s+e)/2;
	int i = s;
	int j = mid+1;
	int k = s;
	int temp[100];
	
	
	while(i<=mid && j<=e)
{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
		}
		
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=e)
	{
		temp[k++]=a[j++];
	}

for(i=0;i<=e;i++)
{
	a[i]=temp[i];
}
}

void mergesort(int a[],int s,int e)
{
	if(s>=e)//return if 0 or 1 ele in arr
	{
		return;
	}
	
	int mid=(s+e)/2;
	
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	
	merge(a,s,e);
	
}

void main()
{
	int a[]={4,5,9,1,5,4,9,1},i;
	mergesort(a,0,8);
	
	for(i=0;i<8;i++)
	{
		printf(" %d",a[i]);
	}
	
}
