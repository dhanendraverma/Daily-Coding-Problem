/*****************************************************************************************************************************
This problem was asked by Spotify.
There are N couples sitting in a row of length 2 * N. They are currently ordered randomly, but would like to rearrange 
themselves so that each couple's partners can sit side by side.
What is the minimum number of swaps necessary for this to happen?
*****************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void updateIndex(vector<int> index, int a, int ai, int b, int bi) { 
    index[a] = ai; 
    index[b] = bi; 
} 
  
int minSwapsRec(vector<int> arr,vector<int> pairs,vector<int> index,int i,int n){
	if(i>n)
		return 0;
	if(pairs[arr[i]]==arr[i+1]) //if they pairs are in right position
		return minSwapsRec(arr,pairs,index,i+2, n);
	// if pairs are not in right position then swap arr[i+1] with the pair of arr[i]
	int first = arr[i+1];
	int firstidx = index[pairs[arr[i]]];
	int second = arr[firstidx];
	int secondidx = i+1;
	swap(arr[i+1],arr[firstidx]);
	updateIndex(index, first, firstidx, second, secondidx);
	int a = minSwapsRec(arr, pairs, index, i+2, n);
	
	// bactracking to create another solution
	swap(arr[i+1],arr[firstidx]);
	updateIndex(index, first, secondidx, second, firstidx);
	
	// if pairs are not in right position then swap arr[i] with the pair of arr[i+1]
	first = arr[i];
	firstidx = index[arr[i]];
	second = arr[firstidx];
	secondidx = i;
	swap(arr[i],arr[firstidx]);
	updateIndex(index, first, firstidx, second, secondidx);
	int b = minSwapsRec(arr, pairs, index, i+2, n);
	swap(arr[i],arr[firstidx]);
	updateIndex(index, first, secondidx, second, firstidx);
	return 1+min(a,b);
}

int minSwapsRequired(vector<int> arr, vector<int> pairs){
	int n = arr.size()/2;
	vector<int> index(2*n+1);
	for(int i=1;i<=2*n;i++)
		index[arr[i]] = i;
		
	return minSwapsRec(arr,pairs,index,1,2*n);
}

int main() {
	vector<int> arr = {0, 3, 5, 6, 4, 1, 2};
	vector<int> pairs = {0, 3, 6, 1, 5, 4, 2};
	cout<<minSwapsRequired(arr,pairs)<<endl;
	return 0;
}
