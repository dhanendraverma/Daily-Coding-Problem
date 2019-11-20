/*************************************************************************************************************************************
This problem was asked by Google.
Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. If such a subset
cannot be made, then return null.
Integers can appear more than once in the list. You may assume all numbers in the list are positive.
For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
**************************************************************************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int> input, int total,vector<int>& ans) {
	vector<vector<bool>> T(input.size()+1,vector<bool>(total+1,false));
	for (int i = 0; i <= input.size(); i++) 
            T[i][0] = true;
    for (int i = 1; i <= input.size(); i++) {
    	for (int j = 1; j <= total; j++) {
    		if (j - input[i - 1] >= 0) 
    			T[i][j] = T[i - 1][j] || T[i - 1][j - input[i - 1]];
    		else 
                T[i][j] = T[i-1][j];
                
            }
    }
    
    if( T[input.size()][total]){
    	int i=input.size(),j=total;
    	while(true){
    		while(T[i][j]) {i--;}
    		ans.push_back(input[i]);
    		j-=input[i];
    		if(j<=0)
    			break;
    		
    	}
    }
        
    return T[input.size()][total];
	
}

int main() {
	vector<int> input = {12, 1, 61, 5, 9, 2};
	int total = 24;
	vector<int> ans;
	if(subsetSum(input,total,ans)){
		for(auto i:ans)
			cout<<i<<" ";
	
	}
		return 0;
}
