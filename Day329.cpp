/******************************************************************************************************************************
This problem was asked by Amazon.
The stable marriage problem is defined as follows:
Suppose you have N men and N women, and each person has ranked their prospective opposite-sex partners in order of preference.
For example, if N = 3, the input could be something like this:
guy_preferences = {
    'andrew': ['caroline', 'abigail', 'betty'],
    'bill': ['caroline', 'betty', 'abigail'],
    'chester': ['betty', 'caroline', 'abigail'],
}
gal_preferences = {
    'abigail': ['andrew', 'bill', 'chester'],
    'betty': ['bill', 'andrew', 'chester'],
    'caroline': ['bill', 'chester', 'andrew']
}
Write an algorithm that pairs the men and women together in such a way that no two people of opposite sex would both rather 
be with each other than with their current partners.
******************************************************************************************************************************/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool m1Overm(string gal,string man,string man1,map<string,vector<string>>& gal_preferences){
    for(auto m:gal_preferences[gal]){
        if(m==man1)
            return true;
        if(m==man)
            return false;
    }
}

void stable_marriage(map<string,vector<string>>& guy_preferences, map<string,vector<string>>& gal_preferences){
    map<string,bool> men;
    for(auto guy:guy_preferences)
        men[guy.first] = false;
    map<string,string> womanToman;
    int freeMen = men.size();
    while(freeMen){
        string man;
        for(auto guy:guy_preferences)
            if(men[guy.first]==false)
                man = guy.first;
        for(auto gal:guy_preferences[man]){
            if(men[man]==true)
                break;
            if(womanToman.find(gal) == womanToman.end()){
                womanToman[gal] = man;
                men[man] = true;
                freeMen--;
            }
            else{
                string man1 = womanToman[gal];
                if(!m1Overm(gal,man,man1,gal_preferences)){
                    womanToman[gal] = man;
                    men[man] = true;
                    men[man1] = false;
                }
                
            }
        }
    }
    for(auto pair:womanToman)
        cout<<pair.first<<" "<<pair.second<<endl;
    
}

int main() {
	map<string,vector<string>> guy_preferences, gal_preferences;
	guy_preferences["andrew"] = {"caroline", "abigail", "betty"};
	guy_preferences["bill"] = {"caroline", "betty", "abigail"};
	guy_preferences["chester"] = {"betty", "caroline", "abigail"};
	gal_preferences["abigail"] = {"andrew", "bill", "chester"};
	gal_preferences["betty"] = {"bill", "andrew", "chester"};
	gal_preferences["caroline"] = {"bill", "chester", "andrew"};
	stable_marriage(guy_preferences,gal_preferences);
	return 0;
}
