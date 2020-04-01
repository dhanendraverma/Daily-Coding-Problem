/*****************************************************************************************************************************
This problem was asked by Quora.
You are given a list of (website, user) pairs that represent users visiting websites. Come up with a program that 
identifies the top k pairs of websites with the greatest similarity.
For example, suppose k = 1, and the list of tuples is:
[('a', 1), ('a', 3), ('a', 5),
 ('b', 2), ('b', 6),
 ('c', 1), ('c', 2), ('c', 3), ('c', 4), ('c', 5)
 ('d', 4), ('d', 5), ('d', 6), ('d', 7),
 ('e', 1), ('e', 3), ('e': 5), ('e', 6)]
Then a reasonable similarity metric would most likely conclude that a and e are the most similar, so your program should 
return [('a', 'e')].
*****************************************************************************************************************************/

#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


class comp 
{ 
public: 
    int operator() (const pair<pair<char,char>,double>& a, pair<pair<char,char>,double>& b) 
    { 
        return a.second>b.second;
    } 
}; 



double JaccardIndex(set<int> s1, set<int> s2){
    double size_s1 = s1.size();
    double size_s2 = s2.size();
    set<int> intersect; 
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),inserter(intersect, intersect.begin())); 
	double size_in = intersect.size();
	double jaccard_in = size_in/(size_s1 + size_s2 - size_in);
	return jaccard_in;
}

vector<pair<char,char>> findKSimilarSites(vector<pair<char,int>>& visits,int k){
    map<char,set<int>> userMap;
    for(auto pair:visits)
        userMap[pair.first].insert(pair.second);
    priority_queue<pair<pair<char,char>,double>,vector<pair<pair<char,char>,double>>,comp> pq;
    for(auto itr=userMap.begin();itr!=userMap.end();itr++){
        for(auto itr2 = next(itr);itr2!=userMap.end();itr2++){
            double ji = JaccardIndex(itr->second,itr2->second);
            // cout<<itr->first<<" "<<itr2->first<<" "<<ji<<endl;
            if(pq.size()==k){
                if(pq.top().second<ji){
                    pq.pop();
                    pq.push({{itr->first,itr2->first},ji});
                }
            }
            else
                pq.push({{itr->first,itr2->first},ji});
            
        }
    }
    vector<pair<char,char>> ans;
    while(!pq.empty()){
        // cout<<pq.top().second<<endl;
        ans.push_back(pq.top().first);
        pq.pop();
    }
    return ans;
}

int main() {
    vector<pair<char,int>> visits = {{'a', 1}, {'a', 3}, {'a', 5},{'b', 2}, {'b', 6},{'c', 1}, 
    {'c', 2}, {'c', 3}, {'c', 4}, {'c', 5},{'d', 4}, {'d', 5}, {'d', 6}, {'d', 7},
    {'e', 1}, {'e', 3}, {'e', 5}, {'e', 6}};
    int k=1;
    vector<pair<char,char>> ans = findKSimilarSites(visits,k);
    for(auto p:ans)
        cout<<p.first<<" "<<p.second<<endl;
        
	return 0;
}
