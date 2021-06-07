#include <iostream>
#include <map>
using namespace std;

class Node{
	public:
	char key;
	int value;
	Node* prev;
	Node* next;
	Node(char key, int value){
		key = key;
		value = value;
		prev = NULL;
		next = NULL;
	}
};

class Cache{
	int limit;
	map<char,Node*> tracker;
	Node *head,*tail;
	public:
	Cache(int limit){
		cout<<"d";
		limit = limit;
		head = new Node{NULL,NULL};
		tail = new Node{NULL,NULL};
	}
	
	void add(Node* node){
		Node* prev_node = tail->prev;
		node->next = tail;
		node->prev = prev_node;
		prev_node->next = node;
		tail->prev = node;
	}
	
	void remove(Node* node){
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free(node);
	}
	
	void set(char key,int value){
		if(tracker[key])
			remove(tracker[key]);
		add(new Node(key,value));
		if(tracker.size()>limit)
		{
			tracker.erase(head->next->key);
			remove(head->next);
		}
		
	}
	
	int get(char key){
		if(tracker[key])
			return tracker[key]->value;
		return NULL;
	}
};


int main() {
	int n = 4;
	Cache LRU(n);
	LRU.set('A',1);
	LRU.set('B',13);
	LRU.set('C',67);
	cout<<LRU.get('A');
	LRU.set('D',4);
	LRU.set('E',23);
	cout<<LRU.get('E');
	return 0;
}
