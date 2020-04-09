/*****************************************************************************************************************************
You are given a circular lock with three wheels, each of which display the numbers 0 through 9 in order. Each of these wheels
rotate clockwise and counterclockwise.
In addition, the lock has a certain number of "dead ends", meaning that if you turn the wheels to one of these combinations, 
the lock becomes stuck in that state and cannot be opened.
Let us consider a "move" to be a rotation of a single wheel by one digit, in either direction. Given a lock initially set to
000, a target combination, and a list of dead ends, write a function that returns the minimum number of moves required to 
reach the target state, or None if this is impossible.
******************************************************************************************************************************/


#include <iostream>
#include <set>
using namespace std;

int minMoves(string source, string target, set<string> deadends){
    set<string>  q, other_q, visited; 
    q.insert(source);
    other_q.insert(target);
    int moves=0;
    while(!q.empty() && !other_q.empty()){
        set<string> nxt_q;
        for(auto state:q){
            // cout<<state<<endl;
            if(other_q.find(state)!=other_q.end())
                return moves;
            for(int i=0;i<state.length();i++){
                char old = state[i];
                state[i] = (state[i]=='9')?'0':state[i]+1;
                // cout<<state<<endl;
                if(visited.find(state)==visited.end() && deadends.find(state)==deadends.end())
                    nxt_q.insert(state);
                state[i] = old;
                state[i] = (state[i]=='0')?'9':state[i]-1;
                // cout<<state<<endl;
                if(visited.find(state)==visited.end() && deadends.find(state)==deadends.end())
                    nxt_q.insert(state);
                state[i] = old;
            }
        }
        moves++;
        q = other_q;
        other_q = nxt_q;
    }
    return -1;
}

int main() {
    string source = "0000", target = "0202";
    set<string> deadends = {"0201","0101","0102","1212","2002"};
    cout<<minMoves(source,target,deadends)<<endl;
	return 0;
}
