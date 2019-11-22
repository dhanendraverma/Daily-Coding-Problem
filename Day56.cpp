/****************************************************************************************************************************************
 This problem was asked by Google.
Given an undirected graph represented as an adjacency matrix and an integer k,
write a function to determine whether each vertex in the graph can be colored
such that no two adjacent vertices share the same color using at most k colors.
****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<bool>> graph,vector<int> color,int c, int V){
	for(int i=0;i<V;i++){
		if(graph[V][i] && color[i]==c)
			return false;
	}
	return true;
}

bool graphColoringUtil(vector<vector<bool>>& graph,vector<int>& color, int k,int v){
	if(v==graph.size())
		return true;
	for(int c=1;c<=k;c++){
		if(isSafe(graph,color,c,v)){
			color[v] = c;
			if(graphColoringUtil(graph,color,k,v+1))
				return true;
			color[v] = 0;
		}
	}
	return false;
}


bool graphColoring(vector<vector<bool>> graph,int k){
	vector<int> color(graph.size(),0);
	if(graphColoringUtil(graph,color,k,0))
		return true;
	return false;
}

int main() {
	vector<vector<bool>> graph = {{0, 1, 1, 1}, 
						        {1, 0, 1, 0}, 
						        {1, 1, 0, 1}, 
						        {1, 0, 1, 0}} ;
	int k = 3;
	cout<<graphColoring(graph,k);
	return 0;
}
