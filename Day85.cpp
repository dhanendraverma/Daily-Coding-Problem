/*****************************************************************************************************************************************
This problem was asked by Facebook.
Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0, using only mathematical or bit operations. You can assume b 
can only be 1 or 0.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

int x_or_y(int b, int x, int y){
	return x*b + y*(!b);
}

int main() {
	int x=15,y=11,b=1;
	cout<<x_or_y(b,x,y)<<endl;
	b = 0;
	cout<<x_or_y(b,x,y)<<endl;
	return 0;
}
