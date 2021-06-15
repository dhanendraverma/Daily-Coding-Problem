/****************************************************************************************************************************************
This problem was asked by Twitter.
Given a list of numbers, create an algorithm that arranges them in order to form the largest possible integer. For example, given
[10, 7, 76, 415], you should return 77641510.
*****************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string A, string B){
		return (A+B)>(B+A);
}

int largestPossibleInt(vector<int> number){
	vector<string> temp;
	for(auto i:number)
		temp.push_back(to_string(i));
	sort(temp.begin(),temp.end(),comp);
	string ans = "";
	for(auto i:temp)
		ans += i;
	return stoi(ans);
}

int main() {
	vector<int> number = {10, 7, 76, 415};
	cout<<largestPossibleInt(number)<<endl;
	return 0;
}
