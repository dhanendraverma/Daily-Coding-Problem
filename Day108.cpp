/*************************************************************************************************************************************
This problem was asked by Google.
Given two strings A and B, return whether or not A can be shifted some number of times to get B.
For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.
**************************************************************************************************************************************

#include <iostream>
using namespace std;

//this solution fails for the input with the repeated characters like A = "AACD" B = "ACDA"
bool canShifted(string A, string B){
	if(A.length()!=B.length())
		return false;
	int i;
	for(i=0;i<A.length();i++){
		if(A[i]==B[0])
			break;
	}
	if(i==A.length())
		return false;
	int j = i+1;
	int k = 1;
	while(j!=i){
		j = j%A.length();
		if(A[j++]!=B[k++])
			return false;
	}
	return true;
}

bool areRotation(string A, string B){
	if(A.length()!=B.length())
		return false;
	A = A+A;
	return (A.find(B)!=string::npos);
}

int main() {
	string A = "abcde";
	string B = "cdeab";
	cout<<canShifted(A,B)<<endl;
	cout<<areRotation<<endl;
	return 0;
}
