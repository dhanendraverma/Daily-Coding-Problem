/*****************************************************************************************************************************************
This problem was asked by Google.
You're given a string consisting solely of (, ), and *. * can represent either a (, ), or an empty string. Determine whether the 
parentheses are balanced.
For example, (()* and (*) are balanced. )*( is not balanced.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

bool isBalanaced(string str){
	int star=0, open=0;
	for(auto i:str){
		if(i==')'){
			if(open)
				open--;
			else if(star)
				star--;
			else
				return false;
		}
		else if(i=='(')
			open++;
		else 
			star++;
	}
	if(open>star)
		return false;
	return !((open-star)%2);
}

int main() {
	string str = "*)((*(*))*";
	cout<<isBalanaced(str)<<endl;
	return 0;
}
