/*****************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Microsoft.
You have n fair coins and you flip them all at the same time. Any that come up tails you set aside. The ones that come up heads you 
flip again. How many rounds do you expect to play before only one coin remains?
Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.
******************************************************************************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int rounds(int n){
	return ceil(log2(n));
}

int main() {
	int n = 200;
	cout<<rounds(n)<<endl;
	return 0;
}
