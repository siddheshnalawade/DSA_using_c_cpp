#include<iostream>
#include<queue>

using namespace std;

struct node{
	int data;
	struct node* next;
};

int insert_node(int,int,struct node*);
void BFS(struct node*,int);
void DFS(struct node*,int *,int u);
int main()
{
	int n=4;
	int visited[n]={0};
	struct node graph[n];
	for(int i=0;i<n;i++)
	{
		graph[i].data=i;
		graph[i].next=NULL;
	}
	
	insert_node(0,1,&graph[0]);
	insert_node(1,0,&graph[1]);
	insert_node(1,2,&graph[1]);
	insert_node(2,1,&graph[2]);
	insert_node(2,3,&graph[2]);
	insert_node(3,2,&graph[3]);
	insert_node(0,3,&graph[0]);
	insert_node(3,0,&graph[3]);
	
	cout<<"BFS:";
	BFS(graph,n);
	cout<<endl;
	cout<<"DFS:";
	DFS(graph,visited,0);
	
}

int insert_node(int f,int l,struct node *start)
{
	int status=0;
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data=l;
	new_node->next=NULL;
	if(start->next==NULL)
	{
		start->next=new_node;
		status=1;
		
	}
	else
	{
		struct node* temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		status=1;
	}
	return status;
}

void BFS(struct node* start,int n)
{
	if(start==NULL)
	{
		cout<<"Empty Graph"<<endl;
	}
	else
	{
		queue<int> q;
		int visited[n]={0};
		q.push(0);
		visited[0]=1;
		while(!q.empty())
		{
			int data=q.front();
			q.pop();
			cout<<data<<" ";
			struct node *temp=&start[data];
			while(temp->next!=NULL)
			{
				temp=temp->next;
				if(visited[temp->data]==0)
				{
				q.push(temp->data);
				visited[temp->data]=1;
				}
			}
			
		}
		
		
	}
}

void DFS(struct node* start,int *visited,int u)
{
	if(start==NULL)
	{
		return;
	}
	else
	{
		struct node*  temp=&start[u];
		cout<<u<<" ";
		visited[u]=1;
		while(temp)
		{
			temp=temp->next;
			if(temp!=NULL)
			{
			if(visited[temp->data]==0)
			{
				
				DFS(start,visited,temp->data);
			}
			}
			
			
		}
	}
}
