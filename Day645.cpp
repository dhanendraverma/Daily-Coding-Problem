/*************************************************************************************************************************************
This problem was asked by Microsoft.
Given a 2D matrix of characters and a target word, write a function that returns whether the word can be found in the matrix by going
left-to-right, or up-to-down.
For example, given the following matrix:
[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]
and the target word 'FOAM', you should return true, since it's the leftmost column. Similarly, given the target word 'MASS', you should
return true, since it's the last row.
**************************************************************************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

bool wordSearchUtil(vector<vector<char>> mat,int row, int col, string word){
	if(mat[row][col]!=word[0])
		return false;
	cout<<row<<" "<<col<<endl;
	int len = word.length();
	int i=0;
	if(mat.size()-row>=len){
		for(i=1;i<word.length();i++){
			if(word[i]!=mat[row+i][col])
				break;
		}
		if(i==word.length())
		return true;
	}
	if(mat[0].size()-col>=len){
		for(i=1;i<word.length();i++){
			if(word[i]!=mat[row][col+i])
				break;
		}
		if(i==word.length())
			return true;
	}
	return false;
}


bool word_search(vector<vector<char>> mat,string word){
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
			if(wordSearchUtil(mat,i,j,word))
				return true;
		}
	}
	return false;
}

int main() {
	vector<vector<char>> mat = {{'F', 'A', 'C', 'I'},
								{'O', 'B', 'Q', 'P'},
								{'A', 'N', 'O', 'B'},
								{'M', 'A', 'S', 'S'}}; 
    string word = "FOAM";
    cout<<word_search(mat,word);                			
	return 0;
}
