/******************************************************************************************************************************
This problem was asked by YouTube.
Write a program that computes the length of the longest common subsequence of three given strings. For example, given 
"epidemiologist", "refrigeration", and "supercalifragilisticexpialodocious", it should return 5, since the longest common 
subsequence is "eieio".
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
mnbb
vim
int longestCommonSub(string A, string B, string C){
	int m = A.length();
	int n = B.length();
	int o = C.length();
	vector<vector<vector<int>>> L(m+1,vector<vector<int>>(n+1,vector<int>(o+1)));
    for(int i=0; i<=m; i++){ 
    	for(int j=0; j<=n; j++){
    		for(int k=0; k<=o; k++){
    			if(i == 0 || j == 0||k==0) 
                    L[i][j][k] = 0; 
                else if(A[i-1] == B[j-1] && A[i-1]==C[k-1]) 
                    L[i][j][k] = L[i-1][j-1][k-1] + 1; 
                else
                    L[i][j][k] = max(max(L[i-1][j][k],L[i][j-1][k]),L[i][j][k-1]); 
            } 
        } 
    } 
    return L[m][n][o];
}


int main() {
	string A = "epidemiologist";
	string B = "refrigeration";
	string C = "supercalifragilisticexpialodocious";
	cout<<longestCommonSub(A,B,C)<<endl;
	return 0;
}
