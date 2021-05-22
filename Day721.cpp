/****************************************************************************************************************************
This problem was asked by Microsoft.
Recall that the minimum spanning tree is the subset of edges of a tree that connect all its vertices with the smallest 
possible total edge weight. Given an undirected graph with weighted edges, compute the maximum weight spanning tree.
/****************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge{
	public:
	int src,dest,weight;
	Edge(){}
	Edge(int src, int dest, int  w){
		this->src = src;
		this->dest = dest;
		this->weight = w;
	}
};

class Graph{
	public:
	int V,E;
	vector<Edge> edges;
	Graph(int V, int E){
		this->V = V;
		this->E = E;
		this->edges = vector<Edge>(E);
	}
	
	void addEdge(int src, int dest, int w){
		edges.push_back(Edge(src,dest,w));
	}
};

class subset{
	public:
	int parent,rank;
	subset(){}
	subset(int parent, int rank){
		this->parent = parent;
		this->rank = rank;
	}
};

int find(vector<subset>& subsets, int i){
	if(subsets[i].parent!=i)
		subsets[i].parent = find(subsets,subsets[i].parent);
	return subsets[i].parent;
}

void Union(vector<subset>& subsets, int x, int y){
	int xr = find(subsets,x);
	int yr = find(subsets,y);
	if(subsets[xr].rank<subsets[yr].rank)
		subsets[xr].parent = yr;
	else if(subsets[xr].rank>subsets[yr].rank)
		subsets[yr].parent = xr;
	else{
		subsets[yr].parent = xr;
		subsets[xr].rank++;
	}
}

bool comp(Edge A, Edge B){
	return A.weight>B.weight;
}

void findMST(Graph graph){
	vector<subset> subsets(graph.V);
	for(int i=0;i<graph.V;i++)
		subsets[i] = subset(i,0);		
	sort(graph.edges.begin(),graph.edges.end(),comp);
	vector<Edge> MST(graph.V-1);
	int count=0,curr=0;
	while(count<graph.V-1){
		Edge curr_edge = graph.edges[curr++];
		int x = find(subsets,curr_edge.src);
		int y = find(subsets,curr_edge.dest);
		if(x!=y){
			MST[count++] = curr_edge;
			Union(subsets,x,y);
		}
	}
	for(int i=0;i<(graph.V-1);i++)
		cout<<MST[i].src<<" "<<MST[i].dest<<endl;
	
}

int main() {
	Graph graph(4,5);
	graph.addEdge(0,1,10);
	graph.addEdge(0,2,6);
	graph.addEdge(0,3,5);
	graph.addEdge(1,3,15);
	graph.addEdge(2,3,4);
	findMST(graph);
	return 0;
}
