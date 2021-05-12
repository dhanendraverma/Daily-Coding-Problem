/**************************************************************************************************************************************************************
This problem was asked by Google.
Given an undirected graph represented as an adjacency matrix and an integer k, write a function to determine whether each vertex in the graph can be colored
such that no two adjacent vertices share the same color using at most k colors.
**************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool canUseClr(vector<vector<int>>& graph, int clr, vector<int>& color, int v){
	for(int i=0; i<graph.size(); i++){
		if(graph[v][i] && color[i]==clr)
			return false;
	}
	return true;
}

bool colorGraphRec(vector<vector<int>>& graph, int k, vector<int>& color, int v){
	if(v >= graph.size())
		return true;
	for(int clr=0; clr<k; clr++){
		if(canUseClr(graph, clr, color, v)){
			color[v] = clr;
			if(colorGraphRec(graph, k, color, v+1))
				return true;
			color[v] = -1;
		}
	}
	return false;
}

bool canColoredWithK(vector<vector<int>>& graph, int k){
	int V = graph.size();
	vector<int> color(V, -1);
	if(colorGraphRec(graph, k, color, 0));
		return true;
	return false;
}

int main() {
	vector<vector<int>> graph = {{0, 1, 1, 1}, 
						        {1, 0, 1, 0}, 
						        {1, 1, 0, 1}, 
						        {1, 0, 1, 0}} ;
	int k=3;
	cout<<canColoredWithK(graph, k)<<endl;
	return 0;
}
