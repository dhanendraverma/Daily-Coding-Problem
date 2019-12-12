#include <iostream>
using namespace std;

#define pair<string,pair<int,int>> Core
#define pair<string,pair<int,int>> Dim

Core convertDim(Core core, Dim dim){
	Core new_core;
	new_core.first = "top_left";
	if(core.first == "top_right")
		new_core.second = {core.second.first-dim.first, core.second.second};
	else if(core.first == "bottom_left")
		new_core.second = {core.second.first, core.second.second+dim.second};
	else if(core.first == "bottom_right")
		new_core.second = {core.second.first-dim.first, core.second.second+dim.second};
	return new_core;
}

int findArea(Core core1, Dim dim1, Core core2, Dim dim2){
	if(core1.first!="top_left")
		dim1 = covertDim(core1.first,dim1);
	if(core2.first!="top_left")
		dim2 = covertDim(core2.first,dim2);
	int w = min(core1.second.first+dim1.first,core2.second.first+dim2.first)-max(core1.second.first,core2.second.first);
	int l = min()
}


int main() {
	Core core1 = {"top_left",{1,4}};
	Dim dim1 = {3,3};
	Core core2 = {"top_left",{0,5}};
	Dim dim2 = {4,3};
	cout<<findArea(core1,core2,dim1,dim2);
	return 0;
}
