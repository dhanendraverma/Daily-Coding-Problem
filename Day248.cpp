/*****************************************************************************************************************************
Find the maximum of two numbers without using any if-else statements, branching, or direct comparisons.
/*****************************************************************************************************************************/

#include <iostream>
using namespace std;

int findMax(int a,int b){
	return a*((a/b)&1) + b*((b/a)&1);
}

int main() {
	int a=6,b=8;
	cout<<findMax(a,b)<<endl;
	return 0;
}
