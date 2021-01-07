#include<iostream>
#include<stdlib.h>
#include<queue>

#define MaxNode 6
using namespace std;


void addNode(int s,int d);
void printList();
//void DFS();
void BFS();

typedef struct Node{
	int data;
	struct Node *next;
	bool visited=false;
}Node;

typedef struct List{
	Node *head;
}List;

List *AdjList[MaxNode]={0};


int main()
{
	int i=0;
	for(int i=0;i<MaxNode;i++)
	{
		AdjList[i]=(List*)malloc(sizeof(List));
		AdjList[i]->head=NULL;
	}
	addNode(0,1);
	addNode(0,2);
	addNode(0,3);
	addNode(1,2);
	addNode(1,0);
	addNode(2,1);
	addNode(2,0);
	addNode(2,3);
	addNode(3,0);
	addNode(3,2);
	addNode(1,4);
	addNode(4,5);
	
	printList();
	BFS();

	
}

void addNode(int s,int d)
{
	Node *src,*dest , *temp;
	if(AdjList[s]->head==NULL)
	{
		src=(Node*)malloc(sizeof(Node));
		src->data=s;
		src->next=NULL;
		AdjList[s]->head=src;
	}
	
	dest=(Node*)malloc(sizeof(Node));
	
	temp=AdjList[s]->head;
	dest->data=d;
	dest->next=NULL;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=dest;	
}

void printList()
{
	int i;
	for(i=0;i<MaxNode;i++)
	{
		printf("List for vertex %d:\n",i);
		Node *p=AdjList[i]->head;
		while(p)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
	}
}

void BFS()
{
	queue <int> q;
	int i;
	int visited[MaxNode];
	int size=0;
	for(int i=0;i<MaxNode;i++)
	{
		
		Node *tmp;
		tmp=AdjList[i]->head;
		
		while(tmp)
		{
		
			if(tmp->visited==false)
			{
			int x=tmp->data;
			q.push(x);
			tmp->visited=true;	
			}
			tmp=tmp->next;
		}
		int y=q.front();
		int flag=0;
		for(int j=0;j<size;j++)
		{
			if(y==visited[j])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			visited[size]=y;
			size++;
		}
		q.pop();
	}
	
	for(int i=0;i<MaxNode;i++)
{
	cout<<visited[i]<<" "; 
}
}
