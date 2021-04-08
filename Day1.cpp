/*********************************************************************************************************************************************************
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.                           
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.  
***********************************************************************************************************************************************************/

#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

void findPair(vector<int> arr, int k){ 
    unordered_set<int> s; 
    for(int i = 0; i < arr.size(); i++){ 
        int temp = k - arr[i]; 
        if (temp >= 0 && s.find(temp) != s.end()){ 
        	cout << "Pair with given sum " << k << " is (" << arr[i] << ", " << temp << ")" << endl;
        	break;
        }
        s.insert(arr[i]); 
    } 
} 


int main()
{
	vector<int> arr = {10, 15, 3, 7};
	int k = 17;
	findPair(arr, k);
}
