/**************************************************************************************************************************************
This problem was asked by IBM.
Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is not possible, 
return None.
For example, given "aaabbc", you could return "ababac". Given "aaab", return None.
***************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool noRepeatingAdj(string str){
	vector<int> f(256,0);
	for(int i=0;i<str.length();i++){
		f[str[i]]++;
		if(f[str[i]]>str.length()/2)
			return false;
	}
	sort(str.begin(),str.end());
	int i=0,j=str.length()-1;
	string ans="";
	while(i<str.length()/2){
		ans += str[i++];
		ans += str[j--];
	}
	cout<<ans<<endl;
	return true;
}

string reArrange(string str){
	int n = str.length();
	vector<int> fre(26,0);
	int fx = 0;
    char x;
    for(int i = 0; i < n; i++)
    {
        fre[str[i]-'a']++;
        if(fre[str[i]-'a'] > fx)
            x = str[i], fx = fre[str[i]-'a'];
    }
    fre[x-'a'] = 0;

    
    if(fx > (n+1)/2)
        return ""; 
    
    string ans = str;        
    int j = 0, i = 1;
    while(j<26)
    {
        if(fre[j])
            ans[i] = (j+'a'), fre[j]--, i += 2;
        else
            j++;
        if(i>=n)
            i = 0;
    }
    while(i < n)
        ans[i] = x, i += 2;
    return ans;
}

int main() {
	string str = "aaaabbbc";
	cout<<noRepeatingAdj(str)<<endl;
	cout<<reArrange(str)<<endl;
	return 0;
}
