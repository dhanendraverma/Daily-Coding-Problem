#include <iostream>
#include <vector>
using namespace std;

void printZigzagForm(string str, int k){
	vector<vector<char>> zigzag(k,vector<char>(str.length(),' '));
	int row=0,col=0,dir=1;
	for(int i=0;i<str.length();i++){
		zigzag[row][col] = str[i];
		if(row==k-1)
			dir = 0;
		else if(row==0)
			dir = 1;
		if(dir==1)
			row++;
		else
			row--;
		col++;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<str.length();j++)
			cout<<zigzag[i][j];
		cout<<endl;
	}
}

int main() {
	string str = "thisisazigzag";
	int k = 4;
	printZigzagForm(str,k);
	return 0;
}
