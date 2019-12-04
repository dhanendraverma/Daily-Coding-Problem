/****************************************************************************************************************************************
Given a real number n, find the square root of n. For example, given n = 9, return 3.
*****************************************************************************************************************************************/
#include <iostream>
using namespace std;

int squareRoot(int n)  
{     
    if (n == 0 || n == 1)  
       return n; 
    int start = 1, end = n, ans;    
    while(start <= end){         
    	int mid = (start + end) / 2; 
        if(mid*mid == n) 
            return mid; 
        if(mid*mid < n)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else
            end = mid-1;         
    } 
    return ans; 
} 

int main() {
	int n = 10;
	cout<<squareRoot(n);
	return 0;
}
