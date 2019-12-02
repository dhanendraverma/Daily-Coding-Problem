/**************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Facebook.
Given a binary tree, return all paths from the root to leaves.
For example, given the tree:
   1
  / \
 2   3
    / \
   4   5
Return [[1, 2], [1, 3, 4], [1, 3, 5]].
***************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Node{
	public:
	char data;
	Node* left;
	Node* right;
	Node(char data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void printPath(vector<char> path){
	for(auto i:path)
		cout<<i<<" ";
	cout<<endl;
}

void findPaths(Node* node, vector<char>& curr_path){
	curr_path.push_back(node->data);
	if(!node->left && !node->right){
		printPath(curr_path);
	}
	else{
		if(node->left)
			findPaths(node->left, curr_path);
		if(node->right)
			findPaths(node->right, curr_path);
	}
	curr_path.pop_back();
}


int main() {
	Node *root = new Node('1');  
    root->left = new Node('2');  
    root->right = new Node('3');  
    root->right->right = new Node('5');  
    root->right->left = new Node('4'); 
    vector<char> path;
	findPaths(root,path);
	return 0;
}
