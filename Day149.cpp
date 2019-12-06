/****************************************************************************************************************************************
This problem was asked by Goldman Sachs.
Given a list of numbers L, implement a method sum(i, j) which returns the sum from the sublist L[i:j] (including i, excluding j).
For example, given L = [1, 2, 3, 4, 5], sum(1, 3) should return sum([2, 3]), which is 5.
You can assume that you can do some pre-processing. sum() should be optimized over the pre-processing step.
****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void preProcess(vector<int> L, vector<int>& pre){
	pre[0] = L[0];
	for(int i=1;i<L.size();i++)
		pre[i] = L[i]+pre[i-1];
}

int sum(int i, int j, vector<int>& pre){
	if(i==0)
		return pre[j-1];
	return pre[j]-pre[i-1];
}

int main() {
	vector<int> L = {1,2,4,5,6,7,8,9,12};
	vector<int> pre(L.size(),0);
	preProcess(L,pre);
	cout<<sum(0,5,pre);
	return 0;
}
