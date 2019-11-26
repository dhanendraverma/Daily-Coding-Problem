/****************************************************************************************************************************************
This problem was asked Microsoft.
Using a read7() method that returns 7 characters from a file, implement readN(n) which reads n characters.
For example, given a file with the content “Hello world”, three read7() returns “Hello w”, “orld” and then “”.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

string read7(){
	string file_contents = "Lorem Ipsum is simply dummy text of";
	static int read_till=0;
	static int start = 0;
	start += read_till;
	read_till = 7<(file_contents.length()-start)?7:(file_contents.length()-start);
	cout<<read_till<<" "<<start<<endl;
	if(start>=file_contents.length())
		return "";
	return file_contents.substr(start,read_till);
}

string readN(int n){
	int m = n/7;
	int rem = n%7;
	string n_chars = "";
	while(m--){
		// cout<<read7()<<endl;
		n_chars += read7();
	}
	string last = read7().substr(0,rem);
	if(rem)
		return n_chars+last;
	return n_chars+"";
}

int main() {
	int n = 70;
	cout<<readN(n);
	return 0;
}
