/******************************************************************************************************************************
This problem was asked by Google.
Find the minimum number of coins required to make n cents.
You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.
For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.
******************************************************************************************************************************/

// ############################## Top Down Approach ###################################

#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int counts(int s,int m,vector<int>& coins,vector<vector<int>>& T){
    if(s==0)
        return 0;
    if(m<=0)
        return INT_MAX;
    if(T[s][m]!=-1)
        return T[s][m];
    if(coins[m-1]<=s)
        return T[s][m] = min(counts(s,m-1,coins,T),1+counts(s-coins[m-1],m,coins,T));
    return T[s][m] = counts(s,m-1,coins,T);
}

int main() {
	vector<int> coins = {1, 10, 5, 25};
	int cents = 16;
	int m = coins.size();
	vector<vector<int>> T(cents+1,vector<int>(m+1,-1));
	cout<<counts(cents,m,coins,T)<<endl;
	return 0;
}


// ############################## Bottom up Approach ###################################

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int minCoins(int cents, vector<int> coins){
    vector<int> T(cents+1,INT_MAX-1);
    T[0] = 0;
    for(int j=0; j < coins.size(); j++){
        for(int i=1; i <= cents; i++){
            if(i >= coins[j])
                T[i] = min(1 + T[i - coins[j]], T[i]);
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
