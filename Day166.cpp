/**************************************************************************************************************************************
This problem was asked by Uber.
Implement a 2D iterator class. It will be initialized with an array of arrays, and should implement the following methods:
next(): returns the next element in the array of arrays. If there are no more elements, raise an exception.
has_next(): returns whether or not the iterator still has elements left.
For example, given the input [[1, 2], [3], [], [4, 5, 6]], calling next() repeatedly should output 1, 2, 3, 4, 5, 6.
Do not use flatten or otherwise clone the arrays. Some of the arrays can be empty.
**************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class TwoDitr{
	int i,j,n;
	vector<vector<int>> ele;
	public:
	TwoDitr(vector<vector<int>> arr){
		this->ele = arr;
		this->i = 0;
		this->j = 0;
		this->n = arr.size();
	}
	
	bool has_next(){
		if(j<ele[i].size())
			return true;
		else{
			i++;
			while(i<n && ele[i].size()==0)
				i++;
			j = 0;
			if(i<n)
				return true;
		}
		return false;
	}
	
	int next(){
		int next;
		if(has_next()){
			next = ele[i][j];
			j++;
		}
		else{
			cout<<"No more elements left"<<endl;
			exit(0);
		}
		return next;
	}
};




int main() {
	vector<vector<int>> arr = {{1,2},{3},{},{4,5,6},{},{}};
	TwoDitr itr(arr);
	cout<<itr.has_next()<<endl;
	cout<<itr.next()<<endl;
	cout<<itr.next()<<endl;
	cout<<itr.next()<<endl;
	cout<<itr.next()<<endl;
	cout<<itr.next()<<endl;
	cout<<itr.next()<<endl;
	cout<<itr.next()<<endl;
	cout<<itr.next()<<endl;
	return 0;
}
