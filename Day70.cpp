/****************************************************************************************************************************************
This problem was asked by Microsoft.
A number is considered perfect if its digits sum up to exactly 10.
Given a positive integer n, return the n-th perfect number.
For example, given 1, you should return 19. Given 2, you should return 28.
*****************************************************************************************************************************************/


#include <iostream>
using namespace std;

long long get_nth_perfect(int n){
	int s=0,temp=n;
	while(temp){
		s+=temp%10;
		temp = temp/10;
	}
	return n*10+(10-s);
}

int main() {
	int n=10;
	cout<<get_nth_perfect(n);
	return 0;
}
