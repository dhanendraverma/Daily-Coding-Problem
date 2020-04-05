/*****************************************************************************************************************************
This problem was asked by Uber.
On election day, a voting machine writes data in the form (voter_id, candidate_id) to a text file. 
Write a program that reads this file as a stream and returns the top 3 candidates at any given time. 
If you find a voter voting more than once, report this as fraud.
******************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class VotingMachine{
    private:
    vector<int> top_three;
    set<int> voters;
    map<int,int> vote_count;
    
    public:
    void process_votes(pair<int,int> vote){
        if(voters.find(vote.first) != voters.end()){
            cout<<"One voter can vote only once!"<<endl;
            return;
        }
        voters.insert(vote.first);
        vote_count[vote.second]++;
        if(top_three.size()<3)
            top_three.push_back(vote.second);
        else{
            int i=0;
            while(i<3){
                if(vote_count[top_three[i]]<vote_count[vote.second]){
                    top_three[i] = vote.second;
                    break;
                }
                i++;
            }
        }
    }
    
    void getTopThree(){
        for(auto i:top_three)
            cout<<i<<" ";
        cout<<endl;
    } 
};


int main() {
    VotingMachine vm;
    vm.process_votes({1,3});
    vm.process_votes({2,4});
    vm.getTopThree();
    vm.process_votes({5,6});
    vm.process_votes({1,2});
	return 0;
}
