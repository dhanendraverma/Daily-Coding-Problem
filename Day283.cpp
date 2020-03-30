/*****************************************************************************************************************************
This problem was asked by Google.
A regular number in mathematics is defined as one which evenly divides some power of 60. Equivalently, we can say that 
a regular number is one whose only prime divisors are 2, 3, and 5.
These numbers have had many applications, from helping ancient Babylonians keep time to tuning instruments according to t
he diatonic scale.
Given an integer N, write a program that returns, in order, the first N regular numbers.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void findNRegular(int N){
    vector<int> num(N);
    int i2=0, i3=0, i5=0, next2=2, next3=3, next5=5;
    num[0]=1;
    for(int i=1;i<N;i++){
        num[i] = min(next2,min(next3,next5));
        if(num[i]==next2){
            i2++;
            next2 = num[i2]*2;
        }
        else if(num[i]==next3){
            i3++;
            next3 = num[i3]*3;
        }
        else{
            i5++;
            next5 = num[i5]*5;
        }
    }
    for(auto i:num)
        cout<<i<<" ";
}

int main() {
    int N=4;
    findNRegular(N);
	return 0;
}
