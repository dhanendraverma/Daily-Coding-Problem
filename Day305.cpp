#include <iostream>
#include <map>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        this->val = data;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    
    void insert(int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    
    void print(){
        Node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    void removeZeroSum(){
        Node *temp = head, *prev = new Node(9999);
        int sum=0;
        map<int,Node*> mp;
        while(temp){
            sum += temp->val;
            if(sum==0)
                head = temp->next;
            else if(mp.find(sum)!=mp.end()){
                mp[sum]->next = temp->next;
            }
            else
                mp[sum] = temp;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList ll;
    ll.insert(6);
    ll.insert(-6);
    ll.insert(5);
    ll.insert(7);
    ll.insert(4);
    ll.insert(3);
    ll.print();
    ll.removeZeroSum();
    ll.print();
    LinkedList ll2;
    ll2.insert(7);
    ll2.insert(9);
    ll2.insert(6);
    ll2.insert(-1);
    ll2.insert(3);
    ll2.insert(2);
    ll2.insert(-4);
    ll2.print();
    ll2.removeZeroSum();
    ll2.print();
	return 0;
}
