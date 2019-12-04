/****************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Facebook.
You have a large array with most of the elements as zero.
Use a more space-efficient data structure, SparseArray, that implements the same interface:
init(arr, size): initialize with the original large array and size.
set(i, val): updates index at i with val.
get(i): gets the value at index i.
*****************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class SparseArray{
	public:
	map<int,int> spcarr;
	SparseArray(vector<int> arr,int size){
		for(int i=0;i<size;i++){
			if(arr[i])
				spcarr[i] = arr[i];
		}
	}
	
	void set(int i, int val){
		spcarr[i] = val;
	}
	
	int get(int i){
		if(spcarr.find(i)!=spcarr.end())
			return spcarr[i];
		return 0;
	}
};

int main() {
	vector<int> arr = {2, 1, 0, 0, 0, 4, 5, 3, 0, 0, 0,2};
	SparseArray efficientArr(arr,arr.size());
	cout<<efficientArr.get(4)<<endl;
	cout<<efficientArr.get(3)<<endl;
	efficientArr.set(3,12);
	cout<<efficientArr.get(3)<<endl;
	return 0;
}
