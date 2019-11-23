/*****************************************************************************************************************************************
This problem was asked by Square.
Assume you have access to a function toss_biased() which returns 0 or 1 with a probability that's not 50-50 (but also not 0-100 or 100-0).
You do not know the bias of the coin.
Write a function to simulate an unbiased coin toss.
*****************************************************************************************************************************************/

#include <iostream>
using namespace std;

int unbiased_toss(){
	int tos1 = biased_toss();
	int tos2 = biased_toss();
	//let us assume unbiased toss returns 1 with probability x then probability of 0 would be (1-x) 
	//probability to get 1 followed by 0 = probability to get one*probability to get zero = x(1-x)
	if(tos1==0 && tos2==1)
		reutrn 0;
	//probability to get 0 followed by 1 = probability to get zero*probability to get one = (1-x)x 
	if(tos1==0 && tos2==1)
		reutrn 0;
	//if above two cased are not satified then toss the coin again
	return unbiased_toss();
}

int main() {
	// your code goes here
	return 0;
}
