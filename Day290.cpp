/*****************************************************************************************************************************
This problem was asked by Facebook.
On a mysterious island there are creatures known as Quxes which come in three colors: red, green, and blue. One power of the
Qux is that if two of them are standing next to each other, they can transform into a single creature of the third color.
Given N Quxes standing in a line, determine the smallest number of them remaining after any possible sequence of such 
transformations.
For example, given the input ['R', 'G', 'B', 'G', 'B'], it is possible to end up with a single Qux through the following 
steps:

        Arrangement       |   Change
----------------------------------------
['R', 'G', 'B', 'G', 'B'] | (R, G) -> B
['B', 'B', 'G', 'B']      | (B, G) -> R
['B', 'R', 'B']           | (R, B) -> G
['B', 'G']                | (B, G) -> R
['R']                     |
******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int afterTrasnformation(vector<char> Quex){
    int red=0,green=0,blue=0;
    for(auto c:Quex){
        if(c=='R')
            red++;
        else if(c=='G')
            green++;
        else
            blue++;
    }
    if(red==Quex.size() || green==Quex.size() || blue==Quex.size())
        return Quex.size();
    if(red%2==green%2 && green%2==blue%2)
        return 2;
    return 1;
}

int main() {
    vector<char> Quex = {'R', 'G', 'B', 'G', 'B'};
    cout<<afterTrasnformation(Quex)<<endl;
	return 0;
}
