/*****************************************************************************************************************************************
This problem was asked by Google.
You are given an array of nonnegative integers. Let's say you start at the beginning of the array and are trying to advance to the end. 
You can advance at most, the number of steps that you're currently on. Determine whether you can get to the end of the array.
For example, given the array [1, 3, 1, 2, 0, 1], we can go from indices 0 -> 1 -> 3 -> 5, so return true.
Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.
******************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool CanReachEnd(vector<int> jumps){
	vector<bool> dp(jumps.size(),false);
	dp[0] = true;
	for(int i=0;i<jumps.size();i++){
		if(dp[i] && jumps[i]>0){
			for(int j=1;j<=jumps[i];j++)
				if(i+j<jumps.size())
					dp[i+j]=true;
		}
	}
	return dp[jumps.size()-1];
}


int main() {
	vector<int> jumps = {1, 2, 1, 0, 0};
	cout<<CanReachEnd(jumps)<<endl;
	return 0;
}
