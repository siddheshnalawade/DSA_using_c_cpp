#include<iostream>

using namespace std;

int partition(int *a,int s,int e)
{
	int i=s-1;
	int j=s;
	int p = a[e];
	
	for(;j<e;j++)
	{
		if(a[j]<p)//if any ele is small then piv	ot then it move to the small region
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}

void quicksort(int a[],int s,int e)
{
	if(s>=e)
	{
		return;
	}
	
	int p = partition(a,s,e);
	quicksort(a,s,p-1);
	quicksort(a,p+1,e);	
}

int main()
{
	int a[]={2,5,1,7,9},i;
	quicksort(a,0,4);
	for(i=0;i<=4;i++)
	{
		printf(" %d",a[i]);
	}
	
}
