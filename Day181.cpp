/**************************************************************************************************************************************
This problem was asked by Google.
Given a string, split it into as few strings as possible such that each string is a palindrome.
For example, given the input string racecarannakayak, return ["racecar", "anna", "kayak"].
Given the input string abc, return ["a", "b", "c"].
***************************************************************************************************************************************/


#include <iostream>
#include <vector>
#include <climits>
using namespace std; 

int minPalPartion(string str) 
{ 
	int n = str.length(); 
	vector<vector<int>> C(n,vector<int>(n)); 
	vector<vector<int>> P(n,vector<int>(n)); 
	for (int i = 0; i < n; i++){ 
		P[i][i] = i; 
		C[i][i] = 0; 
	} 
	for(int L = 2; L <= n; L++){ 
		for (int i = 0; i < n - L + 1; i++){ 
			int j = i + L - 1;
			if (L == 2) 
				P[i][j] = (str[i] == str[j]); 
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 
			if (P[i][j]) 
				C[i][j] = 0; 
			else{ 
				C[i][j] = INT_MAX; 
				for (int k = i; k <= j - 1; k++) {
					if(C[i][j]>C[i][k] + C[k + 1][j] + 1){
						 C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1);
						 P[i][j] = k;
					}
				}
					// C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1); 
			} 
		} 
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<P[i][j]<<" ";
		cout<<endl;
	}
	cout<<"--------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<C[i][j]<<" ";
		cout<<endl;
	}
	return C[0][n - 1]; 
} 

int main() 
{ 
	string str = "racecarannakayak"; 
	cout<<"Min cuts needed for Palindrome Partitioning is "<<endl<<minPalPartion(str); 
	return 0; 
} 
