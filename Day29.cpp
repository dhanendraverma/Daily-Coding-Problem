/****************************************************************************************************************************************
This problem was asked by Amazon.
Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as
a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".
Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic 
characters. You can assume the string to be decoded is valid.
*****************************************************************************************************************************************/

#include <iostream>
using namespace std;

string encoding(string str){
	int ltrCnt = 1;
	string encoded = "";
	char prev = str[0];
	for(int i=1;i<str.length();i++){
		if(str[i]==prev)
			ltrCnt++;
		else{
			encoded += prev+to_string(ltrCnt);
			prev = str[i];
			ltrCnt = 1;
		}
	}
	encoded += str[str.length()-1]+to_string(ltrCnt);
	return encoded;
}

string decoding(string str){
	string decoded = "";
	for(int i=0;i<str.length();i+=2){
		int cnt = str[i+1]-'0';
		while(cnt--){
			decoded += str[i];
		}
	}
	return decoded;
}
int main() {
	string str;
	cin>>str;
	string encoded = encoding(str);
	cout<<"encoded string of "<<str<<" is "<<encoded<<endl; 
	//encoded string of AAAABBBCCDAAeeeee is A4B3C2D1A2e5
	cout<<"decoded string is "<<decoding(encoded)<<endl;
	// decoded string is AAAABBBCCDAAeeeee
	return 0;
}
