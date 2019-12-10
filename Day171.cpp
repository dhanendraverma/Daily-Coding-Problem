/**************************************************************************************************************************************
This problem was asked by Amazon.
You are given a list of data entries that represent entries and exits of groups of people into a building. An entry looks like this:
{"timestamp": 1526579928, count: 3, "type": "enter"}
This means 3 people entered the building. An exit looks like this:
{"timestamp": 1526580382, count: 2, "type": "exit"}
This means that 2 people exited the building. timestamp is in Unix time.
Find the busiest period in the building, that is, the time with the most people in the building. Return it as a pair of (start, end) 
timestamps. You can assume the building always starts off and ends up empty, i.e. with 0 people inside.
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Entry{
	public:
	int timestamp, count;
	string type;
	Entry(int timestamp, int count, string type){
		this->timestamp = timestamp;
		this->count = count;
		this->type = type;
	}
};

bool comp(Entry A,Entry B){
	if(A.timestamp==B.timestamp)
		return A.type=="enter";
	return A.timestamp<B.timestamp;
}

pair<int,int> BusyPeriod(vector<Entry> entries){
	int mx=0;
	int curr=0;
	int start=0,end;
	pair<int,int> ans;
	sort(entries.begin(),entries.end(),comp);
	for(int i=0;i<entries.size();i++){
		curr += entries[i].count*(entries[i].type=="enter"?1:-1);
		// cout<<curr<<" "<<i<<endl;
		if(curr>mx){
			end = i;
			ans = {start,end};
			mx = curr;
		}
		if(curr<=0){
			start = i;
			curr = 0;
		}
	}
	return {entries[ans.first].timestamp,entries[ans.second].timestamp};
}

int main() {
	vector<Entry> entries;
	entries.push_back(Entry(3,4,"enter"));
	entries.push_back(Entry(19,11,"enter"));
	entries.push_back(Entry(22,12,"exit"));
	entries.push_back(Entry(5,1,"enter"));
	entries.push_back(Entry(7,12,"enter"));
	entries.push_back(Entry(3,3,"exit"));
	entries.push_back(Entry(12,1,"enter"));
	entries.push_back(Entry(13,4,"exit"));
	entries.push_back(Entry(11,10,"exit"));
	// sort(entries.begin(),entries.end(),comp);
	// for(auto i:entries)
	// 	cout<<i.timestamp<<" "<<i.count<<" "<<i.type<<endl;
	pair<int,int> period = BusyPeriod(entries);
	cout<<period.first<<" "<<period.second;
	return 0;
}
