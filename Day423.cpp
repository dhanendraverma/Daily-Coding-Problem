/************************************************************************************************************************************************************
This problem was asked by Microsoft.
The transitive closure of a graph is a measure of which vertices are reachable from other vertices. It can be represented as a matrix M, where M[i][j] == 1 
if there is a path between vertices i and j, and otherwise 0.
For example, suppose we are given the following graph in adjacency list form:
graph = [
    [0, 1, 3],
    [1, 2],
    [2],
    [3]
]
The transitive closure of this graph would be:
[1, 1, 1, 1]
[0, 1, 1, 0]
[0, 0, 1, 0]
[0, 0, 0, 1]
Given a graph, find its transitive closure.
************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transitiveClosure(vector<vector<int>>& adj_list){
	int V = adj_list.size();
	vector<vector<int>> closure(V, vector<int>(V,0));
	for(int i=0; i<V; i++){
		for(int j=0; j<adj_list[i].size(); j++)
			closure[i][adj_list[i][j]] = 1;
	}
	
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			for(int k=0; k<V; k++)
				closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
		}
	}
	return closure;
}



int main() {
	vector<vector<int>> adj_list = {{0, 1, 3}, {1, 2}, {2}, {3}};
	vector<vector<int>> transitive_closure = transitiveClosure(adj_list);
	for(auto row:transitive_closure){
		for(auto ele:row)
			cout<<ele<<" ";	
		cout<<endl;
	}
	return 0;
}
