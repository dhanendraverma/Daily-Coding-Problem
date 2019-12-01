/***************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Alibaba.
Given an even number (greater than 2), return two prime numbers whose sum will be equal to the given number.
A solution will always exist. See Goldbach’s conjecture.
Example:
Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible, return the lexicographically smaller solution.
If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then
[a, b] < [c, d]
If a < c OR a==c AND b < d.
***************************************************************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void SieveOfEratosthenes(vector<bool>& isPrime){
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i*i<isPrime.size();i++){
		if(isPrime[i]==true){
			for(int j=i*i;j<isPrime.size();j+=i)
				isPrime[j] = false;
		}
	}
}

void findPrimes(int n){
	vector<bool> isPrime(n+1,true);
	SieveOfEratosthenes(isPrime);
	for(int i=0;i<isPrime.size();i++){
		if(isPrime[i] && isPrime[n-i]){
			cout<<i<<" "<<n-i;
			break;
		}
	}
} 

int main() {
	int n = 122;
	findPrimes(n);
	return 0;
}
