/**************************************************************************************************************************************
This problem was asked by LinkedIn.
Determine whether a tree is a valid binary search tree.
A binary search tree is a tree with two children, left and right, and satisfies the constraint that the key in the left child must be 
less than or equal to the root and the key in the right child must be greater than or equal to the root.
***************************************************************************************************************************************/
#include <iostream>
#include <climits>
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

bool check(Node* node,int mn, int mx){
	if(!node)
		return true;
	if(node->data<mn || node->data>mx)
		return false;
	return check(node->left,mn,node->data-1) && check(node->right,node->data+1,mx);
}

bool is_valid(Node* root){
	return check(root,INT_MIN,INT_MAX);
}


int main() {
	Node *root = new Node(4); 
	root->left = new Node(2); 
	root->right = new Node(5); 
	root->left->left = new Node(1); 
	root->left->right = new Node(3);
	cout<<is_valid(root);
	return 0;
}
