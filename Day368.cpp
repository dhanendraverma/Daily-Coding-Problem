/******************************************************************************************************************************
This problem was asked by Google.
Implement a key value store, where keys and values are integers, with the following methods:
update(key, vl): updates the value at key to val, or sets it if doesn't exist
get(key): returns the value with key, or None if no such value exists
max_key(val): returns the largest key with value val, or None if no key with that value exists
For example, if we ran the following calls:
kv.update(1, 1)
kv.update(2, 1)
And then called kv.max_key(1), it should return 2, since it's the largest key with value 1.
******************************************************************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class KVstore{
    map<int,int> main_mp,aux_mp;
    public:
    KVstore(){}
    
    void update(int key,int val){
        main_mp[key] = val;
        if(aux_mp.find(val)==aux_mp.end() || aux_mp[val]<key)
            aux_mp[val] = key;
    }
    
    int get(int key){
        if(main_mp.find(key)!=main_mp.end())
            return main_mp[key];
        return -1;
    }
    
    int max_key(int val){
        if(aux_mp.find(val)!=aux_mp.end())
            return aux_mp[val];
        return -1;
    }
};

int main() {
    KVstore Map;
    Map.update(2,3);
    Map.update(5,7);
    Map.update(1,8);
    Map.update(7,3);
    cout<<Map.get(2)<<endl;
    cout<<Map.max_key(3)<<endl;
	return 0;
}
