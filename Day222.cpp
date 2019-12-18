/****************************************************************************************************************************************
This problem was asked by Quora.
Given an absolute pathname that may have . or .. as part of it, return the shortest standardized path.
For example, given "/usr/bin/../bin/./scripts/../", return "/usr/bin/".
*****************************************************************************************************************************************/
#include <iostream>
#include <stack>
using namespace std;

string shortestpath(string path){
	string temp="";
	stack<string> s;
	for(int i=1;i<path.length();i++){
		while(i<path.length() && path[i]!='/')
			temp += path[i++];
		if(temp==".."){
			if(!s.empty())
				s.pop();
		}
		else{
			if(temp!="." && temp!="/" && temp!="")
				s.push(temp);
		}
		temp = "";
	}
	string shortest="";
	while(!s.empty()){
		shortest = "/"+s.top()+shortest;
		s.pop();
	}
	return shortest!=""?shortest:"/";
}


int main() {
	string absolutePath = "/usr/bin/../bin/./scripts/../";
	cout<<shortestpath(absolutePath)<<endl;
	return 0;
}
