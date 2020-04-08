/*****************************************************************************************************************************
This problem was asked by Walmart Labs.
There are M people sitting in a row of N seats, where M < N. Your task is to redistribute people such that there are no gaps
between any of them, while keeping overall movement to a minimum.
For example, suppose you are faced with an input of [0, 1, 1, 0, 1, 0, 0, 0, 1], where 0 represents an empty seat and 1 
represents a person. In this case, one solution would be to place the person on the right in the fourth seat. We can consider
the cost of a solution to be the sum of the absolute distance each person must move, so that the cost here would be five.
Given an input such as the one above, return the lowest possible cost of moving people to remove all gaps.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int lowestCost(vector<int> s){
    int cnt=0;
    for(auto seat:s)
        cnt += seat==1?1:0;
    cnt = (cnt+1)/2;
    int median;
    for(int i=0;i<s.size();i++){
        cnt--;
        if(cnt==0){
            median = i;
            break;
        }
    }
    int cost = 0, j = 0, k = median;
	while (j < k){
		if (s[j] == 0)
			j++;
		else if (s[k] == 1)
			k--;
		else{
			swap(s[k],s[j]);
			cost += k-j;
			j++;
			k--;
		}
	}
	j = s.size() - 1;
	k = median;
	while (j > k){
		if(s[j] == 0)
			j--;
		else if(s[k] == 1)
			k++;
		else {
			swap(s[k],s[j]);
			cost += j-k;
			j--;
			k++;
		}
	}
		return cost;
}

int main() {
    vector<int> seats = {0, 1, 1, 0, 1, 0, 0, 0, 1};
    cout<<lowestCost(seats)<<endl;
	return 0;
}
