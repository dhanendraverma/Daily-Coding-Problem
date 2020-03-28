/*****************************************************************************************************************************
This problem was asked by Epic.
The "look and say" sequence is defined as follows: beginning with the term 1, each subsequent term visually describes the 
digits appearing in the previous term. The first few terms are as follows:
1
11
21
1211
111221
As an example, the fourth term is 1211, since the third term consists of one 2 and one 1.
Given an integer N, print the Nth term of this sequence.
******************************************************************************************************************************/

#include <iostream>
using namespace std;

string lookAndSayNth(int N){
    if(N<=0)
        return "Please enter a number greater than 0.";
    string temp = "1";
    if(N==1)
        return temp;
    for(int i=2;i<=N;i++){
        int cnt=1;
        string curr = "";
        for(int j=1;j<temp.length();j++){
            if(temp[j]!=temp[j-1]){
                curr += to_string(cnt)+temp[j-1];
                cnt = 1;
            }
            else
                cnt++;
        }
        curr += to_string(cnt)+temp[temp.length()-1];
        temp = curr;
    }
    return temp;
}

int main() {
    int N = 5;
    cout<<lookAndSayNth(N)<<endl;
	return 0;
}
