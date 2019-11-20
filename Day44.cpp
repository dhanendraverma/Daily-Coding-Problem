/****************************************************************************************************************************************
This problem was asked by Google.
We can determine how "out of order" an array A is by counting the number of inversions it has. Two elements A[i] and A[j] form an 
inversion if A[i] > A[j] but i < j. That is, a smaller element appears after a larger element.
Given an array, count the number of inversions it has. Do this faster than O(N^2) time.
You may assume each element in the array is distinct.
For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3). 
The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
****************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> numbers, vector<int> temp,int left, int mid, int right){
	int i=left,j=mid,k=left,inv_cnt=0;
	while(i<=mid-1 && j<=right){
		if(numbers[i]<=numbers[j])
			temp[k++] = numbers[i++];
		else{
			temp[k++] = numbers[j++];
			inv_cnt += mid-i;
		}
	}
	while(i<=mid-1)
		temp[k++] = numbers[i++];
	while(j<=right)
		temp[k++] = numbers[j++];
	for(int i=left;i<=right;i++)
		numbers[i] = temp[i];
	return inv_cnt;
}

int merge_sort(vector<int> numbers, vector<int> temp,int left,int right){
	int mid,inv_cnt=0;
	if(right>left){
		mid = (left+right)/2;
		inv_cnt = merge_sort(numbers,temp,left,mid);
		inv_cnt += merge_sort(numbers,temp,mid+1,right);
		inv_cnt += merge(numbers,temp,left,mid+1,right);
	}
	return inv_cnt;
}

int count_inversion(vector<int> numbers){
	vector<int> temp(numbers.size());
	return merge_sort(numbers,temp,0,numbers.size()-1);
}

int main() {
	vector<int> numbers={ 1, 20, 6, 4, 5 };
	cout<<count_inversion(numbers);
	return 0;
}
