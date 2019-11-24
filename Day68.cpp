/**************************************************************************************************************************************
This problem was asked by Google.
On our special chessboard, two bishops attack each other if they share the same diagonal. This includes bishops that have another
bishop located between them, i.e. bishops can attack through pieces.
You are given N bishops, represented as (row, column) tuples on a M by M chessboard. Write a function to count the number of pairs of 
bishops that attack each other. The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).
For example, given M = 5 and the list of bishops:
(0, 0)
(1, 2)
(2, 2)
(4, 0)
The board would look like this:
[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]
You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.
**************************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//wrong approach
/*int CountAttackingBishopPairs(vector<vector<int>> pos){
	int count = 0;
	for(int i=0;i<pos.size()-1;i++){
		for(int j=i+1; j<pos.size();j++){
			int rowdiff = pos[j][0] - pos[i][0];
			int coldiff = pos[j][1] - pos[i][1];
			if(rowdiff == coldiff || rowdiff == -coldiff){
				count++;
			}
		}
	}
	return count;
}
*/

int attacking_bishops(vector<vector<int>>mat){
	map<int,int> cnt;
	int ans = 0;
	int i,j;
	for(int k=0;k<mat.size();k++){
		i = mat[k][0];
		j = mat[k][1];
		ans += cnt[i-j];
		cnt[i-j]++;
		if(i+j!=abs(i-j)){
			ans += cnt[i+j];
			cnt[i+j]++;	
		}
		//cout<<"cnt"<<cnt[i-j]<<cnt[i+j]<<endl;
		//cout<<i<<" "<<j<<" "<<ans<<endl;
	}
	return ans;
}


int main() {
	vector<vector<int>> mat ={{0,0},{1,4},{4,2},{3,1},{1,0},{1,1},{2,3}};
	cout<<attacking_bishops(mat);
	//cout<<CountAttackingBishopPairs(mat);
	return 0;
}
