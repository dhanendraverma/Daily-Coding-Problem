/*****************************************************************************************************************************
This problem was asked by Quantcast.
You are presented with an array representing a Boolean expression. The elements are of two kinds:
T and F, representing the values True and False.
&, |, and ^, representing the bitwise operators for AND, OR, and XOR.
Determine the number of ways to group the array elements using parentheses so that the entire expression evaluates to True.
For example, suppose the input is ['F', '|', 'T', '&', 'T']. In this case, there are two acceptable groupings: 
(F | T) & T and F | (T & T).
*****************************************************************************************************************************/

#include<iostream> 
#include <vector>
#include<cstring> 
using namespace std; 

int countParenth(vector<char> input){ 
    vector<char> operand,ops;
    for(int i=0;i<input.size();i++){
        if(i%2)
            ops.push_back(input[i]);
        else
            operand.push_back(input[i]);
            
    }
    int n = operand.size(), m = ops.size();
	vector<vector<int>> F(n,vector<int>(n)), T(n,vector<int>(n)); 
	for(int i=0;i<n;i++){ 
		F[i][i] = (operand[i] == 'F')? 1: 0; 
		T[i][i] = (operand[i] == 'T')? 1: 0; 
	} 
// 	cout<<n<<m<<endl;
	for(int len=1;len<n;len++){ 
		for(int i=0;i<n-len;i++){ 
		    int j = i+len;
			T[i][j] = F[i][j] = 0; 
			for (int k=i;k<j;k++){ 
				int tik = T[i][k] + F[i][k]; 
				int tkj = T[k+1][j] + F[k+1][j]; 
				if (ops[k] == '&'){ 
					T[i][j] += T[i][k]*T[k+1][j]; 
					F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]); 
				} 
				if (ops[k] == '|'){ 
					F[i][j] += F[i][k]*F[k+1][j]; 
					T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]); 
				} 
				if (ops[k] == '^'){ 
					T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j]; 
					F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j]; 
				} 
			} 
		} 
	} 
	return T[0][n-1]; 
} 


int main() 
{ 
	vector<char> input = {'F', '|', 'T', '&', 'T'}; 
	cout<<countParenth(input)<<endl; 
	return 0; 
} 
