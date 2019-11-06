This problem was asked by Microsoft.
Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more 
than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.
For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", 
you should return ['the', 'quick', 'brown', 'fox'].
Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond",
return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

               #include <bits/stdc++.h>
using namespace std;

string breakWordDP(string word, set<string> dict){
	int T[word.length()][word.length()];
	for(int i=0; i < word.length(); i++){
		for(int j=0; j < word.length() ; j++){
			T[i][j] = -1; //-1 indicates string between i to j cannot be split
		}
	}

//fill up the matrix in bottom up manner
	for(int l = 1; l <= word.length(); l++){
    	for(int i=0; i < word.length() -l + 1 ; i++){
        	int j = i + l-1;
        	string str = word.substr(i,l);
        	//if string between i to j is in dictionary T[i][j] is true
        	if(dict.find(str)!=dict.end()){
	            T[i][j] = i;
	            continue;
        		
        	}
        for(int k=i+1; k <= j; k++){
            if(T[i][k-1] != -1 && T[k][j] != -1){
                T[i][j] = k;
                break;
            }
        }
    }
}
if(T[0][word.length()-1] == -1){
    return NULL;
}

//create space separate word from string is possible
string buffer = "";
int i = 0; int j = word.length() -1;
while(i < j){
    int k = T[i][j];
    if(i == k){
        buffer += word.substr(i, j+1-i);
        break;
    }
    buffer += word.substr(i,k-i) + " ";
    i = k;
}

return buffer;
}


int main() {
	// your code goes here
	int n;
	cin>>n;
	set<string> dict;
	string word,input_str;
	for(int i=0;i<n;i++){
		cin>>word;
		dict.insert(word);
	}
	cin>>input_str;
	cout<<breakWordDP(input_str,dict);
	return 0;
}
