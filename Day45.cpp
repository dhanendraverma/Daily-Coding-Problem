/**************************************************************************************************************************************
This problem was asked by Two Sigma.
Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability, implement a function rand7() that
returns an integer from 1 to 7 (inclusive).
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

int rand7(){
	int i;
	i = 5*rand5()+rand5()-5;
	if(i<22)
		return i%7+1;
	return rand7();
}


int main() {
	cout<<rand7();
	return 0;
}
