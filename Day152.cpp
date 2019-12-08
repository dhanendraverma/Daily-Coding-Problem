/*****************************************************************************************************************************************
This problem was asked by Triplebyte.
You are given n numbers as well as n probabilities that sum up to 1. Write a function to generate one of the numbers with its
corresponding probability.
For example, given the numbers [1, 2, 3, 4] and probabilities [0.1, 0.5, 0.2, 0.2], your function should return 1 10% of the time, 
2 50% of the time, and 3 and 4 20% of the time.
You can generate random numbers between 0 and 1 uniformly.
*****************************************************************************************************************************************/

#include <iostream>
#include <stdlib.h> 
#include<time.h> 
#include <vector>
using namespace std;

int genNum(vector<int> numbers, vector<float> probabilities){
	vector<float> new_prob(probabilities.size(),0);
	new_prob[0] = probabilities[0];
	for(int i=1;i<probabilities.size();i++){
		new_prob[i] = probabilities[i]+new_prob[i-1];
	}
	srand(time(0)); 
	float rd = (rand()%10)*0.1;
	auto it = lower_bound(new_prob.begin(), new_prob.end(), rd);
	return numbers[it-new_prob.begin()];
}

int main() {
	vector<int> numbers = {1, 2, 3, 4};
	vector<float> probabilities = {0.1, 0.5, 0.2, 0.2};
	cout<<genNum(numbers,probabilities)<<endl;
	return 0;
}
