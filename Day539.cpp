/*****************************************************************************************************************************
This problem was asked by Pandora.
Given an undirected graph, determine if it contains a cycle.
******************************************************************************************************************************/

#include<iostream> 
#include <list> 
#include <vector> 
using namespace std; 
 
class Graph{ 
	int V; 
	list<int> *adj; 
	bool isCyclicUtil(int v, bool visited[], int parent){
	    visited[v] = true; 
	    list<int>::iterator i; 
	    for (i = adj[v].begin(); i != adj[v].end(); ++i){ 
	        if (!visited[*i] && isCyclicUtil(*i, visited, v)) 
			    return true;
		    else if (*i != parent) 
		        return true; 
	    } 
	    return false; 
	}
    public: 
	Graph(int V){ 
	    this->V = V;
	    this->adj = new list<int>[V];
	}
	
	void addEdge(int v, int w){
	    adj[v].push_back(w);
	    adj[w].push_back(v);
	}
	
	bool isCyclic(){
	    bool visited[V] = {false};
	    for (int u = 0; u < V; u++) 
		    if(!visited[u] && isCyclicUtil(u, visited, -1))
			    return true; 
		return false; 
	} 
}; 


int main() 
{ 
	Graph g1(5); 
	g1.addEdge(1, 0); 
	g1.addEdge(0, 2); 
	g1.addEdge(2, 1); 
	g1.addEdge(0, 3); 
	g1.addEdge(3, 4); 
	g1.isCyclic()? cout << "Graph contains cycle\n": 
				cout << "Graph doesn't contain cycle\n"; 

	Graph g2(3); 
	g2.addEdge(0, 1); 
	g2.addEdge(1, 2); 
	g2.isCyclic()? cout << "Graph contains cycle\n": 
				cout << "Graph doesn't contain cycle\n"; 

	return 0; 
} 
