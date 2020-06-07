/******************************************************************************************************************************
This problem was asked by Goldman Sachs.
You are given N identical eggs and access to a building with k floors. Your task is to find the lowest floor that will cause 
an egg to break, if dropped from that floor. Once an egg breaks, it cannot be dropped again. If an egg breaks when dropped 
from the xth floor, you can assume it will also break when dropped from any floor greater than x.
Write an algorithm that finds the minimum number of trial drops it will take, in the worst case, to identify this floor.
For example, if N = 1 and k = 5, we will need to try dropping the egg at every floor, beginning with the first, until we reach
the fifth floor, so our solution will be 5.
*******************************************************************************************************************************


// ################## Top Down approach ##########################
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int eggDrop(int e,int f,vector<vector<int>>& T){
    // if nummber of floors is 0 or 1 or we've only one egg so wrost would be floors
    if(f==0 || f==1 || e==1)
        return f;
    //if already solved this problem
    if(T[e][f] != -1)
        return T[e][f];
    int res,mn = INT_MAX;
    // drop egg from each floor and take which gives min value
    for(int k=1;k<=f;k++){
        res = max(eggDrop(e-1,k-1,T),eggDrop(e,f-k,T));
        mn = min(res,mn);
    }
    return T[e][f] = mn+1;
}

int main() {
    int e = 2, f = 36;
    vector<vector<int>> T(e+1,vector<int>(f+1,-1));
    cout<<eggDrop(e,f,T)<<endl;
	return 0;
}


// ################## Bottom Up approach ##########################
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minTrials(int f, int e){
	vector<vector<int>> dp(e+1,vector<int>(f+1));
	for(int i=0;i<=f;i++)
		dp[1][i]=i;
	for(int i=2;i<=e;i++){
		for(int j=1;j<=f;j++){
			dp[i][j] = INT_MAX;
			for(int k=1;k<=j;k++)
				dp[i][j] = min(dp[i][j],1+max(dp[i-1][j-1],dp[i][j-k]));
		}
	}
	return dp[e][f];
}

int main() {
	int floors = 38;
	int eggs = 2;
	cout<<minTrials(floors,eggs)<<endl;
	return 0;
}
