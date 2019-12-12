/***************************************************************************************************************************************
This problem was asked by Facebook.
A graph is minimally-connected if it is connected and there is no edge that can be removed while still leaving the graph connected. For 
example, any binary tree is minimally-connected.
Given an undirected graph, check if the graph is minimally-connected. You can choose to represent the graph as either an adjacency 
matrix or adjacency list.
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
		adj = new list<int>[V]; 
	}
	
	void addEdge(int u, int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bool isCyclic(int v, vector<bool>& visited, int parent){
		visited[v] = true;
		for(auto itr = adj[v].begin(); itr!=adj[v].end(); itr++){
			if(!visited[*itr]){
				if(isCyclic(*itr,visited,v))
					return true;
			}
			else if(*itr!=parent)
				return true;
		}
		return false;
	}
	
	bool isMinConn(){
		vector<bool> visited(V,false);
		if(isCyclic(0,visited,-1))
			return false;
		for(int i=0;i<V;i++){
			if(!visited[i])
				return false;
		}
		return true;
	}
};

int main() {
	Graph g1(5); 
	g1.addEdge(1, 0); 
	g1.addEdge(0, 2); 
	g1.addEdge(0, 3); 
	g1.addEdge(3, 4); 
	cout<<g1.isMinConn()<<endl;
	return 0;
}
