/**************************************************************************************************************************************
This problem was asked by Google.
In a directed graph, each node is assigned an uppercase letter. We define a path's value as the number of most frequently-occurring 
letter along that path. For example, if a path in the graph goes through "ABACA", the value of the path is 3, since there are 3
occurrences of 'A' on the path.
Given a graph with n nodes and m directed edges, return the largest value path of the graph. If the largest value is infinite, 
then return null.The graph is represented with a string and an edge list. The i-th character represents the uppercase letter of 
the i-th node. Each tuple in the edge list (i, j) means there is a directed edge from the i-th node to the j-th node. Self-edges are 
possible, as well as multi-edges.
For example, the following input graph:
ABACA
[(0, 1),
 (0, 2),
 (2, 3),
 (3, 4)]
Would have maximum value 3 using the path of vertices [0, 2, 3, 4], (A, A, C, A).
The following input graph:
A
[(0, 0)]
Should return null, since we have an infinite loop.
**************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int dfs(string s,vector<int>& freq,vector<vector<int>>& adj,vector<bool> isZeroIn, int u){
	int temp_ans = ++freq[s[u]-'A']; //increase the frequency of the current node letter and recur for all of its adjacent till dept
					//so max length path can be traversed
	for(auto v:adj[u])
		temp_ans = max(temp_ans,dfs(s,freq,adj,isZeroIn,v));
	--freq[s[u]-'A'];
	isZeroIn[u] = false; //we might explore again the same path from the any other end in recursion call and keep looping so make 
			//explored vertex false
	return temp_ans;
}

void build_graph(vector<vector<int>> edges,vector<vector<int>>& adj,vector<bool>& isZeroIn){
	for(int i=0;i<edges.size();i++){
		isZeroIn[edges[i][1]] = false;
		adj[edges[i][0]].push_back(edges[i][1]);
	}
}

int longest_path(string s, vector<vector<int>> edges){
	int n = s.length();
	vector<vector<int>> adj_list(n); 
	vector<bool> isZeroIn(n,true);//helps in keeping track of cycles in graph
	build_graph(edges,adj_list,isZeroIn); //creating adj list representation so that dfs can be easily performed 
	int ans = 0;
	vector<int> freq(26,0); //remember the frequency of each letter in the current path being explored
	for(int i=0;i<n;i++){
		if(isZeroIn[i]) //if any node has incoming edge it can be part of cycle also there can be longer path wich starts from
				//it's precedence which has in degree of 0
			ans = max(ans,dfs(s,freq,adj_list,isZeroIn,i)); //consider all the starting point one by one and return maximum.
	}
	return ans;
}

int main() {
	string s = "ABACA";
	vector<vector<int>> edges = {{0, 1},{0, 2},{2, 3},{3, 4}};
	cout<<longest_path(s,edges);
	return 0;
}
