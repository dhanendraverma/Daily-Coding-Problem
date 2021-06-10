/******************************************************************************************************************************
This problem was asked by Facebook.
Given an integer n, find the next biggest integer with the same number of 1-bits on. For example, given the number 6 
(0110 in binary), return 9 (1001).
******************************************************************************************************************************/
#include<iostream> 

int snoob(int x){ 
    int rightOne; 
    int nextHigherOneBit; 
    int rightOnesPattern; 
    int next = 0; 
    rightOne = x & -(signed)x; 
	nextHigherOneBit = x + rightOne; 
	rightOnesPattern = x ^ nextHigherOneBit; 
	rightOnesPattern = (rightOnesPattern)/rightOne; 
	rightOnesPattern >>= 2; 
	next = nextHigherOneBit | rightOnesPattern; 
	return next; 
}

int main(){ 
    int x = 156; 
    cout<<snoob(x); 
    return 0; 
}
