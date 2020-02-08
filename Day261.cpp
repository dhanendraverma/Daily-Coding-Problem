#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node{
	public:
	char data;
	unsigned int freq;
	Node *left,*right;
	Node(char data, int freq){
		this->data = data;
		this->left = this->right = NULL;
		this->freq = freq;
	}
};

struct compare { 
	bool operator()(Node* l, Node* r) { 
        return (l->freq > r->freq); 
    } 
}; 

Node* buildHumffmanTree(map<char,int> char_freq){
	priority_queue<Node*,vector<Node*>,compare> pq;
	for(auto p:char_freq)
		pq.push(new Node(p.first,p.second));
	while(pq.size()!=1){
		Node* left = pq.top();
		pq.pop();
		Node* right = pq.top();
		pq.pop();
		Node* newNode = new Node('*',left->freq+right->freq);
		newNode->left = left;
		newNode->right = right;
		pq.push(newNode);
	}
	return pq.top();
}

void printCoding(Node* root,string curr_code){
	if(!root)
		return;
	if(root->data!='*')
		cout<<root->data<<":"<<curr_code<<endl;
	printCoding(root->left,curr_code+"0");
	printCoding(root->right,curr_code+"1");
}

int main() {
	map<char,int> char_freq = {{'b',9},{'c',12},{'d',13},{'e',16},{'f',45},{'a',5}};
	Node* root = buildHumffmanTree(char_freq);
	printCoding(root,"");
	return 0;
}
