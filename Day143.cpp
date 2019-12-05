/****************************************************************************************************************************************
This problem was asked by Amazon.
Given a pivot x, and a list lst, partition the list into three parts.
The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x
Ordering within a part can be arbitrary.
For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

//Dutch National Flag problem
void threeWayPartition(vector<int>& lst, int x){
	int low = 0, mid = 1, high = lst.size()-1;
	while(mid<=high){
		if(lst[mid]<x)
			swap(lst[mid++], lst[low++]);
		else if(lst[mid]>10)
			swap(lst[mid], lst[high--]);
		else
			mid++;
	}
}

int main() {
	vector<int> lst = {9, 12, 3, 5, 14, 10, 10};
	int x = 10;
	threeWayPartition(lst,x);
	for(auto i:lst)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}
