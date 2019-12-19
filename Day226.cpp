/**************************************************************************************************************************************
This problem was asked by Airbnb.
You come across a dictionary of sorted words in a language you've never seen before. Write a program that returns the correct order of 
letters in this language.
For example, given ['xww', 'wxyz', 'wxyw', 'ywx', 'ywz'], you should return ['x', 'z', 'w', 'y'].
***************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Graph{
	public:
	map<char,vector<char>> adj;
	Graph(){}
	void addEdge(char u,char v){
		adj[u].push_back(v);
	}
	
	void topologicalSortUtil(char v, vector<bool>& visited, stack<char> &Stack){ 
		visited[v-'a'] = true; 
		for (auto i:adj[v]) 
			if(!visited[i-'a']) 
		 		topologicalSortUtil(i, visited, Stack); 
		Stack.push(v); 
	}
	
	vector<char> topologicalSorting(){
		stack<char> Stack; 
		vector<char> order;
		vector<bool> visited(26,false);
		for(auto i:adj){
 			if(visited[i.first-'a'] == false) 
 				topologicalSortUtil(i.first, visited, Stack); 
		}
		while (!Stack.empty()){ 
				order.push_back(Stack.top());
			Stack.pop(); 
		}
	return order;
	}

};

vector<char> letterorder(vector<string> dict){
	Graph graph;
	for(int i=0;i<dict.size()-1;i++){
		for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++){
			if(dict[i][j]!=dict[i+1][j]){
				graph.addEdge(dict[i][j],dict[i+1][j]);
				break;
			}
		}
	}
	return graph.topologicalSorting();
}

int main() {
	vector<string> dict = {"xww", "wxyz", "wxyw", "ywx", "ywz"};
	vector<char> order = letterorder(dict);
	for(auto c:order)
		cout<<c<<" ";
	return 0;
}
