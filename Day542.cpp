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
	
	bool DFS(int u, vector<int>& color, int clr){
		color[u] = clr;
		for(auto v:adj[u]){
			if(color[v] == -1){
				if(!DFS(v, color, !clr))
					return false;
			}
			else if(color[u] == color[v])
				return false;
		}
		return true;
	}
	
	bool isBipertite(){
		vector<int> color(V+1,-1);
		for(int i=1; i<=V; i++){
			if(color[i] == -1 && !DFS(i, color, 0))
				return false;
		}
		return true;
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
