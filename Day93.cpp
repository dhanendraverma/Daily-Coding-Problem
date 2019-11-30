/**************************************************************************************************************************************
This problem was asked by Apple.
Given a tree, find the largest tree/subtree that is a BST.
Given a tree, return the size of the largest tree/subtree that is a BST.
***************************************************************************************************************************************/

/**A lot of portals and tutorials have wrong solution for this question so if you learn from there make sure it's right by doing a DRY 
run using different edge cases.**/
#include <iostream>
#include <climits>
using namespace std;
//a strcuture to store and pass information in recursion calls
class Info{
	public:
	int mn;
	int mx;
	int size;
	bool isBST;
	Info(){
		this->mn = INT_MAX;
		this->mx = INT_MIN;
		this->size = 0;
		this->isBST = true;
	}
};

//node structure of the tree
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

//a recursive function to find the largest BST
Info findLargestBST(Node* node, int& ans){
	if(node==NULL){
    return Info(); //if no node just return a BST info with the size of 0(constructor of the class initializes all the variables)
	}
	
	Info l = findLargestBST(node->left, ans); //solution is building up in bottom up manner to consider both childs before the node
	Info r = findLargestBST(node->right, ans);
	Info ret; //a inforation to be returned
  //if left & right subtree root under the current node are BST and current node's value is such that by joining it with the left and
  //right substree preserves the BST property then the subtree under current node would be BST for sure
	if(l.isBST && r.isBST && l.mx<node->data && r.mn>node->data){
		ret.mn = min(l.mn,node->data);
		ret.mx = max(r.mx,node->data);
		ret.size = l.size+r.size+1;
		ans = max(ans,ret.size); //if current built tree has size more than the encoutered before then update the answer.
		return ret;
	}
  //if current node doesn't makes BST then reset to check if tree above this is BST
	ret.isBST = false;
	ret.size = max(l.size,r.size);
	return ret;
}


int main() {
	Node *root = new Node(60); 
    root->left = new Node(65); 
    root->right = new Node(70); 
    root->left->left = new Node(50);
	int ans =0;
	findLargestBST(root,ans);
	cout<<ans;
	return 0;
}
