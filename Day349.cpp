/******************************************************************************************************************************
This problem was asked by Grammarly.
Soundex is an algorithm used to categorize phonetically, such that two names that sound alike but are spelled differently have
the same representation.
Soundex maps every name to a string consisting of one letter and three numbers, like M460.
One version of the algorithm is as follows:
Remove consecutive consonants with the same sound (for example, change ck -> c).
Keep the first letter. The remaining steps only apply to the rest of the string.
Remove all vowels, including y, w, and h.
Replace all consonants with the following digits:
b, f, p, v → 1
c, g, j, k, q, s, x, z → 2
d, t → 3
l → 4
m, n → 5
r → 6
If you don't have three numbers yet, append zeros until you do. Keep the first three numbers.
Using this scheme, Jackson and Jaxen both map to J250.
Implement Soundex.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<set<char>> sounAlike = {{'c','k','s'},{'z','j','x'}};
set<char> voweAlike = {'a','e','i','o','u','y','w','h'};
map<char,set<char>> digitMap;

string soundex(string word){
    string sx = "";
    sx += word[0];
    bool flag = false;
    int n = word.length();
    for(int i=1;i<n;i++){
        if(i<n-1){
            for(auto sa:sounAlike){
                if(sa.find(word[i]) != sa.end() && sa.find(word[i+1]) != sa.end()){
                    // sx += word[i];
                    // i++;
                    flag = true;
                    break;
                }
            }
        }
        if(!flag && voweAlike.find(word[i]) == voweAlike.end()){
            for(auto dm:digitMap){
                if(dm.second.find(word[i]) != dm.second.end()){
                    sx += dm.first;
                    break;
                }
            }
        }
        flag = false;
    }
    while(sx.length()<4)
        sx += "0";
    return sx;
}

int main() {
    string word = "jackson";
    digitMap['1'] = {'b', 'f', 'p', 'v'};
    digitMap['2'] = {'c', 'g', 'j', 'k', 'q', 's', 'x', 'z'};
    digitMap['3'] = {'d', 't'};
    digitMap['4'] = {'l'};
    digitMap['5'] = {'m', 'n'};
    digitMap['6'] = {'r'};
    cout<<soundex(word)<<endl;
	return 0;
}
