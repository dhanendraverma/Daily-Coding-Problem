/******************************************************************************************************************************
This problem was asked by Jane Street.
The United States uses the imperial system of weights and measures, which means that there are many different, 
seemingly arbitrary units to measure distance. There are 12 inches in a foot, 3 feet in a yard, 22 yards in a chain, and so on.
Create a data structure that can efficiently convert a certain quantity of one unit to the correct amount of any other unit.
You should also allow for additional units to be added to the system.
******************************************************************************************************************************/

#include <iostream>
#include <map>
#include <set>
using namespace std;

class Converter{
	public:
	map<string,map<string,double>> mp;
	double factor;
	Converter(){
		this->factor = 1.0;
	}
	
	bool dfs(string src,string target, set<string>& visited){
		if(src==target)
			return true;
		cout<<"y"<<endl;
		for(auto edge:mp[src]){
			if(visited.find(edge.first) == visited.end()){
				factor *= mp[src][edge.first];
				visited.insert(edge.first);
				if(dfs(edge.first,target,visited))
					return true;
				factor /= mp[src][edge.first];
			}
		}
		return false;
	}
	
	void addUnits(string unit1, double value1, string unit2, double value2){
		mp[unit1][unit2] = value2/value1;
		mp[unit2][unit1] = value1/value2;
	}
	
	double convert(string unit1, double value1, string unit2){
		set<string> visited;
		factor = 1.0;
		if(!dfs(unit1,unit2,visited)){
			cout<<"Conversion is not possible"<<endl;
			return -1;
		}
		return value1*factor;
	}
};

int main() {
	Converter conv;
	conv.addUnits("inch",12,"feet",1);
	conv.addUnits("feet",3,"yard",1);
	conv.addUnits("yard",22,"chain",1);
	cout<<conv.convert("inch",1,"yard")<<endl;
	return 0;
}
