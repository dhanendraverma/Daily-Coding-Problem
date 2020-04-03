/*****************************************************************************************************************************
This problem was asked by Stitch Fix.
Pascal's triangle is a triangular array of integers constructed with the following formula:
The first row consists of the number 1.
For each subsequent row, each element is the sum of the numbers directly above it, on either side.
For example, here are the first few rows:

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
Given an input k, return the kth row of Pascal's triangle.
Bonus: Can you do this using only O(k) space?
*****************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> kthRowOfPascal(int k){
    int e=1;
    vector<int> kthRow;
    for(int i=1;i<=k;i++){
        kthRow.push_back(e);
        e = e*(k-i)/i;
    }
    return kthRow;
} 

int main() {
    int k = 5;
    vector<int> kthRow = kthRowOfPascal(k);
    for(auto e:kthRow)
        cout<<e<<" ";
	return 0;
}
