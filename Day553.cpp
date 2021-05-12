/****************************************************************************************************************************************
This problem was asked by Google.
You are given an N by M 2D matrix of lowercase letters. Determine the minimum number of columns that can be removed to ensure that
each row is ordered from top to bottom lexicographically. That is, the letter at each column is lexicographically later as you go down
each row. It does not matter whether each row itself is ordered lexicographically.
For example, given the following table:
cba
daf
ghi
This is not ordered because of the a in the center. We can remove the second column to make it ordered:
ca
df
gi
So your function should return 1, since we only needed to remove 1 column.
As another example, given the following table:
abcdef
Your function should return 0, since the rows are already ordered (there's only one row).
As another example, given the following table:
zyx
wvu
tsr
Your function should return 3, since we would need to remove all the columns to order it.
*****************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int removalForLex(vector<vector<char>> matrix){
	int n = matrix.size();
	if(n==0 || n==1)
		return 0;
	int removals = 0;
	for(int col=0;col<matrix[0].size();col++){
		for(int row=1;row<n;row++)
			if(matrix[row][col]<matrix[row-1][col])
			{
				removals++;
				break;
			}		
	}
	return removals;
}

int main() {
	vector<vector<char>> matrix = {{'c','b','a'},
                                 {'d','a','f'},
                                 {'g','h','i'}};
	cout<<removalForLex(matrix)<<endl;
	matrix = {{'a','b','c','d','e','f'}};
	cout<<removalForLex(matrix)<<endl;
	matrix = {{'z','y','x'},
			  {'w','v','u'},
	 	      {'t','s','r'}};
	cout<<removalForLex(matrix)<<endl;
	return 0;
}
