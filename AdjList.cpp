#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph{
	int V;
	list<int> *l;
	
public:
	Graph(int V)
	{
		this->V=V;
		l = new list<int>[V];
	}
	
	void addEdge(int s,int d)
	{
		l[s].push_back(d);
		l[d].push_back(s);
	}
	
	void printList()
	{
		for(int i=0;i<V;i++)
		{
			cout<<"Vertex "<<i<<"->";
			for(int nbr:l[i]){
				cout<<nbr<<",";				
			}
			cout<<endl;
		}
	}
	
void BFS(int s) 
{ 
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
    {
    	visited[i]=false;
	}
	
	list<int> queue;
	visited[s]=true;
	queue.push_front(s);
	
	list<int>::iterator i;
	
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		
		for(i=l[s].begin();i!=l[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
		}
	}
} 

void DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = l[v].begin(); i != l[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited); 
} 
	
};


int main()
{
	Graph g(4);//bidirectional graph;
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(1,2);
	g.printList();
	
	g.BFS(0);
	cout<<endl;
	g.DFS(0);
}
