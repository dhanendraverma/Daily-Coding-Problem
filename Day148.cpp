/****************************************************************************************************************************************
This problem was asked by Apple.
Gray code is a binary code where each successive value differ in only one bit, as well as when wrapping around. Gray code is common in hardware so that we don't see temporary spurious values during transitions.
Given a number of bits n, generate a possible gray code for it.
For example, for n = 2, one gray code would be [00, 01, 11, 10].
*****************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateGrayCode(int n){
	if(n<=0)
		return;
	vector<string> codes;
	codes.push_back("0");
	codes.push_back("1");
	for(int i=2;i<(1<<n);i=i<<1){
		for(int j=i-1;j>=0;j--)
			codes.push_back(codes[j]);
		for(int j=0;j<i;j++)
			codes[j] = "0"+codes[j];
		for(int j=i;j<2*i;j++)
			codes[j] = "1"+codes[j];
	}
	for(auto code:codes)
		cout<<code<<endl;
}

int main() {
	int n=3;
	generateGrayCode(n);
	return 0;
}
