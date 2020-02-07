#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
	int V;
	vector<vector<bool>> tc;
	list<int> *adj;
	public:
	Graph(int V){
		this->V = V;
		adj = new list<int>[V];
		tc = vector<vector <bool>>(V,vector<bool>(V,false));
	}
	
	void addEdge(int u,int v){
		adj[u].push_back(v);
	}
	
	void dfs(int s,int d){
		tc[s][d] = true;
		for(auto v:adj[d]){
			if(!tc[s][v])
				dfs(s,v);
		}
	}
	
	void transitiveClosure(){
		for(int i=0;i<V;i++)
			dfs(i,i);
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++)
				cout<<tc[i][j]<<" ";
			cout<<endl;
		}
	}
};

int main() {
	Graph g(4);
	g.addEdge(0,0);
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,1);
	g.addEdge(1,2);
	g.addEdge(2,2);
	g.addEdge(3,3);
	g.transitiveClosure();
	return 0;
}
