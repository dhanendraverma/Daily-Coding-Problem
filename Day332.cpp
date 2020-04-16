/******************************************************************************************************************************
This problem was asked by Jane Street.
Given integers M and N, write a program that counts how many positive integer pairs (a, b) satisfy the following conditions:
a + b = M
a XOR b = N
******************************************************************************************************************************/

#include <iostream>
using namespace std;

int countPairs(long long N, long long M){
    long long K = M-N;
    if(K%2)
        return 0;
    K = K>>1;
    int pairs = 1;
    for(int i=1;i<=64;i++){
        int kb = K&1;
        int nb = N&1;
        if(nb==1 && kb==1)
            return 0;
        else if(nb==1 && kb==0)
            pairs *= 2;
        K = K>>1;
        N = N>>1;
    }
    return pairs;
}

int main() {
    long long N = 12, M = 14;
    cout<<countPairs(N,M)<<endl;
	return 0;
}
