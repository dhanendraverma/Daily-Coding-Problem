/*****************************************************************************************************************************
This problem was asked by Palantir.
The ancient Egyptians used to express fractions as a sum of several terms where each numerator is one. For example, 4 / 13 
can be represented as 1 / 4 + 1 / 18 + 1 / 468.
Create an algorithm to turn an ordinary fraction a / b, where a < b, into an Egyptian fraction.
******************************************************************************************************************************/

#include <iostream>
using namespace std;

void findEgyptianFraction(int a,int b){
	if(a==0 || b==0)
		return;
	if(b%a==0){
		cout<<"1/"<<b/a;
		return;
	}
	if(a%b==0){
		cout<<a/b;
		return;
	}
	if(a>b){
		cout<<a/b<<"+";
		findEgyptianFraction(a%b,b);
		return;
	}
	int temp = b/a+1;
	cout<<"1/"<<temp<<"+";
	findEgyptianFraction(a*temp-b,b*temp);
}

int main() {
	int a=6,b=14;
	findEgyptianFraction(a,b);
	return 0;
}
