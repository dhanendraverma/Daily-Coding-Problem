/*****************************************************************************************************************************
This problem was asked by Twitter.
You are given an array of length 24, where each element represents the number of new subscribers during the corresponding 
hour. Implement a data structure that efficiently supports the following:
update(hour: int, value: int): Increment the element at index hour by value.
query(start: int, end: int): Retrieve the number of subscribers that have signed up between start and end (inclusive).
You can assume that all values get cleared at the end of the day, and that you will not be asked for start and end values 
that wrap around midnight.
*****************************************************************************************************************************/

class subscribersTrack{
	public:
	vector<int> arr;
	subscribersTrack(){
		arr = vector<int>(24,0);
	}
	
	void update(int hour, int value){
		if(hour>24)
			cout<<"Please enter a value between 1-24";
		for(int i=hour-1;i<24;i++)
			arr[i] += value;
	}
	
	int query(int start, int end){
		if(start<1 || start>24 || end<1 || end>24){
			cout<<"Please enter a value between 1-24";
			return -1;
		}
		if(end>23)
			end = 23;
		if(start==end)
			return arr[start-1];
		if(start==1)
			return arr[end];
		return arr[end]-arr[start-1];
	}
};

int main() {
	subscribersTrack arr;
	arr.update(1,12);
	arr.update(2,8);
	cout<<arr.query(1,1);
	return 0;
}
