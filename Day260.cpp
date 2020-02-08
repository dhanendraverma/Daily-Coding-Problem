/*****************************************************************************************************************************
The sequence [0, 1, ..., N] has been jumbled, and the only clue you have for its order is an array representing whether each
number is larger or smaller than the last. Given this information, reconstruct an array that is consistent with it.
For example, given [None, +, +, -, +], you could return [1, 2, 3, 0, 4].
/*****************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> reconstructArr(vector<char> arr){
	int n = arr.size();
	int plus_cnt = 0;
	for(int i=0;i<n;i++){
		if(arr[i]=='+')
			plus_cnt++;
	}
	int first = n-plus_cnt-1;
	int sm = first-1, lg = first+1;
	vector<int> ans(n);
	ans[0] = first;
	for(int i=1;i<n;i++){
		if(arr[i]=='+')
			ans[i] = lg++;
		else
			ans[i] = sm--;
	}
	return ans;
}

int main() {
	vector<char> arr = {NULL,'+', '+', '-', '+'};
	vector<int> ans = reconstructArr(arr);
	for(auto num:ans)
		cout<<num<<" ";
	return 0;
}
