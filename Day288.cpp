/*****************************************************************************************************************************
This problem was asked by Salesforce.
The number 6174 is known as Kaprekar's contant, after the mathematician who discovered an associated property: 
for all four-digit numbers with at least two distinct digits, repeatedly applying a simple procedure eventually 
results in this value. The procedure is as follows:
For a given input x, create two new numbers that consist of the digits in x in ascending and descending order.
Subtract the smaller number from the larger number.
For example, this algorithm terminates in three steps when starting from 1234:
4321 - 1234 = 3087
8730 - 0378 = 8352
8532 - 2358 = 6174
Write a function that returns how many steps this will take for a given input N.
******************************************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int stepsToKaprekars(int num,int steps){
    vector<int> digits;
    while(num){
        digits.push_back(num%10);
        num = num/10;
    }
    sort(digits.begin(),digits.end());
    int n = digits.size();
    if(n!=4){
        cout<<"Input number must be a 4 digit number"<<endl;
        return -1;
    }
    int dist_cnt=0;
    for(int i=1;i<n;i++){
        if(digits[i]==digits[i-1])
            dist_cnt++;
        if(dist_cnt>2){
            cout<<"Input number musr contain atleast two distinct digits"<<endl;
            return -1;
        }
    }
    int asc=0,des=0;
    for(int i=0;i<n;i++){
        asc = asc*10+digits[i];
        des = des*10+digits[n-i-1];
    }
    int diff = des-asc;
    if(diff==6174)
        return steps;
    return stepsToKaprekars(diff,steps+1);
}

int main() {
    int num = 1234;
    cout<<stepsToKaprekars(num,1)<<endl;
	return 0;
}
