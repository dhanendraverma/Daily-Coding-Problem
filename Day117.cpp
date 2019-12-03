/**************************************************************************************************************************************
This problem was asked by Facebook.
Given a binary tree, return the level of the tree with minimum sum.
**************************************************************************************************************************************/
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class Node{
	public:
	int  data;
	Node* left;
	Node* right;
	Node(int data){
		this->data = data;
		this->right = NULL;
		this->left = NULL;
	}
};

int findMinSumlevel(Node* node){
	int level = 0;
	int curr_sum = 0,min_sum = INT_MAX,min_level;
	int count = 0;
	queue<Node*> q;
	q.push(node);
	while(!q.empty()){
		count = q.size();
		level++;
		curr_sum = 0;
		while(count--){
			Node* temp = q.front();
			q.pop();
			curr_sum += temp->data;
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		// cout<<curr_sum<<" "<<level<<endl;
		if(curr_sum<min_sum){
			min_sum = curr_sum;
			min_level = level;
		}
	}
	return min_level;
}

int main() {
	Node *root = new Node(100); 
    root->left        = new Node(2); 
    root->right       = new Node(20); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
    root->right->right = new Node(8); 
    root->right->right->left  = new Node(6); 
    root->right->right->right  = new Node(7); 
	cout<<findMinSumlevel(root);
	return 0;
}
