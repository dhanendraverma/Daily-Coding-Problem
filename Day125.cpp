/**************************************************************************************************************************************
This problem was asked by Google.
Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.
For example, given the following tree and K of 20
    10
   /   \
 5      15
       /  \
     11    15
Return the nodes 5 and 15.
**************************************************************************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

class BST{
	public:
	Node* root;
	BST(){
		root = NULL;
	}
	
	void push(int data){
		root =  insertUtil(root,data);
	}
	
	Node* insertUtil(Node* root, int data){
		if(!root)
			return new Node(data);
		if(data < root->data)
			root->left = insertUtil(root->left, data);
		if(data > root->data)
			root->right = insertUtil(root->right, data);
		return root;	
	}
	
	bool isPairSum(int k){
		stack<Node*> s1;
		stack<Node*> s2;
		Node *curr1 = root, *curr2 = root;
		int val1,val2;
		bool done1 = false, done2=false;
		while(true){
			while(!done1){
				if(curr1){
					s1.push(curr1);
					curr1 = curr1->left;
				}
				else{
					if(s1.empty())
						done1 = true;
					else{
						curr1 = s1.top();
						s1.pop();
						val1 = curr1->data;
						curr1 = curr1->right;
						done1 = true;
					}
				}
			}
			while(!done2){
				if(curr2){
					s2.push(curr2);
					curr2 = curr2->right;
				}
				else{
					if(s2.empty())
						done2 = true;
					else{
						curr2 = s2.top();
						s2.pop();
						val2 = curr2->data;
						curr2 = curr2->left;
						done2 = true;
					}
				}
			}
			if(val1!=val2 && val1+val2==k){
				cout<<val1<<" "<<val2<<endl;
				return true;
			}
			else if(val1+val2<k)
				done1 = false;
			else if(val1+val2>k)
				done2 = false;
			if(val1>=val2)
				return false;
		}
	}
}; 

int main() {
	BST bst;
	bst.push(15);
	bst.push(20);
	bst.push(10);
	bst.push(8);
	bst.push(16);
	bst.push(12);
	bst.push(25);
	int k = 33;
	cout<<bst.isPairSum(k);
	return 0;
}
