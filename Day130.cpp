/****************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Facebook.
Given an array of numbers representing the stock prices of a company in chronological order and an integer k, return the maximum profit
you can make from k buys and sells. You must buy the stock before you can sell it, and you must sell the stock before you can buy it again.
For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int> prices, int k){
    int n = prices.size();
    if(n<=1 || k==0)
        return 0;
        
    //same as infinite transactions
    if(2*k>=n){
        int profit = 0;
        for(int i=0;i<n-1;i++)
            profit += max(0,prices[i+1]-prices[i]);
        return profit;
    }
    
     //solve using the dp
	vector<vector<int>> T(k+1,vector<int>(n));
	for(int i=0;i<=k;i++){
		int trackDiff = INT_MIN;
		for(int j=0;j<n;j++){
		    if(i==0 || j==0)
		        T[i][j] = 0;
		    else{
		        //can retain the max when the buying is the least
                	//comapre the last buying with the current buying whichever is min
			trackDiff = max(trackDiff, T[i-1][j-1]-prices[j-1]);
			//after buying at the least price sell it at the current day i.e. j or don't sell at all
			T[i][j] = max(T[i][j-1], prices[j]+trackDiff);
		    }
		}
	}
	return T[k][n-1];
}

int main() {
	vector<int> prices = {5, 2, 4, 0, 1};
	int k = 2;
	cout<<maxProfit(prices,k)<<endl;
	return 0;
}
