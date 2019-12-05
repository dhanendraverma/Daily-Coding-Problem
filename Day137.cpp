/**************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Amazon.
Implement a bit array.
A bit array is a space efficient array that holds a value of 1 or 0 at each index.
init(size): initialize the array with size
set(i, val): updates index at i with val where val is either 1 or 0.
get(i): gets the value at index i.
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class BitArray{
	public:
	set<int> set_indices;
	int size;
	BitArray(vector<int> arr){
		this->size = arr.size();
		for(int i=0;i<arr.size();i++)
			if(arr[i])
				set_indices.insert(i);
	}
	
	void Set(int i, int v){
		if(i>size-1)
			cout<<"Index range is out of bound"<<endl;
		if(v==1 && set_indices.find(i)==set_indices.end())
			set_indices.insert(i);
		else if(v==0 && set_indices.find(i)!=set_indices.end())
			set_indices.erase(set_indices.find(i));
	}
	
	int Get(int i){
		if(i>size-1)
			cout<<"Index range is out of bound";
		return set_indices.find(i)==set_indices.end()?0:1;
	}
};

int main() {
	vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	BitArray bitarr(arr);
	cout<<bitarr.Get(3)<<endl;
	bitarr.Set(3,1);
	cout<<bitarr.Get(3)<<endl;
	return 0;
}
