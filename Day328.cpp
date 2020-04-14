/******************************************************************************************************************************
This problem was asked by Facebook.
In chess, the Elo rating system is used to calculate player strengths based on game results.
A simplified description of the Elo system is as follows. Every player begins at the same score. For each subsequent game, 
the loser transfers some points to the winner, where the amount of points transferred depends on how unlikely the win is. 
For example, a 1200-ranked player should gain much more points for beating a 2000-ranked player than for beating a 
1300-ranked player.
Implement this system.
******************************************************************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

#define K 30

float winPropability(int rating1, int rating2){
    return 1.0/(1.0 + pow(10,float(rating1-rating2)/(float)400));
}

void ELOrating(float rating1, float rating2, bool win1){
    float proA = winPropability(rating2,rating1);
    float proB = winPropability(rating1, rating2);
    // cout<<proA<<" "<<proB<<endl;
    if(win1){
        rating1 = rating1 + K*(1-proA);
        rating2 = rating2 + K*(0-proB);
    }
    else{
        rating1 = rating1 + K*(0-proA);
        rating2 = rating2 + K*(1-proB);
    }
    
    cout<<rating1<<" "<<rating2<<endl;
}

int main() {
    float rating1 = 1200, rating2 = 1000;
    ELOrating(rating1, rating2, true);
    ELOrating(rating1, rating2, false);
	return 0;
}
