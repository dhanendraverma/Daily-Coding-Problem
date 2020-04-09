#include <iostream>
#include <vector>
using namespace std;

int noOfArrangement(int N){
    vector<int> dp(N+1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for(int i=4;i<=N;i++)
        dp[i] = 2*dp[i-1]+dp[i-3];
    return dp[N];
}

int main() {
    int N = 4;
    cout<<noOfArrangement(N)<<endl;
	return 0;
}
