#include<iostream>

using namespace std;

//Adjacancy Matrix
int main()
{
	int N;
	cout<<"Enter No of Vertices"<<endl;
	cin>>N;
	
	char NodeList[N];
	cout<<"Enter Node"<<endl;
	for(int i=0;i<N;i++)
	{
		cin>>NodeList[i];
	}
	int AdjMatrix[N][N];
	for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	{
		AdjMatrix[i][j]=0;
	}
}
	cout<<"Enter Number of edges"<<endl;
	int edges;
	cin>>edges;
	cout<<"Enter Two vertex in between you want edges"<<endl;
	for(int i=0;i<edges;i++)
	{
	char first,last;
	cout<<"Enter First: ";
	cin>>first;
	cout<<"Enter last: ";
	cin>>last;
	int id1=-1,id2=-1;
	for(int j=0;j<N;j++)
	{
		if(NodeList[j]==first)
		{
			id1=j;
		}
		if(NodeList[j]==last)
		{
			id2=j;
		}
		
	}
	AdjMatrix[id1][id2]=1;
	cout<<AdjMatrix[id1][id2]<<endl;
	
}

for(int i=0;i<N;i++)
{
	for(int j=0;j<N;j++)
	{
		cout<<AdjMatrix[i][j]<<" ";
	}
	cout<<endl;
}
	
	return 0;
}
