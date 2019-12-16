/***************************************************************************************************************************************
This problem was asked by Apple.
A Collatz sequence in mathematics can be defined as follows. Starting with any positive integer:
if n is even, the next number in the sequence is n / 2
if n is odd, the next number in the sequence is 3n + 1 
It is conjectured that every such sequence eventually reaches the number 1. Test this conjecture.
Bonus: What input n <= 1000000 gives the longest sequence?
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

bool checkCollatz(long int n, int& len){
	len++;
	if(n<=0) 
		return false;
	if(n==1) 
		return true;
	if(n%2==1) 
		return checkCollatz(3*n+1,len);
	return checkCollatz(n/2,len);
}
 
int maxLenSeq(int N=1000000){
	int mx=0,n;
	for (int i=1; i<N; i++){
    	int len=0;
    	checkCollatz(i,len);
    	if(len>mx) {
    		mx=len;
    		n = i;
    	}
	}
  return n;
}

int main() {
	int n=23,count=0;
	cout<<checkCollatz(n,count)<<endl;
	cout<<maxLenSeq()<<endl;
	return 0;
}
