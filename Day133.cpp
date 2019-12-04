/**************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Amazon.
Given a node in a binary search tree, return the next bigger element, also known as the inorder successor.
For example, the inorder successor of 22 is 30.
   10
  /  \
 5    30
     /  \
   22    35
You can assume each node has a parent pointer.
**************************************************************************************************************************************/

#include <iostream> 
using namespace std;

class Node {
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

Node* insert(Node* node, int data) { 
	if (!node) 
		return new Node(data); 
	if(data <node->data) 	 
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);  
	return node; 
}

Node* minValue(Node* node) { 
	Node* current = node; 
	while(current->left)
		current = current->left; 
	return current; 
} 

Node* inorderSucc(Node* root, Node* node) { 
	if( node->right) 
        return minValue(node->right); 
    Node* succ = NULL; 
    while(root){ 
    	if (node->data<root->data) 
        { 
            succ = root; 
            root = root->left; 
        } 
        else if (node->data > root->data) 
            root = root->right; 
        else
           break; 
    } 
    return succ; 
} 

int main() { 
	Node* root = NULL, *temp, *succ, *min; 
	root = insert(root, 20); 
	root = insert(root, 8); 
	root = insert(root, 22); 
	root = insert(root, 4); 
	root = insert(root, 12); 
	root = insert(root, 10); 
	root = insert(root, 14);	 
	temp = root->left->right->right; 
	succ = inorderSucc(root, temp); 
	cout<<succ->data;
	return 0; 
} 
