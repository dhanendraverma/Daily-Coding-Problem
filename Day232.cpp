#include <iostream>
#include <map>
using namespace std;

class PrefixMapSum{
	map<string,int> mp;
	public:
	void insert(string key, int value){
		mp[key] = value;
	}
	
	int sum(string prefix){
		int s = 0;
		for(auto i:mp){
			auto res = std::mismatch(prefix.begin(), prefix.end(), i.first.begin());
			if (res.first == prefix.end())
				s += i.second;
		}
		return s;
	}
	
};


int main() {
	PrefixMapSum mapsum;
	mapsum.insert("columnar", 3);
	cout<<mapsum.sum("col")<<endl;
	mapsum.insert("column", 2);
	cout<<mapsum.sum("col")<<endl;
	return 0;
}
