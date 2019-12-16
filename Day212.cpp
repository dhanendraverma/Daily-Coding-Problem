/*****************************************************************************************************************************************
This problem was asked by Dropbox.
Spreadsheets often use this alphabetical encoding for its columns: "A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....
Given a column number, return its alphabetical column id. For example, given 1, return "A". Given 27, return "AA".
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

string columnId(int n){
	string id="";
	while(n){
		if(n%26){
			char temp = 'A'+(n%26-1);
			id = temp+id;
			n = n/26;
		}
		else{
			id = "Z"+id;
			n = (n/26)-1;
		}
	}
	return id;
}

int main() {
	int col = 706;
	cout<<columnId(col)<<endl;
	return 0;
}
