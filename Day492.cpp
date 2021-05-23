/**************************************************************************************************************************************************************
This problem was asked by Google.
Given an undirected graph represented as an adjacency matrix and an integer k, write a function to determine whether each vertex in the graph can be colored
such that no two adjacent vertices share the same color using at most k colors.
**************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canColorGraph(vector<vector<int>>& graph, int k){
	int V = graph.size();
	vector<bool> visited(V+1, false);
	vector<int> color(V,1);
	int max_colors = 0;
	for(int u=0; u<V; u++){
		
		if(visited[u])
			continue;
		
		visited[u] = true;
		queue<int> q;
		q.push(u);
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(int i=0; i<V; i++){
				if(graph[v][i] && color[v] == color[i]){
					color[i]++;
					max_colors = max(max_colors,max(color[v], color[i]));
					if(max_colors > k)
						return false;
					if(!visited[i]){
						visited[i] = true;
						q.push(i);
					}
				}
			}
		}
		
	}
	return true;
}


bool isSafe(vector<vector<int>>& graph, int v, vector<int>& color, int c){
	for(int i=0; i<graph[v].size(); i++)
		if(graph[v][i] && color[i] == c)
			return false;
	return true;
}

bool colorGraphRec(vector<vector<int>>& graph, int v, vector<int>& color, int k){
	if(v == graph.size())
		return true;
	for(int c=1; c<=k; c++){
		if(isSafe(graph, v, color, c)){
			color[v] = c;
			if(colorGraphRec(graph, v+1, color, k))
				return true;
			color[v] = 0;
		}
	}
	return false;
}

bool isPossibleKcolor(vector<vector<int>>& graph, int k){
	vector<int> color(graph.size(),0);
	return colorGraphRec(graph, 0, color, k);
}


int main() {
	vector<vector<int>> adj_mat = {{0, 1, 1, 1}, 
						        {1, 0, 1, 0}, 
						        {1, 1, 0, 1}, 
						        {1, 0, 1, 0}} ;
	int k = 3;
	cout<<isPossibleKcolor(adj_mat, k)<<endl;
	cout<<canColorGraph(adj_mat, k)<<endl;
	return 0;
}
