/****************************************************************************************************************************************
This problem was asked by Stripe.
Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.
For example, given 156, you should return 3.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

int ConsecutiveOne(int n){
	int count=0;
	while(n){
		n = (n&(n<<1));
		count++;
	}
	return count;
}

int main() {
	int n = 786;
	cout<<ConsecutiveOne(n);
	return 0;
}
