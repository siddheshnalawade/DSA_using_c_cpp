#include<iostream>

using namespace std;

int BinarySearch(int arr[],int l,int r,int x)
{
	if(l<=r)
	{
		int mid=(l+r)/2;
		
		if(arr[mid]==x)
		{
			return mid;
		}
		if(arr[mid]>x)
		{
			return BinarySearch(arr,l,mid-1,x);
		}
		else
		{
			return BinarySearch(arr,mid+1,r,x);
		}
	}
	return -1;
}

int main()
{
	int arr[]={1,5,8,9,14,25,36,42,58,98};//Sorted array is required for binary search
	int x=36;
	int result=BinarySearch(arr,0,9,x);
	if(result==-1)
	{
		printf("Ele Not Found");
	}
	else
	{
		printf("Ele found at index: %d",result);
	}
}
