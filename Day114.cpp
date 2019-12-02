/**************************************************************************************************************************************
This problem was asked by Facebook.
Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order of the delimiters.
For example, given "hello/world:here", return "here/world:hello"
Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

string reversewords(string str){
	vector<string> words;
	int start = 0; //keep trak of the last occured delimiter characters
	vector<pair<char,int>> del; //stores the delimiters along with the number of words after they should 
								//appear on string 
	for(int i=0;i<str.length();i++){
		if(str[i]==':' || str[i]=='/'){
			//this checks if there are consecutive delimiters if no consider this word
			if(i-start>1){
				// cout<<i<<" "<<start<<endl;
				// cout<<str.substr(start,i-start)<<endl;
				words.push_back(str.substr(start,i-start));
			}
			//store the delimiters along with the number of the words after which they are present in str
			del.push_back({str[i],words.size()});
			start= i+1;
		}
	}
	//if there are any word left at the last
	if(str.length()-start>1)
		words.push_back(str.substr(start,str.length()-start));
	// for(auto p:del)
	// 	cout<<p.first<<" "<<p.second<<endl;
	string ans = "";
	int cnt = 0,j=0,i=words.size()-1;
	while(j!=del.size()){
		if(del[j].second==cnt)
			ans += del[j++].first;
		else{
			ans += words[i--];
			cnt++;
		}
	}
	
	//if no of delimiters are less as compared to the words then last one would be left
	if(i>-1)
		ans += words[i];
	return ans;
}


int main() {
	string str = "//hello/imks/world:here//:";
	cout<<reversewords(str); //output : //here/world/imks:hello//:
	return 0;
}
