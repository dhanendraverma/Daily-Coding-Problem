/****************************************************************************************************************************************
This problem was asked by Google.
The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.
For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
You may also use a list or array to represent a set.
****************************************************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate_power_set(vector<int> set){
	vector<vector<int>> ans;
	vector<int> temp;
	unsigned int pow_set_size = pow(2,set.size());
	for(int i=0;i<pow_set_size;i++){
		for(int j=0;j<set.size();j++){
			if(i&(1<<j))
				temp.push_back(set[j]);
		}
		ans.push_back(temp);
		temp.clear();
	}
	return ans;
}

int main() {
	vector<int> set = {1, 2, 3};
	vector<vector<int>> ans = generate_power_set(set);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
