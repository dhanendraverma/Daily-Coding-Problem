/*****************************************************************************************************************************
This problem was asked by Amazon.
Given an integer N, construct all possible binary search trees with N nodes.
******************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int val;
        Node *left,*right;
        Node(int val){
            this->val = val;
            this->left = this->right = NULL;
        }
};

vector<Node*> constrcutBST(int start,int end){
    vector<Node*> nodeList;
    if(start>end){
        nodeList.push_back(NULL);
        return nodeList;
    }
    for(int i=start;i<=end;i++){
        vector<Node*> leftBST = constrcutBST(start,i-1);
        vector<Node*> rightBST = constrcutBST(i+1,end);
        for(int j=0;j<leftBST.size();j++){
            Node* left = leftBST[j];
            for(int k=0;k<rightBST.size();k++){
                Node* right = rightBST[k];
                Node* currRoot = new Node(i);
                currRoot->left = left;
                currRoot->right = right;
                nodeList.push_back(currRoot);
            }
        }
    }
    return nodeList;
}

void preOrder(Node* root){
    if(!root)
        return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int N = 3;
    vector<Node*> roots = constrcutBST(1,N);
    for(auto root:roots){
        preOrder(root);
        cout<<endl;
    }
	return 0;
}
