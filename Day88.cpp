/*****************************************************************************************************************************************
This question was asked by ContextLogic.
Implement division of two positive integers without using the division, multiplication, or modulus operators. Return the quotient as an 
integer, ignoring the remainder.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

int division(int dividend, int divisor){
	int rem = dividend%divisor;
	dividend -= rem;
	int l=1,r=dividend,mid;
	while(l<=r){
		mid = (l+r)/2;
		if(mid*divisor==dividend)
			break;
		else if(mid*divisor>dividend)
			r = mid-1;
		else
			l = mid+1;
	}
	return mid;
}


int main() {
	cout<<division(20,2);
	return 0;
}
