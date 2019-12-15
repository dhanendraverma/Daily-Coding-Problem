/*****************************************************************************************************************************************
This problem was asked by Palantir.
Write a program that checks whether an integer is a palindrome. For example, 121 is a palindrome, as well as 888. 678 is not a 
palindrome. Do not convert the integer into a string.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

bool isPalhelper(int num, int& num2){
	if(num>=0 && num<10)
		return (num==num2%10);
	if(!isPalhelper(num/10,num2))
		return false;
	num2 = num2/10;
	return (num%10==num2%10);
}


bool isPal(int num){
	if(num<0)
		num *= -1;
	int num2 = num;
	return isPalhelper(num,num2);
	
}
int main() {
	int num = 909909;
	cout<<isPal(num)<<endl;
	return 0;
}
