/**************************************************************************************************************************************
This problem was asked by Google.
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, 
the Gs come second, and the Bs come last. You can only swap elements of the array.
Do this in linear time and in-place.
For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
*************************************************************************************************************************************/
#include <bits/stdc++.h> 
using namespace std; 

void dutch_national_flag(vector<char>& colors) 
{ 
	int lo = 0; 
	int hi = colors.size() - 1; 
	int mid = 0; 

	while (mid <= hi) { 
		switch (colors[mid]) { 
		case 'R': 
			swap(colors[lo++], colors[mid++]); 
			break; 
		case 'G': 
			mid++; 
			break; 
		case 'B': 
			swap(colors[mid],colors[hi--]); 
			break; 
		} 
	} 
} 


int main() 
{ 
	vector<char> colors =  {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
	dutch_national_flag(colors); 
	for (int i = 0; i < colors.size(); i++) 
		cout << colors[i] << " "; //R R R G G B B
	return 0; 
} 

