/**************************************************************************************************************************************
This problem was asked by Google.
Given a sorted list of integers, square the elements and give the output in sorted order.
For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
**************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> findSortedSq(vector<int> lst){
	int i;
	for(i=0;i<lst.size();i++){
		if(lst[i]>0)
			break;
	}
	reverse(lst.begin(),lst.begin()+i);
	for(int j=0;j<i;j++)
		lst[j] *= lst[j];
	for(int j=i;j<lst.size();j++)
		lst[j] *= lst[j];
	vector<int> ans(lst.size());
	int j=0,k=i,l=0;
	while(j<i && k<lst.size()){
		if(lst[j]<lst[k])
			ans[l++] = lst[j++]; 
		else
			ans[l++] = lst[k++];
	}
	while(j<i)
		ans[l++] = lst[j++];
	while(k<lst.size())
		ans[l++] = lst[k++];
	return ans;
}


int main() {
	vector<int> sorted_lst  = {-9, -2, 0, 2, 3};
	vector<int> sorted_sq = findSortedSq(sorted_lst);
	for(auto i:sorted_sq)
		cout<<i<<" ";
	return 0;
}
