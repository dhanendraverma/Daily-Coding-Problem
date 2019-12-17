/*****************************************************************************************************************************************
This problem was asked by Facebook.
Given a number in Roman numeral format, convert it to decimal.
The values of Roman numerals are as follows:
{
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}
In addition, note that the Roman numeral system uses subtractive notation for numbers such as IV and XL.
For the input XIV, for instance, you should return 14.
******************************************************************************************************************************************/
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char,int> values = {{'I',1},{'X',10},{'V',5},{'L',50},{'C',100},{'D',500},{'M',1000}};

int romanToDec(string roman){
	int num=0;
	for(int i=0;i<roman.length();i++){
		if(i+1<roman.length() && values[roman[i]]<values[roman[i+1]]){
			num += (values[roman[i+1]]-values[roman[i]]);
			i++;
		}
		else
			num += values[roman[i]];
	}
	return num;
}

int main() {
	string roman = "MCMIVC";
	cout<<romanToDec(roman);
	return 0;
}
