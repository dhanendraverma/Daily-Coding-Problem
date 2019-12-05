/****************************************************************************************************************************************
This problem was asked by Google.
Find the minimum number of coins required to make n cents.
You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.
For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.
*****************************************************************************************************************************************/
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int minCoins(int cents, vector<int> coins){
    vector<int> T(cents+1,INT_MAX-1);
    T[0] = 0;
    for(int j=0; j < coins.size(); j++){
        for(int i=1; i <= cents; i++){
            if(i >= coins[j]){
                if (T[i - coins[j]] + 1 < T[i]) {
                    T[i] = 1 + T[i - coins[j]];
                }
            }
        }
    }
    return T[cents];
}

int main() {
	vector<int> coins = {1, 10, 5, 25};
	int cents = 16;
	cout<<minCoins(cents,coins)<<endl;
	return 0;
}
