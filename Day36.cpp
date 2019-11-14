/**************************************************************************************************************************************
This problem was asked by Dropbox.
Given the root to a binary search tree, find the second largest node in the tree.
**************************************************************************************************************************************/


#include <bits/stdc++.h> 
using namespace std;

struct Node{
	public:
	int key;
	Node *left, *right;
};

Node* newnode(int key){
	Node* newnode = new Node;
	newnode->key = key;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

Node* insert(Node* node, int key){
	if(!node)
		return newnode(key);
	if(key<node->key)
		node->left = insert(node->left,key);
	else
		node->right = insert(node->right,key);
	return node;
}

void secondLargest(Node *root){
	static int c=0;
	if(root==NULL || c>=2)
		return;
	secondLargest(root->right);
	c++;
	if(c==2)
	{
		cout<<"Second largest element is: "<<root->key;
		return;
	}
	secondLargest(root->left);	
}

int main() {
Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    secondLargest(root); //Second largest element is: 70
    return 0; 
}
