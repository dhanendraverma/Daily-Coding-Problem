/*****************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Uber.
A rule looks like this:
A NE B
This means this means point A is located northeast of point B.
A SW C
means that point A is southwest of C.
Given a list of rules, check if the sum of the rules validate. For example:
A N B
B NE C
C N A
does not validate, since A cannot be both north and south of C.
A NW B
A N B
is considered valid.
*****************************************************************************************************************************************/

#include <iostream>
using namespace std;

class Pos{
	public:
	int x,y;
	Pos{}
	Pos(int x, int y){
		this->x = x;
		this->y = y;
	}
};

Pos get_pos(string dir){
	switch(dir){
		case "N":
			return Pos(1,0);
		case "NE":
			return Pos(1,1);
		case "E":
			return Pos(0,1);
		case "SE":
			return Pos(0,1);
		case "S":
			return Pos(0,-1);
		case "SW":
			return Pos(-1,-1);
		case "W":
			return Pos(-1,0);
		case "NW":
			return Pos(1,1);
	}
}

bool is_valid(char to, char from, string dir){
	swtich(dir){
		case "N":
		if(to.y>from.y)
			return true;
		break;
		case "NE":
		if(to.y>from.y && to.x>from.x)
			return true;
		break;
		case "E":
		if(to.x>from.x)
			return true;
		break;
		case "SE":
		if(to.x>from.x && from.y>to.y)
			return true;
		break;
		case "S":
		if(from.y>to.y)
			return true;
		break;
		case "SW":
		if(from.y>to.y && from.x>to.x)
			return true;
		break;
		case "W":
		if(from.x>to.x)
			return true;
		break;
		case "NW":
		if(from.y<to.y && from.x>to.x)
			return true;
		break;
		default:
			return false;
		
	}
}

bool isValidRules(vector<vector<string>> rules){
	map<char,pos> mp; 
	char to,form;
	string dir;
	for(int i=0;i<rules.size();i++){
		to = rules[i][0];
		dir = rules[i][1];
		from = rules[i][2];
		Pos curr = get_pos(dir);
		if((mp.find(to)!=mp.end()) && (mp.find(from)!=mp.end())){
			if(!is_vaild(to,form,dir))
				return false;
		}
		else if((mp.find(to)!=mp.end()) && (mp.find(from)==mp.end())) //to found but not from
			mp[to] = Pos(mp[to].x+curr.x, mp[to].y+curr.y);
		else if((mp.find(to)==mp.end()) && (mp.find(from)!=mp.end()))//from found but not to
			mp[to] = Pos(mp[from].x+curr.x, mp[from].y+curr.y);
		else{
			mp[to] = Pos(0,0);
			mp[from] = Pos(curr.x, curr.y);
		}
	}
}

int main() {
		return 0;
}
