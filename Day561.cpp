/******************************************************************************************************************************************************
This problem was asked by Etsy.
Given a sorted array, convert it into a height-balanced binary search tree.
******************************************************************************************************************************************************/

#include <iostream>
#include <vector>
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

void inorder(Node* node){
    if(!node)
        return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

Node* sortedArrayToBSTRec(vector<int>& arr, int left, int right){
	if(left > right)
		return NULL;
	int mid = left + (right-left)/2;
	Node* root = new Node(arr[mid]);
	root->left = sortedArrayToBSTRec(arr, left, mid-1);
	root->right = sortedArrayToBSTRec(arr, mid+1, right);
	return root;
}

Node* sortedArrayToBST(vector<int> arr){
	return sortedArrayToBSTRec(arr, 0, arr.size()-1);
}

int main() {
	vector<int> sorted_arr = {1,2,3,4,5,6,7,8};
    Node* root = sortedArrayToBST(sorted_arr);
    inorder(root);
	return 0;
}
