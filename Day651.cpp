/*************************************************************************************************************************************************************
This problem was asked by LinkedIn.
Determine whether a tree is a valid binary search tree.
A binary search tree is a tree with two children, left and right, and satisfies the constraint that the key in the left child must be less than or
equal to the root and the key in the right child must be greater than or equal to the root.
*************************************************************************************************************************************************************/

#include <iostream>
#include <climits>
using namespace std;

class Node{
	public:
	int val;
	Node* left;
	Node* right;
	Node(int val){
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

bool isBSTRec(Node* node, int min, int max){
	if(!node)
		return true;
	if(node->val < min || node->val > max)
		return false;
	return isBSTRec(node->left, min, node->val-1) && isBSTRec(node->right, node->val+1, max);
}

bool isBST(Node* root){
	return isBSTRec(root, INT_MIN, INT_MAX);
}


int main() {
	Node *root = new Node(4); 
	root->left = new Node(2); 
	root->right = new Node(5); 
	root->left->left = new Node(1); 
	root->left->right = new Node(3);
	cout<<isBST(root);
	return 0;
}
