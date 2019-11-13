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
	priority_queue<double> s; 
	priority_queue<double,vector<double>,greater<double> > g; 
	double med = arr[0]; 
	s.push(arr[0]); 
	cout << med << endl; 
	for (int i=1; i < n; i++) 
	{ 
		double x = arr[i]; 
		if (s.size() > g.size()) 
		{ 
			if (x < med) 
			{ 
				g.push(s.top()); 
				s.pop(); 
				s.push(x); 
			} 
			else
				g.push(x); 

			med = (s.top() + g.top())/2.0; 
		} 
		else if (s.size()==g.size()) 
		{ 
			if (x < med) 
			{ 
				s.push(x); 
				med = (double)s.top(); 
			} 
			else
			{ 
				g.push(x); 
				med = (double)g.top(); 
			} 
		} 
		else
		{ 
			if (x > med) 
			{ 
				s.push(g.top()); 
				g.pop(); 
				g.push(x); 
			} 
			else
				s.push(x); 

			med = (s.top() + g.top())/2.0; 
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
