/*****************************************************************************************************************************
This problem was asked by Microsoft.
You are given an string representing the initial conditions of some dominoes. Each element can take one of three values:
L, meaning the domino has just been pushed to the left, 
R, meaning the domino has just been pushed to the right, or
., meaning the domino is standing still.
Determine the orientation of each tile when the dominoes stop falling. Note that if a domino receives a force from the left 
and right side simultaneously, it will remain upright.
For example, given the string .L.R....L, you should return LL.RRRLLL.
Given the string ..R...L.L, you should return ..RR.LLLL.
******************************************************************************************************************************/

#include <iostream>
using namespace std;

string finalDominoes(string Dominoes){
	if(Dominoes=="")
		return "";
	int last = 0;
	for(int i=0;i<Dominoes.length();i++){
		if(Dominoes[i]!='.'){
			if(!last && Dominoes[i]=='L')
				fill_n(Dominoes.begin(),i,'L');
			else if(Dominoes[i]=='R' && Dominoes[last]=='R')
				fill_n(Dominoes.begin()+last,i-last+1,'R');
			else if(Dominoes[i]=='L' && Dominoes[last]=='L')
				fill_n(Dominoes.begin()+last,i-last+1,'L');
			else{
				int mid = last + (i-last)/2;
				fill_n(Dominoes.begin()+last,mid-last,Dominoes[last]);
				if((i-last)%2)
					fill_n(Dominoes.begin()+mid,i-mid,Dominoes[i]);
				else
					fill_n(Dominoes.begin()+mid+1,i-mid,Dominoes[i]);
			}
			last = i;
		}
	}
	return Dominoes;
}

int main() {
	string iDominoes = "..R...L.L";
	cout<<finalDominoes(iDominoes)<<endl;
	return 0;
}
