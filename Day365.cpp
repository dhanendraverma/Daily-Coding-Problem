/******************************************************************************************************************************
This problem was asked by Google.
A quack is a data structure combining properties of both stacks and queues. It can be viewed as a list of elements written
left to right such that three operations are possible:
push(x): add a new item x to the left end of the list
pop(): remove and return the item on the left end of the list
pull(): remove the item on the right end of the list.
Implement a quack using three stacks and O(1) additional memory, so that the amortized time for any push, pop, or pull 
operation is O(1).
******************************************************************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

class Quack{
    public:
    stack<int> left,right,aux;
    Quack(){
    }
    void push(int e){
        left.push(e);
    }
    
    int pop(){
        if(left.size()==0 && right.size()==0){
            cout<<"There is no element inside Quack.";
            return 0;
        }
        else if(left.size()==0){
            int i=0,n=right.size()/2;
            while(i<n){
                aux.push(right.top());
                right.pop();
                i++;
            }
            while(right.size()){
                left.push(right.top());
                right.pop();
            }
            while(aux.size()){
                right.push(aux.top());
                aux.pop();
            }
        }
        int e = left.top();
        left.pop();
        return e;
    }
    
    int pull(){
        if(left.size()==0 && right.size()==0){
            cout<<"There is no element inside Quack.";
            return 0;
        } 
        else if(right.size()==0){
            int i=0,n=left.size()/2;
            while(i<n){
                aux.push(left.top());
                left.pop();
                i++;
            }
            while(left.size()){
                right.push(left.top());
                left.pop();
            }
            while(aux.size()){
                left.push(aux.top());
                aux.pop();
            }
        }
        int e = right.top();
        right.pop();
        return e;
    }
};

int main() {
    Quack q;
    q.push(2);
    q.push(4);
    q.push(-3);
    q.push(-4);
    q.push(345);
    q.push(54);
    cout<<q.pop()<<endl;
    cout<<q.pull()<<endl;
	return 0;
}
