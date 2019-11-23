/**************************************************************************************************************************************
This problem was asked by Facebook.
Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.
For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true, since we can split it up into {15, 5, 10, 15, 10} 
and {20, 35}, which both add up to 55.
Given the multiset {15, 5, 20, 10, 35}, it would return false, since we can't split it up into two subsets that add up to the same sum.
**************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <numeric> 
using namespace std;

bool can_split(vector<int> mltset){
	int n = mltset.size();
	int s = accumulate(mltset.begin(), mltset.end(), 0);
	if(s%2)
		return false;
	s = s/2;
	//a table where row is represnting sum and col is representing input numbers
	vector<vector<bool>> T(n+1,vector<bool>(s+1));
	//sum 0 can be obtained by using any number
	for(int i=0;i<=n;i++)
		T[i][0] = true;
	//available input numbers are 0 in count then no any sum except 0 is possible
	for(int i=1;i<=n;i++)
		T[0][i] = false;
	//filling the dp tabel starting from the sum=1 to the required sum if current sum is possible with the
	//avaiable j number of inputs
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			if(j-mltset[i-1]>=0) //current sum is greater than or equal to the number being considered
			//if sum j is possible either by considering current number or not conisdering it at all
				T[i][j] = T[i-1][j] || T[i-1][j-mltset[i-1]]; 
			else
				T[i][j] = T[i-1][j]; //we have only option to not consider current number
		}
	}
	return T[n][s];
}


int main() {
	vector<int> mltset = {15, 5, 20, 10, 35, 15, 10};
	cout<<can_split(mltset);
	return 0;
}
