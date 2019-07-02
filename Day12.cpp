/*****************************************************************************************************************************************
This problem was asked by Amazon.
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the 
number of unique ways you can climb the staircase. The order of the steps matters.
For example, if N is 4, then there are 5 unique ways:
•	1, 1, 1, 1
•	2, 1, 1
•	1, 2, 1
•	1, 1, 2
•	2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? 
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*****************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1]+dp[i-2];
    cout<<dp[n];
    /* When allowed to climb any number from a set of positive integers X
    vector<int> set;
    int set_size, temp;
    for(int i=0;i<set_size;i++) {
        cin>>temp;
        set.push_back(temp);
    }
  
    for(int i=2;i<=n;i++) {
        dp[i] = 0;
        for(int j=0;j<set_size && set[j]<=i;j++) {
            dp[i] += dp[i-set[j]]
        }
    }
    cout<<dp[n];
    */
}

