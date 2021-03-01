/**************************************************************************************************************************************
This problem was asked by Microsoft.
Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on
each new element.
Recall that the median of an even-numbered list is the average of the two middle numbers.
**************************************************************************************************************************************/
#include<bits/stdc++.h> 
using namespace std; 

void running_median(vector<double> arr, int n) 
{ 
	priority_queue<double> smaller; 
	priority_queue<double,vector<double>,greater<double> > greater; 
	double med = arr[0]; 
	s.push(arr[0]); 
	cout << med << endl; 
	for (int i=1; i < n; i++) 
	{ 
		double x = arr[i]; 
		if (smaller.size() > greater.size()) 
		{ 
			if (x < med) 
			{ 
				greater.push(s.top()); 
				smaller.pop(); 
				smaller.push(x); 
			} 
			else
				greater.push(x); 

			med = (smaller.top() + greater.top())/2.0; 
		} 
		else if (smaller.size()==greater.size()) 
		{ 
			if (x < med) 
			{ 
				smaller.push(x); 
				med = (double)smaller.top(); 
			} 
			else
			{ 
				greater.push(x); 
				med = (double)greater.top(); 
			} 
		} 
		else
		{ 
			if (x > med) 
			{ 
				smaller.push(greater.top()); 
				greater.pop(); 
				greater.push(x); 
			} 
			else
				smaller.push(x); 

			med = (smaller.top() + greater.top())/2.0; 
		} 

		cout << med << endl; 
	} 
} 

int main() 
{ 
	vector<double> arr = {2, 1, 5, 7, 2, 0, 5}; 
	int n = arr.size();
	running_median(arr, n); 
	return 0; 
} 
