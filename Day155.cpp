/**************************************************************************************************************************************
This problem was asked by MongoDB.
Given a list of elements, find the majority element, which appears more than half the time (> floor(len(lst) / 2.0)).
You can assume that such element exists.
For example, given [1, 2, 1, 1, 3, 4, 0], return 1.
***************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

//Moore's Algorithm this won't work when the majority element occurs exactly half times of the length
int findMajorityEle(vector<int> lst){
	int cnt=1, idx=0;
	for(int i=1;i<lst.size();i++){
		if(lst[i]==lst[idx])
			cnt++;
			
		else{
			cnt--;
			if(cnt==0){
				idx = i;
				cnt =1;
			}
		}
	}
	return lst[idx];
}

int findMajorityEle1(vector<int> lst){
	map<int,int> cnt;
	int lmt = floor(lst.size()/2.0);
	for(int i=0;i<lst.size();i++){
		cnt[lst[i]]++;
		if(cnt[lst[i]]>=lmt)
			return lst[i];
	}
	return NULL;
}

int main() {
	vector<int> lst = {1, 2, 1, 1, 3, 4, 0};
	// cout<<findMajorityEle(lst)<<endl;
	cout<<findMajorityEle1(lst)<<endl;
	return 0;
}
