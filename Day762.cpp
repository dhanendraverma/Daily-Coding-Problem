/***************************************************************************************************************************************
Find an efficient algorithm to find the smallest distance (measured in number of words) between any two given words in a string.
For example, given words "hello", and "world" and a text content of "dog cat hello cat dog dog hello cat world", return 1 because 
there's only one word "cat" in between the two words.
***************************************************************************************************************************************/

#include <iostream>
#include <climits>
#include <sstream>

using namespace std;

int smallestDist(string str, string word1, string word2){
  int curr_dist = 0, min_dist = INT_MAX;
  stringstream ss(str);
  string curr_word, last_word = "";
  while(ss>>curr_word){
    if((curr_word == word1 && last_word == word2) || (curr_word == word2 && last_word == word1)){
      min_dist = min(min_dist, curr_dist);
      last_word = curr_word;
      curr_dist = 0;
    }
    else if(curr_word==word1 || curr_word==word2){
      last_word = curr_word;
      curr_dist = 0;
    }
    else
      curr_dist++;
  }
  return min_dist;
}

int main() {
  string str = "dog cat hello cat dog dog hello aadn cat world namo world hello";
	string word1 = "hello";
	string word2 = "world";
	cout<<smallestDist(str,word1,word2)<<endl;
}
