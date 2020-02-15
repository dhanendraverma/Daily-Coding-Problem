/*****************************************************************************************************************************
This problem was asked by Indeed.
Given a 32-bit positive integer N, determine whether it is a power of four in faster than O(log N) time.
******************************************************************************************************************************/

#include <iostream>
using namespace std;

bool isPowerOfFour(int n){
	return n && !(n&(n-1)) && !(n&0xAAAAAAAA);
}

int main() {
	int n = 16;
	cout<<isPowerOfFour(n)<<endl;
	return 0;
}
