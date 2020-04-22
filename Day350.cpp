/******************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Uber.
Write a program that determines the smallest number of perfect squares that sum up to N.
Here are a few examples:
Given N = 4, return 1 (4)
Given N = 17, return 2 (16 + 1)
Given N = 18, return 2 (9 + 9)
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minSqSum(int n){
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4;i<=n;i++){
        dp[i] = i;
        for(int j=1;j<=ceil(sqrt(i));j++){
            if(j*j>i)
                break;
            else
                dp[i] = min(dp[i],1+dp[i-j*j]);
        }
    }
    return dp[n];
}

int main() {
    int N = 17;
    cout<<minSqSum(N)<<endl;
	return 0;
}
