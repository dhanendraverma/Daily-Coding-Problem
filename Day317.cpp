/******************************************************************************************************************************
#include <iostream>
using namespace std;

int andOfRange(int N, int M){
    if(N==0 || M==0)
        return 0;
    //keeps track of the positions from right where both aren't equal
    int trailing_zero = 1;
    //when both number become equal it's sure that all the bit positions at the corresponding bit
    //positions will be same in the whole range, kind of same prefix for all the numbers in the range
    while(N != M){
        trailing_zero *= 2;
        N = N/2;
        M = M/2;
    }
    return N*trailing_zero;
}


int main() {
    int N = 10, M = 15;
    cout<<andOfRange(N,M)<<endl;
	return 0;
}
******************************************************************************************************************************/

#include <iostream>
using namespace std;

int andOfRange(int N, int M){
    if(N==0 || M==0)
        return 0;
    //keeps track of the positions from right where both aren't equal
    int trailing_zero = 1;
    //when both number become equal it's sure that all the bit positions at the corresponding bit
    //positions will be same in the whole range, kind of same prefix for all the numbers in the range
    while(N != M){
        trailing_zero *= 2;
        N = N/2;
        M = M/2;
    }
    return N*trailing_zero;
}


int main() {
    int N = 10, M = 15;
    cout<<andOfRange(N,M)<<endl;
	return 0;
}
