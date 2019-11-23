/*****************************************************************************************************************************************
This problem was asked by Google.
Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.
Do this faster than the naive method of repeated multiplication.
For example, pow(2, 10) should return 1024.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

double fast_exponentiation(float x, int y){
	bool flag = false;
	if(y<0){
		flag = true;
		y*= -1;
	}
	double ans = 1;
	while(y){
		if(y&1)
			ans = ans*x;
		y = y>>1;
		x = x*x;
	}
	if(flag)
		return 1/ans;
	return ans;
}

int main() {
	int x=2,y=10;
	cout<<fast_exponentiation(x,y);
	return 0;
}
