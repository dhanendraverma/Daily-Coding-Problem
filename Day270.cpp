/*****************************************************************************************************************************
This problem was asked by Twitter.
A network consists of nodes labeled 0 to N. You are given a list of edges (a, b, t), describing the time t it takes for a 
message to be sent from node a to node b. Whenever a node receives a message, it immediately passes the message on to a 
neighboring node, if possible.
Assuming all nodes are connected, determine how long it will take for every node to receive a message that begins at node 0.
For example, given N = 5, and the following edges:
edges = [
    (0, 1, 5),
    (0, 2, 3),
    (0, 5, 4),
    (1, 3, 8),
    (2, 3, 1),
    (3, 5, 10),
    (3, 4, 5)
]
You should return 9, because propagating the message from 0 -> 2 -> 3 -> 4 will take that much time.
******************************************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
	int V;
	list<pair<int,int>> *edges;
	Graph(int v){
		this->V = v;
		this->edges = new list<pair<int,int>>[v];
	}
	
	void addEdge(int u,int v,int w){
		edges[u].push_back({v,w});
	}
	
	int shortestPath(){
		set<pair<int,int>> setds;
		vector<int> dist(V,INT_MAX);
		setds.insert({0,0});
		dist[0] = 0;
		while(!setds.empty()){
			pair<int,int> tmp = *(setds.begin());
			setds.erase(setds.begin());
			int u = tmp.second;
			for(auto edge:edges[u]){
				int v = edge.first;
				int w = edge.second;
				if(dist[v]>dist[u]+w){
					if(dist[v]!=INT_MAX)
						setds.erase(setds.find({dist[v],v}));
					dist[v] = dist[u]+w;
					setds.insert({dist[v],v});
				}
			}
		}
		int ans = 0;
		for(auto time:dist)
			ans = max(ans,time);
		return ans;
	}
	
};

int main() {
	Graph g(6);
	g.addEdge(0,1,5);
	g.addEdge(0,2,3);
	g.addEdge(0,5,4);
	g.addEdge(1,3,8);
	g.addEdge(2,3,1);
	g.addEdge(3,5,10);
	g.addEdge(3,4,5);
	cout<<g.shortestPath()<<endl;
	return 0;
}
