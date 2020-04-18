/******************************************************************************************************************************
This problem was asked by Microsoft.
Write a program to determine how many distinct ways there are to create a max heap from a list of N given integers.
For example, if N = 3, and our integers are [1, 2, 3], there are two ways, shown below.

  3      3
 / \    / \
1   2  2   1
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int combination(int n,int k,vector<vector<int>>& nck){
    if(k>n)
        return 0;
    if(n<=1 || k==0)
        return 1;
    if(nck[n][k] != -1)
        return nck[n][k];
    int comb = combination(n-1,k-1,nck)+combination(n-1,k,nck);
    nck[n][k] = comb;
    return comb;
}


int getLeftCnt(int n){
    if(n==1)
        return 0;
    int h = log2(n);
    int maxNode = (1<<h);
    int lasLevelNode = n - (maxNode - 1);
    if(lasLevelNode >= maxNode/2)
        return maxNode - 1;
    else
        return maxNode -1 - (maxNode/2 - lasLevelNode);
}

int findHeapCntRec(int n,vector<int>& dp,vector<vector<int>>& nck){
    if(n<=1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    int lefCnt = getLeftCnt(n);
    int heapCnt = combination(n-1,lefCnt,nck)*findHeapCntRec(lefCnt,dp,nck)*findHeapCntRec(n - lefCnt - 1,dp,nck);
    dp[n] = heapCnt;
    return heapCnt;
}

int getNoOfHeaps(int n){
    vector<int> dp(n+1,-1);
    vector<vector<int>> nck(n+1,vector<int>(n+1,-1));
    return findHeapCntRec(n,dp,nck);
}

int main() {
    int N = 10;
    cout<<getNoOfHeaps(N);
	return 0;
}
