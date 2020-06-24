/*******************************************************************************************************************************************************************
This problem was asked by Amazon.
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the 
number of unique ways you can climb the staircase. The order of the steps matters.
For example, if N is 4, then there are 5 unique ways:
•	1, 1, 1, 1
•	2, 1, 1
•	1, 2, 1
•	1, 1, 2
•	2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? 
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*******************************************************************************************************************************************************************/


// ######################################### Bottom up approach ######################################

#include <iostream>
#include <vector>
using namespace std;

int no_of_ways(vector<int>& steps,int n){
    vector<int> T(n+1,0);
    T[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<steps.size();j++)
            if(steps[j]<=i)
                T[i] += T[i-steps[j]];
    }
    return T[n];
}



int main() {
    vector<int> steps = {1,2};
    int n = 4;
    cout<<no_of_ways(steps,n)<<endl;
	return 0;
}


// ######################################### Top down approach ######################################
#include <iostream>
#include <vector>
using namespace std;

int no_of_ways(vector<int>& steps,int n,vector<int>& T){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(T[n]!=-1)
        return T[n];
    int count = 0;
    for(int i=0;i<steps.size();i++){
        if(steps[i]<=n)
            count += no_of_ways(steps,n-steps[i],T);
    }
    return T[n] = count;
}


int main() {
    vector<int> steps = {1,2,3};
    int n = 4;
    vector<int> T(n+1,-1);
    cout<<no_of_ways(steps,n,T)<<endl;
	return 0;
}
