/*****************************************************************************************************************************
A cryptarithmetic puzzle is a mathematical game where the digits of some numbers are represented by letters. 
Each letter represents a unique digit.
For example, a puzzle of the form:
  SEND
+ MORE
--------
 MONEY
may have the solution:
{'S': 9, 'E': 5, 'N': 6, 'D': 7, 'M': 1, 'O', 0, 'R': 8, 'Y': 2}
Given a three-word puzzle like the one above, create an algorithm that finds a solution.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool dfs(string w1, string w2, string w3, int i1, int i2, int i3, int carry, vector<bool>& used, vector<int>& res) {
        if(i3 < 0)
        	return carry==0;
        if(i1 >= 0 && res[w1[i1] - 'A'] < 0){
        	for(int d = 0; d <= 9; d++) {
        		if(!used[d]){
        			res[w1[i1] - 'A'] = d;
        			used[d] = true;
        			if(dfs(w1, w2, w3, i1, i2, i3, carry, used,res)) 
        				return true;
	                res[w1[i1] - 'A'] = -1;
	                used[d] = false;
                }
            }
            return false;
        }
        
        if(i2 >= 0 && res[w2[i2] - 'A'] < 0) {
        	for(int d = 0; d <= 9; d++) {
        		if(!used[d]) {
        			res[w2[i2] - 'A'] = d;
	                used[d] = true;
	                if(dfs(w1, w2, w3, i1, i2, i3, carry, used,res))
	                    return true;
	                    res[w2[i2] - 'A'] = -1;
	                    used[d] = false;
                }
            }
            return false;
        }
        
        int sum = carry;
        sum += i1 >= 0 ? res[w1[i1] - 'A'] : 0;
        sum += i2 >= 0 ? res[w2[i2] - 'A'] : 0;
        if(res[w3[i3] - 'A'] >= 0 && sum % 10 == res[w3[i3] - 'A'])
            return dfs(w1, w2, w3, i1 - 1, i2 - 1, i3 - 1, sum / 10, used,res);
        else if(res[w3[i3] - 'A'] >= 0 || used[sum % 10])
            return false;
        used[sum % 10] = true;
        res[w3[i3] - 'A'] = sum % 10;
        if(dfs(w1, w2, w3, i1 - 1, i2 - 1, i3 - 1, sum / 10, used,res)) {
            return true;
        }
        used[sum % 10] = false;
        res[w3[i3] - 'A'] = -1;
        return false;
}

vector<int> cryptarithmeticPuzzle(string word1, string word2, string word3) {
		vector<int> res(26,-1);
        vector<bool> used(10,false);
        if(word3.length() > word1.length() && word3.length() > word2.length()) {
            res[word3[0] - 'A'] = 1;
            used[1] = true;
        }
        dfs(word1, word2, word3, word1.length() - 1, word2.length() - 1, word3.length() - 1, 0, used,res);
        return res;
    }

int main() {
	vector<int> res = cryptarithmeticPuzzle("SEND", "MORE", "MONEY");
	for(int i=0;i<res.size();i++)
		cout<<char(i+'A')<<" "<<res[i]<<endl;
	return 0;
}
