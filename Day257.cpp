#include <iostream>
#include <vector>
using namespace std;

void findSmallestWin(vector<int> arr){
	int s,e,n=arr.size();
	for(int i=0;i<n-1;i++){
		if(arr[i]>arr[i+1]){
			s = i;
			break;
		}
	}
	if(s==n-1){
		cout<<"Array is already sorted"<<endl;
		return;
	}
	for(int i=n-1;i>=0;i--){
		if(arr[i]<arr[i-1]){
			e = i;
			break;
		}
	}
	int mn=s,mx=s;
	for(int i=s+1;i<=e;i++){
		mn = min(mn,arr[i]);
		mx = max(mx,arr[i]);
	}
	for(int i=0;i<s;i++){
		if(arr[i]>mn){
			s = i;
			break;
		}
	}
	for(int i=n-1;i>=e+1;i--){
		if(arr[i]<mx){
			e = i;
			break;
		}
	}
	cout<<"s = "<<s<<", e = "<<e<<endl;
	for(int i=s;i<=e;i++)
		cout<<arr[i]<<" ";
}

int main() {
	vector<int> arr = {3, 7, 5, 6, 9};
	findSmallestWin(arr);
	return 0;
}
