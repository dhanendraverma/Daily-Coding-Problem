/**************************************************************************************************************************************
This problem was asked by Dropbox.
Given an undirected graph G, check whether it is bipartite. Recall that a graph is bipartite if its vertices can be divided into two 
independent sets, U and V, such that no edge connects vertices of the same set.
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
	public:
	int V;
	list<int> *adj;
	Graph(int V){
		this->V = V;
		adj = new list<int>[V+1];
	}
	
	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bool DFS(int v,vector<bool>& visited, vector<int>& color){
		for(auto i:adj[v]){
			if(!visited[i]){
				visited[v] = true;
				color[i] = !color[v];
				if(!DFS(i,visited,color))
					return false;
			}
			else if(color[i]==color[v])
				return false;
		}
		return true;
	}
	
	bool isBipertite(){
		vector<int> color(V+1,0);
		vector<bool> visited(V+1,false);
		if(DFS(1,visited,color))
			return true;
		return false;
	}
};

int main() {
	Graph graph(6);
	graph.addEdge(1,2);
	graph.addEdge(2,3);
	graph.addEdge(4,3);
	graph.addEdge(4,5);
	graph.addEdge(5,6);
	graph.addEdge(6,1);
	cout<<graph.isBipertite()<<endl;
	return 0;
}
