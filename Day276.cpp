/*****************************************************************************************************************************
This problem was asked by Dropbox.
Implement an efficient string matching algorithm.
That is, given a string of length N and a pattern of length k, 
write a program that searches for the pattern in the string with less than O(N * k) worst-case time complexity.
If the pattern is found, return the start index of its location. If not, return False.
*****************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void computeLPS(string pat,vector<int>& lps){
    lps[0] = 0;
    int curr_len = 0;
    int i=1;
    while(i<pat.length()){
        if(pat[i]==pat[curr_len]){
            curr_len++;
            lps[i] = curr_len;
            i++;
        }
        else{
            if(curr_len!=0)
                curr_len = lps[curr_len-1];
            else
                lps[i] = 0;
                i++;
        }
    }
}

int KMPSearch(string str, string pat){
    int n = str.length();
    int k = pat.length();
    vector<int> lps(n);
    computeLPS(pat,lps);
    int i=0,j=0;
    while(i<n){
        if(pat[j]==str[i]){
            j++;
            i++;
        }
        if(j==k)
            return i-k;
        else if(i<n && pat[j]!=str[i]){
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
}

int main() {
    string str = "ABABDABACDABABCABAB", pattern = "ABABCABAB";
    cout<<KMPSearch(str,pattern)<<endl;
	return 0;
}
