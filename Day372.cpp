/********************************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Write a function that takes a natural number as input and returns the number of digits the input has.

Constraint: don't use any loops.
********************************************************************************************************************************************************/


#include <iostream>
#include <cmath>
using namespace std;

int no_of_digits(int n){
    return to_string(n).length();
}

int no_of_digits_rec(int n){
    if(n==0)
        return 0;
    return no_of_digits_rec(n/10)+1;
}

int no_of_digits_log(int n){
    return floor(log10(n)+1);
}

int main() {
    int n = 4655734;
    cout<<no_of_digits(n)<<endl;
    cout<<no_of_digits_rec(n)<<endl;
    cout<<no_of_digits_log(n)<<endl;
	return 0;
}
