/*****************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Apple.
Implement the function fib(n), which returns the nth number in the Fibonacci sequence, using only O(1) space.
*****************************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void multiply(vector<vector<long long>>& F1,vector<vector<long long>>& F2){
	long long  x = F1[0][0]*F2[0][0] + F1[0][1]*F2[1][0];
	long long  y = F1[0][0]*F2[0][1] + F1[0][1]*F2[1][1];
	long long  z = F1[1][0]*F2[0][0] + F1[1][1]*F2[1][0];
	long long  w= F1[1][0]*F2[0][1] + F1[1][1]*F2[1][1];
	F1[0][0] = x; 
	F1[0][1] = y; 
	F1[1][0] = z; 
	F1[1][1] = w; 
}


void power(vector<vector<long long >>& F, int n){
	if(n==0 || n==1)
		return;
	vector<vector<long long >> M = {{1,1},{1,0}};
	power(F,n/2);
	multiply(F,F);
	if(n%2)
		multiply(F,M);
}

long long fib2(int n){
	vector<vector<long long>> F = {{1,1},{1,0}};
	if(n==0)
		return 0;
	power(F,n-1);
	return F[0][0];
}

long long fib(int n){
	long long a=0,b=1,c;
	for(int i=2;i<=n;i++){
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}

long long fib1(int n){
	double temp = (1+sqrt(5))/2;
	return round(pow(temp,n)/sqrt(5));
}

int main() {
	int n=9;
	cout<<fib(n)<<endl;
	cout<<fib1(n)<<endl;
	cout<<fib2(n)<<endl;
	return 0;
}
