#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std; 

void dfs(string node, string& A, int& k,set<string>& visited, vector<int>& edges) { 
	for (int i=0; i<A.size(); ++i) { 
		string str = node + A[i]; 
		if (visited.find(str) == visited.end()) { 
			visited.insert(str); 
			dfs(str.substr(1),A,k,visited,edges); 
			edges.push_back(i); 
		} 
	} 
} 

string deBruijn(set<char> C, int k){ 
	string A = "";
	for(auto ch:C)
		A += ch;
	set<string> visited; 
	vector<int> edges; 
	string startNode = string(k-1, A[0]); 
	dfs(startNode,A,k,visited,edges); 
	string seq; 
	int l = pow(A.size(),k); 
	for (int i = 0; i < l; ++i)
		seq += A[edges[i]]; 
	seq += startNode; 
	return seq; 
} 

int main() { 
	int k = 3; 
	set<char> C = {'0','1'}; 
	cout<<deBruijn(C,k); 
	return 0; 
} 
