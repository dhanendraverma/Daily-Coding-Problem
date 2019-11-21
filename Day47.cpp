/****************************************************************************************************************************************
This problem was asked by Facebook.
Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum
profit you could have made from buying and selling that stock once. You must buy before you can sell it.
For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.
*****************************************************************************************************************************************/
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int max_profit(vector<int> prices){
	int n=prices.size();
	if(n<=1)
		return 0;
	int min_sofar = prices[0];
	int max_sofar = prices[1]-prices[0];
	for(int i=1;i<n;i++){
		max_sofar = max(max_sofar,prices[i]-min_sofar);
		min_sofar = min(min_sofar,prices[i]);
	}
	return max_sofar;
}

int main() {
	vector<int> prices = {25,9, 11, 8, 5, 7, 10};
	cout<<max_profit(prices);
	return 0;
}
