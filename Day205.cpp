/**************************************************************************************************************************************
This problem was asked by IBM.
Given an integer, find the next permutation of it in absolute order. For example, given 48975, the next permutation would be 49578.
***************************************************************************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

string next_per(int num){
	string temp = to_string(num);
	next_permutation(temp.begin(),temp.end());
	return temp;
}

string findNext(int num) 
{ 
	string number = to_string(num);
	int i, j,n = number.length();
	for (i = n-1; i > 0; i--) 
		if (number[i] > number[i-1]) 
		break; 
	if (i==0) 
	{ 
		cout << "Next number is not possible"; 
		return ""; 
	} 
	int smallest = i; 
	for (j = i+1; j < n; j++) 
		if (number[j] > number[i-1] && number[j] < number[smallest]) 
			smallest = j; 
	swap(number[smallest], number[i-1]); 
	sort(number.begin() + i, number.begin() + n); 
	return number; 
} 

int main() {
	int num = 48975;
	cout<<next_per(num)<<endl;
	int t = 48975;
	cout<<findNext(t);
	return 0;
}
