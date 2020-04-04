/******************************************************************************************************************************
This problem was asked by Etsy.
Given a sorted array, convert it into a height-balanced binary search tree.
******************************************************************************************************************************/

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

Node* sortedArrToBST(vector<int>& arr, int l, int r){
    if(l>r)
        return NULL;
    int mid = (l+r)/2;
    Node* curr_root = new Node(arr[mid]);
    curr_root->left = sortedArrToBST(arr,l,mid-1);
    curr_root->right = sortedArrToBST(arr,mid+1,r);
    return curr_root;
}

int main() {
    vector<int> sorted_arr = {1,2,3,4,5,6,7,8};
    Node* root = sortedArrToBST(sorted_arr,0,sorted_arr.size()-1);
    inorder(root);
	return 0;
}
