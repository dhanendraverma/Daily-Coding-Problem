/*****************************************************************************************************************************
This problem was asked by Dropbox.
Create a data structure that performs all the following operations in O(1) time:
plus: Add a key with value 1. If the key already exists, increment its value by one.
minus: Decrement the value of a key. If the key's value is currently 1, remove it.
get_max: Return a key with the highest value.
get_min: Return a key with the lowest value.
Reference: https://tech.io/playgrounds/52828/common-coding-interview-questions-o1-data-structure
*****************************************************************************************************************************/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
using namespace std;

class AllOne {
private:
    struct Value {
        unsigned int value;
        list<pair<unsigned int, unordered_set<string>>>::iterator bucket;
    };
    list<pair<unsigned int, unordered_set<string>>> _buckets;
    unordered_map<unsigned int, unsigned int> _counts;
    unordered_map<string, Value> _values;
public:
    AllOne() {
        
    }
    
    void create_element(const string& key) {
        if (_buckets.size() == 0 || _buckets.front().first != 1) {
            _buckets.push_front(make_pair(1, unordered_set<string>{key}));
        } else {
            _buckets.front().second.insert(key);
        }
        
        auto it = _buckets.begin();
        
        _values.insert(make_pair(key, Value{1, it}));
        _counts[1]++;
    }
    
    void delete_element(unordered_map<string, Value>::iterator it) {
        _counts[1]--;
        
        if (_counts[1] == 0) {
            _buckets.pop_front();
        } else {
            _buckets.front().second.erase(it->first);
        }
        _values.erase(it);
    }
    
    void adjust_element(unordered_map<string, Value>::iterator it, int adj) {
        unsigned current = it->second.value;
        unsigned next = current+adj;
        _counts[current]--;
        _counts[next]++;
        it->second.bucket->second.erase(it->first);
        if (_counts[current] == 0 && _counts[next] == 1) {
            it->second.bucket->first += adj;
        }
        if (_counts[current] > 0 && _counts[next] > 1) {
            advance(it->second.bucket, adj);
        }
        if (_counts[current] > 0 && _counts[next] == 1) {
            if (adj > 0) 
                advance(it->second.bucket, adj);
            it->second.bucket = _buckets.insert(it->second.bucket, make_pair(next, unordered_set<string>{it->first}));
        }
        if (_counts[current] == 0 && _counts[next] > 1) {
            it->second.bucket = _buckets.erase(it->second.bucket);
            if (adj < 0)
                advance(it->second.bucket, adj);
        }
        it->second.bucket->second.insert(it->first);
        it->second.value += adj;
    }
                       
    void plus(string key) {
        auto it = _values.find(key);
        if (it == _values.end()) {
            create_element(key);
        } else {
            adjust_element(it, 1);
        }
    }
    
    void minus(string key) {
        auto it = _values.find(key);
        if (it == _values.end())
            return;
        if (it->second.value == 1) {
            delete_element(it);
        } else {
            adjust_element(it, -1);
        }
    }
    
    string get_max() {
        if (_buckets.empty())
            return string("");
        return *_buckets.back().second.begin();
    }
    
    string get_min() {
        if (_buckets.empty())
            return string("");
        return *_buckets.front().second.begin();
    }
};

int main() {
    AllOne ao;
    ao.plus("a");
    ao.plus("b");
    ao.plus("a");
    ao.plus("c");
    cout<<ao.get_min()<<endl;
    cout<<ao.get_max()<<endl;
    ao.minus("c");
    cout<<ao.get_min()<<endl;
	return 0;
}
