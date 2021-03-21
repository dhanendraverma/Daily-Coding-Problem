/***********************************************************************************************************************************************************
This problem was asked by Amazon.
A tree is symmetric if its data and shape remain unchanged when it is reflected about the root node. The following tree is 
an example:
        4
      / | \
    3   5   3
  /           \
9              9
Given a k-ary tree, determine whether it is symmetric.
*************************************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define K 3

class Node{
	public:
		int data;
		vector<Node*> children;
		Node(int data){
			this->data = data;
			this->children = vector<Node*>(K,NULL);
		}
};

bool isSymmetricTree(Node* node1, Node* node2){
	if(!node1 && !node2)
		return true;
	if( !node1 || !node2 || (node1->data != node2->data))
		return false;
	for(int i=0; i<(K+1)/2; i++){
		if(!isSymmetricTree(node1->children[i], node2->children[K-i-1]))
			return false;
	}
	return true;
}


int main() {
	Node* root = new Node(4);
	root->children[0] = new Node(3);
	root->children[1] = new Node(5);
	root->children[2] = new Node(3);
	root->children[0]->children[0] = new Node(9);
	root->children[2]->children[2] = new Node(9);
	cout<<isSymmetricTree(root,root);
	return 0;
}
