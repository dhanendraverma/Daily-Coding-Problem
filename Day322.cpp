/******************************************************************************************************************************
This problem was asked by Flipkart.
Starting from 0 on a number line, you would like to make a series of jumps that lead to the integer N.
On the ith jump, you may move exactly i places to the left or right.
Find a path with the fewest number of jumps required to get from 0 to N.
*****************************************************************************************************************************/

#include <iostream>
using namespace std;

int getSum(int n){
    return n*(n+1)/2;
}

int minJumps(int n){
    n = abs(n);
    int jumps = 0;
    while (getSum(jumps) < n or (getSum(jumps)-n)&1)
        jumps++;
    return jumps;
}

int main() {
    int N = 8;
    cout<<minJumps(N)<<endl;
	return 0;
}
