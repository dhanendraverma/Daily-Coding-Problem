/**************************************************************************************************************************************
This problem was asked by Microsoft.
Print the nodes in a binary tree level-wise. For example, the following should print 1, 2, 3, 4, 5.
  1
 / \
2   3
   / \
  4   5
**************************************************************************************************************************************/

#include <iostream>
#include <queue>
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

void levelOrder(Node* head){
	if(!head)
		return;
	queue<Node*> q;
	q.push(head);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}

int main() {
	Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
    levelOrder(root);
	return 0;
}
