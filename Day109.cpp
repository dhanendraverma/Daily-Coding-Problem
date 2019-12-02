/****************************************************************************************************************************************
This problem was asked by Cisco.
Given an unsigned 8-bit integer, swap its even and odd bits. The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped,
and so on.
For example, 10101010 should be 01010101. 11100010 should be 11010001.
Bonus: Can you do this in one line?
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

int swapbit(int num){
	return  ((num&85)<<1) | ((num &170)>>1);
}

int main() {
	int num = 23;
	cout<<swapbit(num);
	return 0;
}
