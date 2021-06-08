/****************************************************************************************************************************************
This problem was asked by Snapchat.
Given a string of digits, generate all possible valid IP address combinations.
IP addresses must follow the format A.B.C.D, where A, B, C, and D are numbers between 0 and 255. Zero-prefixed numbers, such as 01 and 065, are not allowed, except for 0 itself.
For example, given "2542540123", you should return ['254.25.40.123', '254.254.0.123'].
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<string> convert(string digits){ 
	int l = digits.length(); 
    if ( l>12 || l<4 ) 
    	return {};
    string temp=digits; 
    vector <string> ans; 
    for( int i = 1; i < l - 2; i++ ){ 
    	for( int j = i + 1; j < l - 1; j++ ){
    		for( int k = j + 1; k < l; k++ ) {
            	if((l-k<4) && (k-j<4) && i<4 && (j-i<4)){
            		if(digits[i]!='0' && digits[j]!='0' && digits[k]!='0'){
            			if( stoi(digits.substr(0,i))<256 && stoi(digits.substr(i,j-i))<256 && stoi(digits.substr(j,k-j))<256 && stoi(digits.substr(k))<256 )
            				ans.push_back(digits.substr(0,i)+"."+digits.substr(i,j-i)+"."+digits.substr(j,k-j)+"."+digits.substr(k));
            		}
            	}
            } 
        } 
    }
    return ans;
} 

int main() {
	string digits = "25525511135";
	vector<string> ips = convert(digits);
	for(auto ip:ips)
		cout<<ip<<" ";
	return 0;
}
