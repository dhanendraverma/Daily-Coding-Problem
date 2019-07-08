/*****************************************************************************************************************************************
Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:
10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. 
You can simply print them out as you compute them.
******************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void printMaxk(vector<int> A, int n, int k) {
    int maxk = INT_MIN;
    int i = 0;
    while(i<n) {
        while(i<k) {
            maxk = max(maxk,A[i]);
            i++;
        }
        cout<<maxk<<" ";
        maxk = max(maxk,A[i]);
        i++;
    }
    cout<<maxk<<endl;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> A(n,0);
    for(int i=0; i<n; i++)
        cin>>A[i];
    printMaxk(A,n,k);
    return 0;
 
}
