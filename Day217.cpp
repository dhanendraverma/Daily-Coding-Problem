/***************************************************************************************************************************************
This problem was asked by Oracle.
We say a number is sparse if there are no adjacent ones in its binary representation. For example, 21 (10101) is sparse, but 22 (10110) 
is not. For a given input N, find the smallest sparse number greater than or equal to N.
Do this in faster than O(N log N) time.
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int findNextSparse(int num){
	vector<bool> binary;
	while(num){
		binary.push_back(num&1);
		num >>= 1;
	}
	binary.push_back(0);
	int last=0;
	for(int i=1;i<binary.size()-1;i++){
		if(binary[i]==1 && binary[i-1]==1 && binary[i+1]==0){
			binary[i+1] = 1;
			int j=i;
			while(j>=last)
				binary[j--] = 0;
			last = i+1;
		}
	}
	
	int nextSparse=0;
	for(int i=0;i<binary.size();i++)
		nextSparse += binary[i]*(1<<i);
	return nextSparse;
}

int main() {
	int num = 1709;
	cout<<findNextSparse(num)<<endl;
	return 0;
}
