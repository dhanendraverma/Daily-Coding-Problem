/*****************************************************************************************************************************
This problem was asked by Dropbox.
Given a list of words, determine whether the words can be chained to form a circle. A word X can be placed in front of another
word Y in a circle if the last character of X is same as the first character of Y.
For example, the words ['chair', 'height', 'racket', touch', 'tunic'] can form the following circle:
chair --> racket --> touch --> height --> tunic --> chair
*****************************************************************************************************************************/
#include<iostream> 
#include <list> 
#include <vector>
using namespace std; 

class Graph 
{ 
	int V;
	list<int> *adj;
	vector<int> in; 
	public: 
	Graph(int V){
		this->V = V; 
		adj = new list<int>[V]; 
		in = vector<int>(V,0);
	} 
	
	void addEdge(int u, int v) {
		adj[u].push_back(v); 
		in[v]++; 
	} 
	bool isEulerianCycle(); 
	bool isSC(); 
	void dfs(int v, vector<bool>& visited); 
	Graph getTranspose(); 
};

bool Graph::isEulerianCycle() 
{ 
	if (!isSC()) 
		return false; 
	for (int i = 0; i < V; i++) 
		if (adj[i].size()!=in[i]) 
			return false; 
	return true; 
} 

void Graph::dfs(int v, vector<bool>& visited) 
{ 
	visited[v] = true; 
	list<int>::iterator i; 
	for (auto i:adj[v]) 
		if (!visited[i]) 
			dfs(i, visited); 
} 

Graph Graph::getTranspose() 
{ 
	Graph g(V); 
	for (int v = 0; v < V; v++) 
	{ 
		for(auto i:adj[v]) 
		{ 
			g.adj[i].push_back(v); 
			g.in[v]++; 
		} 
	} 
	return g; 
} 

bool Graph::isSC() 
{ 
	vector<bool> visited(V,false); 
	int n; 
	for (n = 0; n < V; n++) 
		if(adj[n].size()) 
			break; 
	dfs(n, visited); 
	for (int i = 0; i < V; i++) 
		if (adj[i].size() > 0 && visited[i] == false) 
			return false; 
	Graph gr = getTranspose(); 
	visited.assign(V,false);
	gr.dfs(n, visited); 
	for (int i = 0; i < V; i++) 
		if (adj[i].size() > 0 && visited[i] == false) 
			return false; 
	return true; 
} 


bool canFormCycle(vector<string> words) 
{ 
	Graph g(26); 
	for (int i = 0; i < words.size(); i++) 
		g.addEdge(words[i][0]-'a', words[i].back()-'a'); 
	return g.isEulerianCycle(); 
} 

 
int main() 
{ 
	vector<string> words  = {"chair", "height", "racket", "touch", "tunic"}; 
	cout<<canFormCycle(words)<<endl;
	return 0; 
} 
