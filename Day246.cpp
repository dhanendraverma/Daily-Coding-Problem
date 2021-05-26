/*****************************************************************************************************************************
This problem was asked by Dropbox.
Given a list of words, determine whether the words can be chained to form a circle. A word X can be placed in front of another
word Y in a circle if the last character of X is same as the first character of Y.
For example, the words ['chair', 'height', 'racket', touch', 'tunic'] can form the following circle:
chair --> racket --> touch --> height --> tunic --> chair
*****************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *adj_list;
	vector<int> in;
	public:
		Graph(int V){
			this->V = V;
			this->adj_list = new list<int>[V];
			this->in = vector<int>(V,0);
		}
		
		void addEdge(int u, int v){
			adj_list[u].push_back(v);
			in[v]++;
		}
		
		bool isEulerianCycle();
		bool isSC();
		void dfs(int u, vector<bool>& visited);
		Graph getTranspose();
};

Graph Graph::getTranspose(){
	Graph gr(V);
	for(int u=0; u<V; u++){
		for(auto v:adj_list[u]){
			gr.addEdge(v,u);
		}
	}
	return gr;
}

void Graph::dfs(int u, vector<bool>& visited){
	visited[u] = true;
	for(auto v:adj_list[u]){
		if(!visited[v])
			dfs(v, visited);
	}
}

bool Graph::isSC(){
	int u;
	for(u=0; u<V; u++){
		if(adj_list[u].size() != 0)
			break;
	}
	
	vector<bool> visited(V, false);
	dfs(u, visited);
	for(int i=0; i<V; i++){
		if(adj_list[i].size() != 0 && !visited[i])
			return false;
	}
	
	Graph gr = getTranspose();
	visited.assign(V, false);
	gr.dfs(u, visited);
	
	for(int i=0; i<V; i++){
		if(gr.adj_list[i].size() != 0 && !visited[i])
			return false;
	}
	
	return true;
}

bool Graph::isEulerianCycle(){
	if(!isSC())
		return false;
	for(int i=0; i<V; i++){
		if(adj_list[i].size() != in[i])
			return false;
	}
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
