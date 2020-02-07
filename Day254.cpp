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

void printInorder(Node* root){
	if(!root)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

Node* convertToFullBtree(Node* node){
	if(!node || !node->left&&!node->right)
		return node;
	node->left = convertToFullBtree(node->left);
	node->right = convertToFullBtree(node->right);
	if(node->left && node->right)
		return node;
	return node->left?node->left:node->right;
}

int main() {
	Node* root = new Node(0);
	root->left = new Node(1);
	root->right = new Node(2);
	root->left->left = new Node(3);
	root->left->left->right = new Node(5);
	root->right->right = new Node(4);
	root->right->right->right = new Node(7);
	root->right->right->left = new Node(6);
	printInorder(root);
	cout<<endl;
	root = convertToFullBtree(root);
	printInorder(root);
	return 0;
}
