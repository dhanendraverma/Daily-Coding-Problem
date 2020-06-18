/******************************************************************************************************************************
This problem was asked by Google.
The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions 
required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute
the “k” for “s”, substitute the “e” for “i”, and append a “g”.
Given two strings, compute the edit distance between them.
******************************************************************************************************************************/


// ################################ Top down appraoch #######################################
#include <iostream>
#include <vector>
using namespace std;

int minEditDist(string A,string B,int m,int n,vector<vector<int>>& T){
    if(m==0 || n==0)
        return max(m,n);
    if(T[m][n]!=-1)
        return T[m][n];
    if(A[m-1]==B[n-1])
        return T[m][n] = minEditDist(A,B,m-1,n-1,T);    
    return T[m][n] = 1+min(minEditDist(A,B,m-1,n,T),min(minEditDist(A,B,m,n-1,T),minEditDist(A,B,m-1,n-1,T)));
}

int main() {
    string A = "kitten", B = "sitting";
    vector<vector<int>> T(A.length()+1,vector<int>(B.length()+1,-1));
    cout<<minEditDist(A,B,A.length(),B.length(),T)<<endl;
	return 0;
}



// ################################ Bottom up appraoch #######################################
#include <iostream>
using namespace std;

int minEditDist(string str1, string str2){
	int m = str1.length();
	int n = str2.length();
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
		dp[0][i] = i;
	for(int i=0;i<=n;i++)
		dp[i][0] = i;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
				
			}
			else
				dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
		}
	}
	return dp[m][n];
}

int main() {
	// your code goes here
	string str1,str2;
	cin>>str1>>str2;
	cout<<minEditDist(str1,str2)<<endl;
	return 0;
}
