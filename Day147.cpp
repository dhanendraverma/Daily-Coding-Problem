#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//using pancake sorting smiliar so selection sort
vector<int> sortUsingReverse(vector<int> arr){
	int n = arr.size();
	int i = n-1;
	while(i){
		auto minEle = max_element(arr.begin(),arr.begin()+i+1);
		reverse(minEle,arr.begin()+i+1);
		i--;
	}
	return arr;
}


int main() {
	vector<int> arr = {1,2,6,8,3,10,3,6,20,19};
	vector<int> sortedArr = sortUsingReverse(arr);
	for(auto ele:sortedArr)
		cout<<ele<<" ";
	return 0;
}
