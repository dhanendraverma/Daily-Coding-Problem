#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int inversionCont(vector<int> arr){
  int inv_cnt = 0;
  multiset<int> s;
  for(auto num:arr){
    auto it = s.upper_bound(num);
    if(it != s.end())
      inv_cnt += distance(it, s.end());
    s.insert(num); 
  }
  return inv_cnt;
}


int main() {
  vector<int> arr = {2, 4, 1, 3, 5};
  cout<<inversionCont(arr)<<endl;
}
