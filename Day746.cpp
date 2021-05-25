#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class Stack{
	public:
	stack<int> st;
	int mx;
	Stack(){
		this->mx = INT_MIN;
	}
		
	void push(int ele){
		if(st.empty())
			mx = ele;
		if(ele > mx){
			st.push(2*ele - mx);
			mx = ele;
		}
		else
			st.push(ele);
	}
	
	int pop(){
		int top_ele = st.top();
		st.pop();
		if(top_ele > mx){
			int old_mx = mx;
			mx = 2*mx - top_ele;
			return old_mx;
		}
		return top_ele;
	}
	
	int Max(){
		return mx;
	}
};


int main() {
	Stack s;
	s.push(2);
	s.push(10);
	s.push(45);
	cout<<s.Max()<<endl;
	s.push(67);
	s.push(1);
	s.push(76);
	cout<<s.Max()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.Max()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.Max()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.Max()<<endl;
	return 0;
}
