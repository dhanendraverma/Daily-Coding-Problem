
/*****************************************************************************************************************************
This problem was asked by Google.
In linear algebra, a Toeplitz matrix is one in which the elements on any given diagonal from top left to bottom right are 
identical.
Here is an example:
1 2 3 4 8
5 1 2 3 4
4 5 1 2 3
7 4 5 1 2
Write a program to determine whether a given input is a Toeplitz matrix.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

bool checkDiagonal(vector<vector<int>>& matrix, int i, int j){
    int n = matrix.size(), m = matrix.size(), ele = matrix[i][j];
    while(i<n && j<m){
        if(matrix[i][j] != ele)
            return false;
        i++;
        j++;
    }
    return true;
}

bool isToeplitxMatrix(vector<vector<int>>& matrix){
    int n = matrix.size(), m = matrix[0].size();
    for(int i=0;i<n;i++){
        if(!checkDiagonal(matrix,i,0))
            return false;
    }
    for(int i=1;i<m;i++){
        if(!checkDiagonal(matrix,0,i))
            return false;
    }
    return true;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4, 8},
                                  {5, 1, 2, 3, 4},
                                  {4, 5, 1, 2, 3},
                                  {7, 4, 5, 1, 2}};
    cout<<isToeplitxMatrix(matrix)<<endl;
	return 0;
}
