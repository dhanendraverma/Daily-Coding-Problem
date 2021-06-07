/***********************************************************************************************************************************************************
This problem was asked by Google.
Implement an LRU (Least Recently Used) cache. It should be able to be initialized with a cache size n, and contain the following methods:
set(key, value): sets key to value. If there are already n items in the cache and we are adding a new item, then it should also remove the least recently 
used item.
get(key): gets the value at key. If no such key exists, return null.
Each operation should run in O(1) time.
************************************************************************************************************************************************************/

#include <iostream>
#include <list>
#include <map>
using namespace std;

class LRU{
	int size;
	list<string> dq;
	map<string, pair<list<string>::iterator, string>> mp;
	public:
		LRU(int n){
			this->size = n;
		}
		
		void set(string key ,string value){
			if(mp.find(key) == mp.end()){
				if(dq.size() == size){
					string last = dq.back();
					dq.pop_back();
					mp.erase(last);
				}
			}
			else
				dq.erase(mp[key].first);
			dq.push_front(key);
			mp[key] = {dq.begin(), value};
		}
		
		string get(string key){
			if(mp.find(key) == mp.end())
				return "";
			return mp[key].second;
		}
};

int main() {
	LRU lru(3);
	lru.set("aa","1");
	lru.set("bb","2");
	lru.set("cc","3");
	cout<<lru.get("cc")<<endl;
	lru.set("dd","4");
	cout<<lru.get("aa")<<endl;
	return 0;
}
