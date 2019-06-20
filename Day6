/***********************************************************************************************************************************
An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields,
it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; 
it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and 
dereference_pointer functions that converts between nodes and memory addresses.
*************************************************************************************************************************************/
#include<bits/stdc++.h>
#include<inttypes.h>

using namespace std;

class Node{
    public:
        int data;
        Node* npx;
    
};

Node* XOR(Node* a, Node* b){
    return (Node*)((uintptr_t)(a)^(uintptr_t)(b));
    
}


void insert(Node** head, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->npx = XOR(*head,NULL);
    if(*head!=NULL){
        Node* next = XOR((*head)->npx,NULL);
        (*head)->npx = XOR(new_node,next);
    }
    
    *head = new_node;
}

void printList(Node* head){
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    
    while(curr!=NULL){
        cout<<curr->data<<" ";
        next = XOR(prev,curr->npx);
        prev = curr;
        curr = next;
        
    }
}


int main(){
    Node* head = NULL;
    insert(&head,1);
    insert(&head,4);
    insert(&head,23);
    insert(&head,56);
    insert(&head,12);
    
    printList(head);
    
    return 0;
    
}
