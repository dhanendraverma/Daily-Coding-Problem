/*****************************************************************************************************************************
This problem was asked by Dropbox.
A Boolean formula can be said to be satisfiable if there is a way to assign truth values to each variable such that the 
entire formula evaluates to true.
For example, suppose we have the following formula, where the symbol ¬ is used to denote negation:
(¬c OR b) AND (b OR c) AND (¬b OR c) AND (¬c OR ¬a)
One way to satisfy this formula would be to let a = False, b = True, and c = True.
This type of formula, with AND statements joining tuples containing exactly one OR, is known as 2-CNF.
Given a 2-CNF formula, find a way to assign truth values to satisfy it, or return False if this is impossible.
*****************************************************************************************************************************/

#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 100000; 
vector<int> adj[MAX]; 
vector<int> adjInv[MAX]; 
bool visited[MAX]; 
bool visitedInv[MAX]; 
stack<int> s; 
int scc[MAX]; 
int counter = 1; 

void addEdges(int a, int b){ 
	adj[a].push_back(b); 
} 


void addEdgesInverse(int a, int b){ 
	adjInv[b].push_back(a); 
} 


void dfsFirst(int u){ 
	if(visited[u]) 
		return; 
	visited[u] = 1; 
	for (int i=0;i<adj[u].size();i++) 
		dfsFirst(adj[u][i]); 

	s.push(u); 
} 

void dfsSecond(int u){ 
	if(visitedInv[u]) 
		return; 
	visitedInv[u] = 1; 
	for (int i=0;i<adjInv[u].size();i++) 
		dfsSecond(adjInv[u][i]); 
	scc[u] = counter; 
} 

void is2Satisfiable(int n, int m, int a[], int b[]) { 
	for(int i=0;i<m;i++) { 
		if (a[i]>0 && b[i]>0){ 
			addEdges(a[i]+n, b[i]); 
			addEdgesInverse(a[i]+n, b[i]); 
			addEdges(b[i]+n, a[i]); 
			addEdgesInverse(b[i]+n, a[i]); 
		} 

		else if (a[i]>0 && b[i]<0){ 
			addEdges(a[i]+n, n-b[i]); 
			addEdgesInverse(a[i]+n, n-b[i]); 
			addEdges(-b[i], a[i]); 
			addEdgesInverse(-b[i], a[i]); 
		} 

		else if (a[i]<0 && b[i]>0){ 
			addEdges(-a[i], b[i]); 
			addEdgesInverse(-a[i], b[i]); 
			addEdges(b[i]+n, n-a[i]); 
			addEdgesInverse(b[i]+n, n-a[i]); 
		} 

		else{ 
			addEdges(-a[i], n-b[i]); 
			addEdgesInverse(-a[i], n-b[i]); 
			addEdges(-b[i], n-a[i]); 
			addEdgesInverse(-b[i], n-a[i]); 
		} 
	} 
	for (int i=1;i<=2*n;i++) 
		if (!visited[i]) 
			dfsFirst(i); 

	while (!s.empty()) 
	{ 
		int n = s.top(); 
		s.pop(); 

		if (!visitedInv[n]) 
		{ 
			dfsSecond(n); 
			counter++; 
		} 
	} 

	for (int i=1;i<=n;i++){ 
		if(scc[i]==scc[i+n]) 
		{ 
			cout << "The given expression "
				"is unsatisfiable." << endl; 
			return; 
		} 
	} 
	cout << "The given expression is satisfiable."
		<< endl; 
	return; 
} 


int main() { 
	int n =3 , m = 4; 
	int a[] = {-3, 2, -2, -3};
	int b[] = {2, 3, 3, -1};
	is2Satisfiable(n, m, a, b); 
	return 0; 
} 
