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


void DFS(vector<vector<int>>& adjList, int root, int descendant, vector<vector<int>>& closure){
	for(auto child:adjList[descendant]){
		if(!closure[root][child]){
			closure[root][child] = true;
			DFS(adjList, root, child, closure);
		}
	}
}

vector<vector<int>> transitiveClosureDFS(vector<vector<int>>& adj_list){
	int V = adj_list.size();
	vector<vector<int>> closure(V, vector<int>(V,false));
	for(int i=0; i<V; i++){
		// closure[i][i] = 1;
		DFS(adj_list, i, i, closure);
	}
	return closure;
}

int main() {
	vector<vector<int>> adj_list = {{0, 1, 3}, {1, 2}, {2}, {3}};
	vector<vector<int>> transitive_closure = transitiveClosureDFS(adj_list);
	for(auto row:transitive_closure){
		for(auto ele:row)
			cout<<ele<<" ";	
		cout<<endl;
	}
	cout<<"------------------------"<<endl;
	transitive_closure = transitiveClosureDFS(adj_list);
	for(auto row:transitive_closure){
		for(auto ele:row)
			cout<<ele<<" ";	
		cout<<endl;
	}
	return 0;
}
