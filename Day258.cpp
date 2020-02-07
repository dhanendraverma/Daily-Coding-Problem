#include <iostream>
#include <stack>
using namespace std;

class Node{
	public:
	int data;
	Node *left,*right;
	Node(int data){
		this->data = data;
		this->left = this->right = NULL;
	}
};

void zigZagLevelOrder(Node* root){
	stack<Node*> s1,s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			Node* temp = s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->right)
				s2.push(temp->left);
			if(temp->left)
				s2.push(temp->right);
		}
		cout<<endl;
		while(!s2.empty()){
			Node* temp = s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				s1.push(temp->right);
			if(temp->right)
				s1.push(temp->left);
		}
		cout<<endl;
	}
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(5);
	root->left->left = new Node(4);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	zigZagLevelOrder(root);
	return 0;
}
