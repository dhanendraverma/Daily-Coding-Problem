/***************************************************************************************************************************************
Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C, replace the color of the given pixel and 
all adjacent same colored pixels with C.
For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:
B B W
W W W
W W W
B B B
Becomes
B B G
G G G
G G G
B B 
***************************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};

void changeColorRecur(vector<vector<string>>& image,string color, string initial_color,int i,int j){
	if(i<0 || i>=image.size() || j<0 || j>=image[i].size() || image[i][j]!=initial_color)
		return;
	image[i][j] = color;
	for(int p=0;p<4;p++){
		changeColorRecur(image,color,initial_color,i+dir[p][0],j+dir[p][1]);
	}
}

void changeColor(vector<vector<string>>& image,string color,int i,int j){
	if(image[i-1][j-1]==color)
		return;
	changeColorRecur(image,color,image[i-1][j-1],i-1,j-1);
}
int main() {
	vector<vector<string>> image =  {{"B", "B", "W"},
									{"W", "W", "W"},
									{"W", "W", "W"},
									{"B", "B", "B"}};
	string color = "G";
	vector<int> start = {2,2};
	changeColor(image,color,start[0], start[1]);
	for(int i=0;i<image.size();i++){
		for(int j=0;j<image[i].size();j++)
			cout<<image[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
