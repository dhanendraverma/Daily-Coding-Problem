/*****************************************************************************************************************************************
This problem was asked by Facebook.
There is an N by M matrix of zeroes. Given N and M, write a function to count the number of ways of starting at the top-left corner and 
getting to the bottom-right corner. You can only move right or down.
For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:
Right, then down
Down, then right
Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

long long find_ways(int m,int n){
	if(m==1 || n==1)
		return 1;
	return find_ways(m-1,n)+find_ways(m,n-1);
}

int main() {
	int m=5,n=5;
	cout<<find_ways(m,n);
	return 0;
}
