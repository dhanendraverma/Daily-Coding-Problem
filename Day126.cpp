/*****************************************************************************************************************************************
This problem was asked by Facebook.
Write a function that rotates a list by k elements. For example, [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 6, 1, 2]. Try 
solving this without creating a copy of the list. How many swap or move operations do you need?
******************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void rotateKtimes(vector<int>& lst, int k){
	int i=0,j=k,cnt=0;
	while(j<lst.size()){
		swap(lst[i++],lst[j++]);
		cnt++;
	}
	cout<<endl<<"No of swaps are : "<<cnt;
}


int main() {
	vector<int> lst = {1, 2, 3, 4, 5, 6};
	int k = 2;
	cout<<"Before rotation : ";
	for(auto i:lst)
		cout<<i;
	rotateKtimes(lst,k);
	cout<<endl<<"After rotation : ";
	for(auto i:lst)
		cout<<i;
	return 0;
}
