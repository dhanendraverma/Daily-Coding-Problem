/*****************************************************************************************************************************
This problem was asked by Uber.

One way to unlock an Android phone is through a pattern of swipes across a 1-9 keypad.

For a pattern to be valid, it must satisfy the following:

All of its keys must be distinct.
It must not connect two keys by jumping over a third key, unless that key has already been used.
For example, 4 - 2 - 1 - 7 is a valid pattern, whereas 2 - 1 - 7 is not.

Find the total number of valid unlock patterns of length N, where 1 <= N <= 9.
*****************************************************************************************************************************/
#include <iostream> 
#include <vector>
using namespace std; 

 
int patternsFromCur(vector<bool>& visited, vector<vector<int>>& jump,int cur, int n) { 
	if (n == 0) 
		return 1; 
	int ways = 0; 
	visited[cur] = true; 
	for (int i=1; i<10; i++) { 
		if (!visited[i] && (jump[cur][i]==0 || visited[jump[cur][i]]==true)) 
			ways += patternsFromCur(visited, jump, i, n-1); 
	} 
	visited[cur] = false; 
	return ways; 
} 
 
int validPatterns(int n){ 
	vector<vector<int>> jump(10,vector<int>(10,0)); 
	jump[1][3] = jump[3][1] = 2; 
	jump[7][9] = jump[9][7] = 8; 
	jump[1][7] = jump[7][1] = 4; 
	jump[3][9] = jump[9][3] = 6; 
	jump[1][9] = jump[9][1] = jump[2][8] = jump[8][2] 
	= jump[3][7] = jump[7][3] = jump[4][6] = jump[6][4] = 5; 
	vector<bool> visited(10,false); 
	int ways = 0; 
	ways += 4*patternsFromCur(visited, jump, 1, n-1); 
	ways += 4*patternsFromCur(visited, jump, 2, n-1); 
	ways += patternsFromCur(visited, jump, 5, n-1); 
	return ways; 
} 

int main() 
{ 
	int N = 2; 
	cout << validPatterns(N); 
	return 0; 
} 
