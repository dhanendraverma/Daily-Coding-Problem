/*****************************************************************************************************************************
This problem was asked by Airbnb.
<br>You are given a huge list of airline ticket prices between different cities around the world on a given day. These are all direct flights. Each element in the list has the format (source_city, destination, price).
<br>Consider a user who is willing to take up to k connections from their origin city A to their destination B. Find the cheapest fare possible for this journey and print the itinerary for that journey.
<br>For example, our traveler wants to go from JFK to LAX with up to 3 connections, and our input flights are as follows:
[
    ('JFK', 'ATL', 150),
    ('ATL', 'SFO', 400),
    ('ORD', 'LAX', 200),
    ('LAX', 'DFW', 80),
    ('JFK', 'HKG', 800),
    ('ATL', 'ORD', 90),
    ('JFK', 'LAX', 500),
]
Due to some improbably low flight prices, the cheapest itinerary would be JFK -> ATL -> ORD -> LAX, costing $440.
*****************************************************************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <climits>
using namespace std;

map<string,vector<pair<string,int>>> tickets;
int cheapest = INT_MAX;
string itinerary = "";

void addTicket(string src,string dest,int price){
    tickets[src].push_back({dest,price});
}

void findCheapestItr(int k,string src,string dest,int fair,string itr){
    if(k<=0 && src!=dest){
        return;
    }
    
    if(src==dest && fair<cheapest){
        cheapest = fair;
        itinerary = itr;
        return;
    }
    
    for(auto next:tickets[src]){
        findCheapestItr(k-1,next.first,dest,fair+next.second,itr+"->"+next.first);
    }
}

int main() {
    addTicket("JFK","ATL",150);
    addTicket("ATL","SFO",400);
    addTicket("ORD","LAX",200);
    addTicket("LAX","DFW",80);
    addTicket("JKF","HKG",800);
    addTicket("ATL","ORD",90);
    addTicket("JKF","LAX",500);
    int k = 3;
    string src = "JFK", dest = "LAX";
    findCheapestItr(k,src,dest,0,src);
    cout<<cheapest<<endl;
    cout<<itinerary<<endl;
	return 0;
}
