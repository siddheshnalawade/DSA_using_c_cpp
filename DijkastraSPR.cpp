#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

template<typename T>
class Graph{
	unordered_map<T,list<pair<T,int>>> m;
	public:
		void addEdge(T u,T v,int dist,bool bidir=true)
		{
			m[u].push_back(make_pair(v,dist));
			if(bidir==true)
			{
				m[v].push_back(make_pair(u,dist));
			}
		}
		
		void printGraph()
		{
			for(auto i:m)
			{
				cout<<i.first<<"->";
				for(auto j:i.second)
				{
					cout<<"("<<j.first<<","<<j.second<<")";
				}
				cout<<endl;
			}
		}
		
		void dijk(T src)
		{
			unordered_map<T,int> dist;
			
			for(auto j:m)
			{
				dist[j.first] = numeric_limits<int>::max();
			}
			
			set<pair<int,T>> s;
			
			dist[src] = 0;
			s.insert(make_pair(0,src));
			while(!s.empty())
			{
				auto p = *(s.begin());
				T node  = p.second;
				
				int nodeDist = p.first;
				s.erase(s.begin());
				
				for(auto childPair:m[node])
				{
					if(nodeDist+childPair.second < dist[childPair.first])
					{
						T dest = childPair.first;
						auto f = s.find(make_pair(dist[dest],dest));
						if(f!=s.end())
						{
							s.erase(f);
						}
						
						dist[dest] =nodeDist+childPair.second;
						s.insert(make_pair(dist[dest],dest));
					}
				}	
			}
			
			cout<<"For Node :"<<src<<endl;
			cout<<"Node  "<<"Distance "<<endl;
			for(auto d:dist)
			{
				cout<<d.first<<"         "<<d.second<<endl;
			}
			cout<<endl;
		}
		
};


int main()
{
	
	Graph<char> g;
	g.addEdge('A','B',1);
	g.addEdge('A','C',4);
	g.addEdge('A','D',7);
	g.addEdge('B','C',1);
	g.addEdge('C','D',2);
	g.dijk('A');
	g.dijk('B');
	g.dijk('C');
	g.dijk('D');
	
	
}
