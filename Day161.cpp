/****************************************************************************************************************************************
This problem was asked by Facebook.
Given a 32-bit integer, return the number with its bits reversed.
For example, given the binary number 1111 0000 1111 0000 1111 0000 1111 0000, return 0000 1111 0000 1111 0000 1111 0000 1111.
*****************************************************************************************************************************************/


#include <iostream>
using namespace std;

unsigned int reverseBits(unsigned int num) 
{ 
	unsigned int cnt = 31; 
	unsigned int reverse_num = num; 
	num >>= 1; 
	while(num) 
	{ 
		reverse_num <<= 1;	 
		reverse_num |= num & 1; 
		num >>= 1; 
		cnt--; 
	} 
	reverse_num <<= cnt; 
	return reverse_num; 
}

int main() {
	unsigned int n=49;
	cout<<reverseBits(n);
	return 0;
}
