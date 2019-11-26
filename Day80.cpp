/**************************************************************************************************************************************
This problem was asked by Google.
Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.
    a
   / \
  b   c
 /
d
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(char data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

class BinaryTree{
	public:
	Node* root;
	int max_level;
	char deepValue;
	void inorder(Node* root,int level){
		if(root){
			inorder(root->left,level+1);
			if(level>max_level){
				deepValue = root->data;
				max_level = level; 
			}
			inorder(root->right,level+1);
		}
	}
	
	void getDeepestNode(){
		max_level = 0;
		inorder(root,0);
		cout<<"Deepest node value is "<<deepValue<<endl;
	}
};

int main() {
	BinaryTree btree;
	btree.root = new Node('A');
	btree.root->left = new Node('B'); 
	btree.root->right = new Node('C'); 
	btree.root->left->left = new Node('D'); 
	btree.root->right->left = new Node('E'); 
	btree.root->right->right = new Node('F'); 
	btree.root->right->left->right = new Node('G'); 
	btree.root->right->right->right = new Node('H'); 
	btree.root->right->left->right->left = new Node('I'); 
	btree.getDeepestNode();
	return 0;
}
