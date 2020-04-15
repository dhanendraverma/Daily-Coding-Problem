/*****************************************************************************************************************************
This problem was asked by LinkedIn.
You are given a string consisting of the letters x and y, such as xyxxxyxyy. In addition, you have an operation called flip, 
which changes a single x to y or vice versa.
Determine how many times you would need to apply this operation to ensure that all x's come before all y's. In the preceding 
example, it suffices to flip the second and sixth characters, so you should return 2.
******************************************************************************************************************************/

#include <iostream>
using namespace std;

int minFlips(string str){
    int n = str.length();
    int forward = 0, backward = 0;
    int i = -1,j = n;
    while(str[++i]=='x');
    while(str[--j]=='y');
    // cout<<i<<" "<<j<<endl;
    while(i<=j){
        if(str[i]=='y')
            forward++;
        else
            backward++;
        i++;
    }
    return forward<backward?forward:backward;
}

int main() {
    string str = "xyxxxyxyy";
    cout<<minFlips(str)<<endl;
	return 0;
}
