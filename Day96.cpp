/*****************************************************************************************************************************************
This problem was asked by Microsoft.
Given a number in the form of a list of digits, return all possible permutations.
For example, given [1,2,3], return [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].
*****************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void printLst(vector<int> digLst){
	for(auto i:digLst)
		cout<<i<<" ";
	cout<<endl;
}

void generateAll(vector<int>& digLst,int l, int r){
	if(l==r)
		printLst(digLst);
	else{
		for(int i=l;i<=r;i++){
			swap(digLst[i],digLst[l]);
			generateAll(digLst,l+1,r);
			swap(digLst[i],digLst[l]);
		}
	}
}
int main() {
	vector<int> digLst = {1,2,3};
	generateAll(digLst,0,digLst.size()-1);
	return 0;
}
