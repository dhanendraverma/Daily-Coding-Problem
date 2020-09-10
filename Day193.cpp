/****************************************************************************************************************************************
This problem was asked by Affirm.
Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the
maximum profit you could have made from buying and selling that stock. You're also given a number fee that represents a transaction fee 
for each buy and sell transaction.
You must buy before you can sell the stock, but you can make as many transactions as you like.
For example, given [1, 3, 2, 8, 4, 10] and fee = 2, you should return 9, since you could buy the stock at 1 dollar, and sell at 8 dollars,
and then buy it at 4 dollars and sell it at 10 dollars. Since we did two transactions, there is a 4 dollar fee, so we have 7 + 6 = 13
profit minus 4 dollars of fees.
*****************************************************************************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

int maxProfitEase(vector<int> prices, int fee){
	if(!prices.size()){
            return 0;
        } 
        int buy = -prices[0], sell = 0;
        for(int i=1;i<prices.size();i++){
            // either sell today or do nothing/hold the stock
            sell = max(sell,buy+prices[i]-fee);
            // either buy today or do nothing/not hold any stock
            buy = max(buy,sell-prices[i]);
        }
        return sell
}

int main() {
	vector<int> prices = {1, 3, 2, 8, 4, 10};
	int fee = 2;
	cout<<maxProfitEase(prices,fee)<<endl;
	return 0;
}






#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> prices, int fee){
	int profit = 0;
	int buy=prices[0],sell=prices[0];
	for(int i=0;i<prices.size();i++){
		if(prices[i]<buy || prices[i]+fee<sell){
			profit += (sell-buy-fee)>0?(sell-buy-fee):0;
			buy = prices[i];
			sell = prices[i];
		}
		else if(prices[i]>sell)
			sell = prices[i];
	}
	profit += (sell-buy-fee)>0?(sell-buy-fee):0;
	return profit;
}

int main() {
	vector<int> prices = {1, 3, 2, 8, 4, 10};
	int fee = 2;
	cout<<maxProfit(prices,fee)<<endl;
	return 0;
}
