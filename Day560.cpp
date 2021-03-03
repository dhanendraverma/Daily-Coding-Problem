/*************************************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was recently asked by Google.
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?
*************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


//O(N) time and O(k) space doesn't work fir negative numbers
int addUptoKArr(vector<int> lst, int k){
	vector<bool> remainders(k,false);
	for(int i=0;i<lst.size();i++){
		if(lst[i]<k){
			if(remainders[k-lst[i]]){
				cout<<lst[i]<<" "<<k-lst[i]<<endl;
				return 1;
			}
			remainders[lst[i]] = true;
		}
	}
	return false;
}


//O(N) time and O(N) space
int addUptoKMap(vector<int> lst, int k){
	map<int,bool> mp;
	for(int i=0;i<lst.size();i++){
		if(mp[k-lst[i]]){
			cout<<lst[i]<<" "<<k-lst[i]<<endl;
			return true;
		}
		mp[lst[i]] = true;
	}
	return false;
}



//O(NlogN) time and O(1) space
int addUptoK(vector<int> lst, int k){
	sort(lst.begin(),lst.end());
	int left = 0, right = lst.size()-1;
	while(left<right){
		if(lst[left]+lst[right]<k)
			left++;
		else if(lst[left]+lst[right]>k)
			right--;
		else{
			cout<<lst[left]<<" "<<lst[right]<<endl;
			return true;
		}
	}
	return false;
}


int main() {
	vector<int> lst = {1, 4, 45, 6, 10, -8 };
	int k = 16;
	cout<<addUptoK(lst, k)<<endl;
	cout<<addUptoKMap(lst, k)<<endl;
	cout<<addUptoKArr(lst, k)<<endl;
	return 0;
}
