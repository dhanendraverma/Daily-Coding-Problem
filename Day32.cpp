/***************************************************************************************************************************************
This problem was asked by Jane Street.
Suppose you are given a table of currency exchange rates, represented as a 2D array. Determine whether there is a possible arbitrage: 
that is, whether there is some sequence of trades you can make, starting with some amount A of any currency, so that you can end up
with some amount greater than A of that currency.
There are no transaction costs and you can trade fractional quantities.
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

bool is_arbitrage(vector<vector<int>> exchange_rate){
	int n = exchange_rate.size();
	vector<vector<int>> transformed(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			transformed[i][j] = -log(exchange_rate[i][j]);
		}
	}
	vector<int> dist(n,INT_MAX);
	for(int k=0;k<=n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[j]>dist[i]+transformed[i][j])
					dist[j]=dist[i]+transformed[i][j];
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[j]>dist[i]+transformed[i][j])
				return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin>>n;
	vector<vector<int>> exchange_rate(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>exchange_rate[i][j];
		}
	}
	cout<<is_arbitrage(exchange_rate);
	return 0;
}
