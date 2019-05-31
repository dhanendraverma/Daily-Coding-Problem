/*---------------Question-----------------------------------------------------------//
*   Given a list of numbers and a number k,                                         //
*   return whether any two numbers from the list add up to k.                       //    
*   For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.  //
*-----------------------------------------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

void find_pair(int arr[], int arr_size, int sum) 
{ 
    unordered_set<int> s; 
    for(int i = 0; i < arr_size; i++) 
    { 
        int temp = sum - arr[i]; 
  
        if (temp >= 0 && s.find(temp) != s.end()) 
            cout << "Pair with given sum " << sum << 
                 " is (" << arr[i] << ", " << temp << 
                 ")" << endl; 
  
        s.insert(arr[i]); 
    } 
} 



int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    find_pair(a,n,k);
  
}
