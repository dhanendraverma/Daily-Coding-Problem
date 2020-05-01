/******************************************************************************************************************************
This problem was asked by Square.
You are given a histogram consisting of rectangles of different heights. These heights are represented in an input list, 
such that [1, 3, 2, 5] corresponds to the following diagram:

      x
      x  
  x   x
  x x x
x x x x
Determine the area of the largest rectangle that can be formed only from the bars of the histogram. For the diagram above,
for example, this would be six, representing the 2 x 3 area at the bottom right.
******************************************************************************************************************************/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRecArea(vector<int>& histogram){
    stack<int> s;
    int max_area=0, curr, curr_area;
    int i = 0;
    while(i<histogram.size()){
        if(s.empty() || histogram[s.top()]<=histogram[i])
            s.push(i++);
        else{
            curr = s.top();
            s.pop();
            curr_area = histogram[curr]*(s.empty()?i:i-s.top()-1);
            max_area = max(curr_area,max_area);
            
        }
    }
    while(!s.empty()){
        curr = s.top();
        s.pop();
        curr_area = histogram[curr]*(s.empty()?i:i-s.top()-1);
        max_area = max(max_area,curr_area);
    }
    return max_area;
}

int main() {
    vector<int> histogram = {1, 3, 2, 5};
    cout<<largestRecArea(histogram)<<endl;
	return 0;
}
