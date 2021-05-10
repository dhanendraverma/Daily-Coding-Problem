/************************************************************************************************************************************************************
This problem was asked by Facebook.
A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while ensuring that no two neighboring 
houses are of the same color. Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, 
return the minimum cost which achieves this goal.
************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCostRec(vector<vector<int>>& cost, int prev, int row, vector<vector<int>>& dp){
	if(row >= cost.size())
		return 0;
	if(prev != -1 && dp[row][prev] != -1)
		return dp[row][prev];
	int curr_min = INT_MAX;
	for(int color=0; color<cost[0].size(); color++){
		if(color != prev)
			curr_min = min(curr_min, cost[row][color] + minCostRec(cost, color, row+1, dp));
			
	}
	if(prev != -1)
		dp[row][prev] = curr_min;
	return curr_min;
}

int minCostDp(vector<vector<int>>& cost){
	vector<vector<int>> dp(cost.size(),vector<int>(cost[0].size(),-1));
	return minCostRec(cost,-1,0,dp);
}

int minCost(vector<vector<int>>& cost){
	int n =  cost.size(), k = cost[0].size();
	int prev_color = -1, prev_min = 0, prev_second_min = 0;
	for(int row=0; row<n; row++){
		int curr_color, curr_min = INT_MAX, curr_second_min = INT_MAX;
		for(int color = 0; color<k; color++){
			int curr_cost = cost[row][color];
			curr_cost += (color==prev_color) ? prev_second_min : prev_min;
			if( curr_cost < curr_min){
				curr_second_min = curr_min;
				curr_min = curr_cost;
				curr_color = color;
			}
			else if( curr_cost < curr_second_min )
				curr_second_min = curr_cost;
		}
		prev_color = curr_color;
		prev_min = curr_min;
		prev_second_min = curr_second_min;
	}
	return prev_min;
}

int main() {
	vector<vector<int>> cost = {{7, 3, 8, 6, 1, 2},
				   {5, 6, 7, 2, 4, 3},
				   {10, 1, 4, 9, 7, 6}};
	cout<<minCost(cost)<<endl;
     cost = {{7, 3, 8, 6, 1, 2},
    		{5, 6, 7, 2, 4, 3},
    		{10, 1, 4, 9, 7, 6},
    		{10, 1, 4, 9, 7, 6}};
     cout<<minCost(cost)<<endl;
     cout<<minCostDp(cost)<<endl;
     return 0;
}
