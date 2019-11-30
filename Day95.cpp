/*************************************************************************************************************************************
This problem was asked by Palantir.
Given a number represented by a list of digits, find the next greater permutation of a number, in terms of lexicographic ordering. 
If there is not greater permutation possible, return the permutation with the lowest value/ordering.
For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should return [2,1,3]. The list [3,2,1] should return [1,2,3].
Can you perform the operation without allocating extra memory (disregarding the input memory)?
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findNextGreater(vector<int>& lst){
	int i;
	for(i=lst.size()-1;i>0;i--){
		if(i>0 && lst[i]>lst[i-1])
			break;
	}
	if(i==0)
		reverse(lst.begin(),lst.end());
	else{
		for(int j=lst.size()-1;j>i-1;j--){
			if(lst[j]>lst[i-1]){
				swap(lst[j],lst[i-1]);
				break;
			}
		}
		reverse(lst.begin()+i,lst.end());
	}
}

int main() {
	vector<int> lst = {3,2,1};
	findNextGreater(lst);
	for(auto i:lst)
		cout<<i<<" ";
	return 0;
}
