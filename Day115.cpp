/***************************************************************************************************************************************
This problem was asked by Google.
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s.
A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree
of itself.
***************************************************************************************************************************************/
#include <iostream>
using namespace std;

class Node{
	public:
	char data;
	Node* left;
	Node* right;
	Node(char data){
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

void findInorder(Node* node, string& inorder){
	if(!node)
		return;
	findInorder(node->left,inorder);
	inorder += node->data;
	findInorder(node->right,inorder);
}

void findPreorder(Node* node, string& preorder){
	if(!node)
		return;
	preorder += "#"+node->data;
	findPreorder(node->left,preorder);
	findPreorder(node->right,preorder);
}

bool isSubtree(Node* T, Node* S){
	string Tinorder = "",Tpreorder = "";
	string Sinorder = "",Spreorder = "";
	findInorder(T,Tinorder);
	findInorder(T,Sinorder);
	findPreorder(S,Tpreorder);
	findPreorder(S,Spreorder);
	return ((Tinorder.find(Sinorder)!=string::npos && Tpreorder.find(Spreorder)!=string::npos));
}

int main() {
	// Node* T = new Node('a'); 
 //   T->left = new Node('b'); 
 //   T->right = new Node('d'); 
 //   T->left->left = new Node('c'); 
 //   T->right->right = new Node('e'); 
  
 //   Node* S = new Node('a'); 
 //   S->left = new Node('b'); 
 //   S->left->left = new Node('c'); 
 //   S->right = new Node('d');
 //   cout<<isSubtree(T,S);
    
    Node *T = new Node('2');  
    T->right         = new Node('3');  
    T->right->right = new Node('3');  
    T->left         = new Node('1');  
    T->left->left     = new Node('4');  
    T->left->left->right = new Node('5');  
    T->left->right     = new Node('6');
    
    Node *S = new Node('1');  
    S->right     = new Node('6');  
    S->left     = new Node('4');  
    S->left->right = new Node('5');
      cout<<isSubtree(T,S);
	return 0;
}
