/**************************************************************************************************************************************
This problem was asked by Yahoo.
Write an algorithm that computes the reversal of a directed graph. For example, if a graph consists of A -> B -> C, it should become 
A <- B <- C.
***************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Graph{
	public:
	int V;
	vector<vector<int>> adj;
	Graph(int V){
		this->V;
		this->adj = vector<vector<int>>(V);
	}
	
	void addEdge(int u, int v){
		adj[u].push_back(v);
	}
	
	void printGraph(){
		for(int u=0;u<adj.size();u++){
			for(auto v:adj[u])
				cout<<u<<"->"<<v<<endl;
		}
	}
};

void reverseGraph(Graph g){
	Graph rgraph(g.V);
	for(int u=0;u<g.adj.size();u++){
		for(auto v:g.adj[u])
			rgraph.addEdge(v,u);
	}
	cout<<"After reversing the edges"<<endl;
	rgraph.printGraph();
}

int main() {
	int V = 5;
	Graph graph(5);
	graph.addEdge(0, 1); 
    graph.addEdge(0, 4); 
    graph.addEdge(0, 3); 
    graph.addEdge(2, 0); 
    graph.addEdge(3, 2); 
    graph.addEdge(4, 1); 
    graph.addEdge(4, 3);
    graph.printGraph();
    reverseGraph(graph);
	return 0;
}
