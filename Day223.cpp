/***************************************************************************************************************************************
This problem was asked by Palantir.
Typically, an implementation of in-order traversal of a binary tree has O(h) space complexity, where h is the height of the tree. Write
a program to compute the in-order traversal of a binary tree using O(1) space.
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *left, *right;
	Node(int data){
		this->data = data;
		this->left = this->right = NULL;
	}
};

void inorder(Node* root){
	Node *curr,*pre;
	if(!root)
		return;
	curr = root;
	while(curr){
		if(curr->left==NULL){
			cout<<curr->data<<" ";
			curr = curr->right;
		}
		else{
			pre = curr->left;
			while(pre->right!=NULL && pre->right!=curr)
				pre = pre->right;
			
			if(pre->right==NULL){
				pre->right = curr;
				curr = curr->left;
			}
			else{
				pre->right = NULL;
				cout<<curr->data<<" ";
				curr = curr->right;
			}
		}
	}
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	inorder(root);
	return 0;
}
