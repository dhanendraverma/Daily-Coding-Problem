/*****************************************************************************************************************************
This problem was asked by Amazon.
At a popular bar, each customer has a set of favorite drinks, and will happily accept any drink among this set. 
For example, in the following situation, customer 0 will be satisfied with drinks 0, 1, 3, or 6.
preferences = {
    0: [0, 1, 3, 6],
    1: [1, 4, 7],
    2: [2, 4, 7, 5],
    3: [3, 2, 5],
    4: [5, 8]
}
A lazy bartender working at this bar is trying to reduce his effort by limiting the drink recipes he must memorize. 
Given a dictionary input such as the one above, return the fewest number of drinks he must learn in order to satisfy 
all customers.
For the input above, the answer would be 2, as drinks 1 and 5 will satisfy everyone.
/*****************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int fewestDrinks(vector<vector<int>> fav_drinks){
    int c = fav_drinks.size(), d=0;
    for(auto drinks:fav_drinks)
        for(auto drink:drinks)
            d = max(d,drink);
    vector<vector<int>> arr(d+1,vector<int>(c+1,0));
    for(int i=0;i<c;i++){
        for(int j=0;j<fav_drinks[i].size();j++){
            // cout<<fav_drinks[i][j]<<endl;
            arr[fav_drinks[i][j]][i] = 1;
        }
    }
    for(int i=0;i<d;i++){
        int sum=0;
        for(int j=0;j<c;j++){
            sum += arr[i][j];
        }
        arr[i][c] = sum;
    }
    int customers = c, count=0;
    while(customers){
        int max_idx,max_val=0;
        for(int i=0;i<d;i++){
            if(arr[i][c]>max_val){
                max_val =arr[i][c];
                max_idx = i;
            }
        }
        count++;
        customers -= max_val;
        for(int i=0;i<c;i++){
            if(arr[max_idx][i]){
                for(int j=0;j<d;j++){
                    if(arr[j][i]){
                        arr[j][i] = 0;
                        arr[j][c] -= 1;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> fav_drinks = {{0, 1, 3, 6},
        {1, 4, 7},
        {2, 4, 7, 5},
        {3, 2, 5},
        {5, 8}
    };
    cout<<fewestDrinks(fav_drinks)<<endl;
	return 0;
}
