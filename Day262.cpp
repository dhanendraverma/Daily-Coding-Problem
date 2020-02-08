#include <iostream>
#include <list>
#include <vector>
#include <climits>
using namespace std;

class Graph{
	int V;
	list<int>* adj;
	public:
	Graph(int V){
		this->V = V;
		adj = new list<int>[V];
	}
	
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	void dfs(int u, vector<bool>& visited, vector<int>& visited_time, vector<int>& low_time, vector<int>& parent){
		visited[u] = true;
		static int time  = 0;
		visited_time[u] = low_time[u] = time++; //if visited first time update the visited time
		for(auto v:adj[u]){
			if(!visited[v]){
				parent[v] = u; //first time v was visited through u
				dfs(v,visited,visited_time,low_time,parent);
				low_time[u] = min(low_time[v],low_time[u]); //get the vertex with the lowest visited_time which is reachable from the u
				if(visited_time[u]<low_time[v]) //if the visited time for the parent vertex is lower than the low_time for the 
          cout<<u<<" "<<v<<endl; //adjacent v then 
					 //there is no back edge and hence no other way to visit v except through u hence u-v is a bridge
			}
			else if(parent[u]!=v)
				low_time[u] = min(low_time[u],visited_time[v]);//checking throug all the adjacent which is the earliest vertex 
                                                      //reachable from u
		}
	}
	
	void findBridges(){
		vector<bool> visited(V,false); //keeps track of the vertex visited so far so avoid the cyclic visit
		vector<int> visited_time(V,INT_MAX); //time/distance from the source the when it's visited in current dfs call
		vector<int> low_time(V,INT_MAX); //the visited_time of the earliest vertex which is reachable from the vertex
		vector<int> parent(V,-1); //parent of the vertex
		for(int i=0;i<V;i++){
			if(!visited[i]){
				dfs(i,visited,visited_time,low_time,parent);
			}
		}
	}
};

int main() {
	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(4,6);
	g.addEdge(5,7);
	g.findBridges();
	return 0;
}
