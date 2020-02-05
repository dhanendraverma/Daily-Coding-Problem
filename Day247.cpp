/****************************************************************************************************************************
This problem was asked by PayPal.
Given a binary tree, determine whether or not it is height-balanced. A height-balanced binary tree can be defined as one 
in which the heights of the two subtrees of any node never differ by more than one.
/****************************************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *left,*right;
	Node(int data){
		this->data = data;
		this->left = this->right=NULL;
	}
};

int isHbalanced(Node* node){
	if(!node)
		return 0;
	int l = isHbalanced(node->left);
	int r = isHbalanced(node->right);
	if(l==-1 || r==-1 || abs(l-r)>1)
            return -1;
        return 1+max(l,r);
}

int main() {
	Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->left->left->left = new Node(7); 
    cout<<(isHbalanced(root)!=-1);
	return 0;
}
