/**************************************************************************************************************************************
cons(a, b) constructs a pair, and car(pair) and cdr(pair) 
returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
Given this implementation of cons:
def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
****************************************************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

struct pairr{
    int first;
    int second;
};



int cdr(struct pairr p){
    return p.second;
}

int car(struct pairr p){
    return p.first;
    }

struct pairr cons(int a, int b){
    struct pairr p;
    p.first = a;
    p.second = b;
    return p;
    }

int main(){
    cout<<cdr(cons(3,4)); //output : 4
    cout<<car(cons(6,7)); //output : 6
}
