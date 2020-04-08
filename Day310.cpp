/*****************************************************************************************************************************
This problem was asked by Pivotal.
Write an algorithm that finds the total number of set bits in all integers between 1 and N.
******************************************************************************************************************************/

#include <iostream>
using namespace std;

int countSetBits(int n){
    n = n+1;
    int k = 2, setBits = n/2;
    while(k<n){
        int pairs = n/k;
        setBits += (pairs/2)*k;
        setBits += (pairs&1)?(n%k):0;
        k<<=1;
    }
    return setBits;
}

int main() {
    int N = 14;
    cout<<countSetBits(N)<<endl;
	return 0;
}
