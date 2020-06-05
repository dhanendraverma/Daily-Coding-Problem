/*****************************************************************************************************************************
This problem was asked by Quantcast.
You are presented with an array representing a Boolean expression. The elements are of two kinds:
T and F, representing the values True and False.
&, |, and ^, representing the bitwise operators for AND, OR, and XOR.
Determine the number of ways to group the array elements using parentheses so that the entire expression evaluates to True.
For example, suppose the input is ['F', '|', 'T', '&', 'T']. In this case, there are two acceptable groupings: 
(F | T) & T and F | (T & T).
*****************************************************************************************************************************/

// ######### TOp down approach #################
#include <iostream>
#include <vector>
using namespace std;
int solve(string str,int i,int j,vector<vector<int>>& T, vector<vector<int>>& F,bool tf){
    if(i>j)
        return 0;
        
    if(i==j){
        T[i][j] = (str[i]=='T'?1:0);
        F[i][j] = (str[i]=='F'?1:0);
    }
    
    if(tf==true && T[i][j]!=-1)
        return T[i][j];
    
    if(tf==false && F[i][j]!=-1)
        return F[i][j];    
     //Recursively solve the problem by breaking the expression at each oprator between i&j and solve left and right part
     //individually
    T[i][j] = F[i][j] = 0;
    for(int k=i+1;k<j;k+=2){
        T[i][k-1] = solve(str,i,k-1,T,F,true);
        F[i][k-1] = solve(str,i,k-1,T,F,false);
        T[k+1][j] = solve(str,k+1,j,T,F,true);
        F[k+1][j] = solve(str,k+1,j,T,F,false);
        if(str[k]=='|'){
            T[i][j] += T[i][k-1]*F[k+1][j]+F[i][k-1]*T[k+1][j]+T[i][k-1]*T[k+1][j];
            F[i][j] += F[i][k-1]*F[k+1][j];
        }
        else if(str[k]=='&'){
            T[i][j] += T[i][k-1]*T[k+1][j];
            F[i][j] += T[i][k-1]*F[k+1][j] + F[i][k-1]*T[k+1][j] + F[i][k-1]*F[k+1][j];
        }
        else if(str[k]=='^'){
            T[i][j] += T[i][k-1]*F[k+1][j] + F[i][k-1]*T[k+1][j];
            F[i][j] += T[i][k-1]*T[k+1][j] + F[i][k-1]*F[k+1][j];
            
        }
    }
    return tf==true?T[i][j]:F[i][j];
    
}
int main() {
    string str = "F|T&T";
    int n = str.length();
    vector<vector<int>> T(n,vector<int>(n,-1)), F(n,vector<int>(n,-1));
    cout<<solve(str,0,n-1,T,F,true)<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<T[i][j]<<" ";
    //     cout<<endl;
    // }
    return 0;
}




//########### Bottom up approach ##############
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
