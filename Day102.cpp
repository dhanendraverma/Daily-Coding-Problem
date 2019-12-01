/*****************************************************************************************************************************************
This problem was asked by Lyft.
Given a list of integers and a number K, return which contiguous elements of the list sum to K.
For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4], since 2 + 3 + 4 = 9.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findContSubarr(vector<int> lst, int k){
	unordered_map<int,int> m;
	int curr_sum=0;
	for(int i=0;i<lst.size();i++){
		curr_sum += lst[i];
		if(curr_sum==k)
			return vector<int>(lst.begin(),lst.begin()+i+1);
		if(m.find(curr_sum-k)!=m.end())
			return vector<int>(lst.begin()+m[curr_sum-k]+1,lst.begin()+i+1);
		m[curr_sum] = i;
	}
	cout<<"No subarray sums to k"<<endl;
	exit(0);
}

int main() {
	vector<int> lst = {1, 2, 3, 4, 5};
	int k = 9;
	vector<int> subarr = findContSubarr(lst,k);
	for(auto i:subarr)
		cout<<i<<" ";
	return 0;
}
