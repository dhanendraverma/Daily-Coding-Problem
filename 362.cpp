/*****************************************************************************************************************************
This problem was asked by Twitter.
A strobogrammatic number is a positive number that appears the same after being rotated 180 degrees.
For example, 16891 is strobogrammatic.
Create a program that finds all strobogrammatic numbers with N digits.
*****************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<string> genstrobogrammatic(int n,int len){
    if(n==0)
        return {""};
    else if(n==1)
        return {"1","0","8"};
    vector<string> mids = genstrobogrammatic(n-2,len);
    vector<string> ans = {};
    for(auto mid:mids){
        if(n!=len)
            ans.push_back("0"+mid+"0");
        ans.push_back("8"+mid+"8");
        ans.push_back("1"+mid+"1");
        ans.push_back("6"+mid+"9");
        ans.push_back("9"+mid+"6");
    }
    return ans;
}

int main() {
    int n = 4;
    vector<string> ans = genstrobogrammatic(n,n);
    for(auto str:ans)
        cout<<str<<", ";
	return 0;
}
