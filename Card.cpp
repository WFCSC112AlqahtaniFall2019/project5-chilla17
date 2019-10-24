#include "Card.h"
// #include <iostream>
#include <string>
using namespace std;

// default constructor
Card::Card(){
    rankNum = 0;
    suitNum = 0;
}

// constructor
Card::Card(int rank, int suit) {
    rankNum = rank;
    suitNum = suit;
}

bool Card::operator<(Card comp) {
    if (this -> rankNum < comp.rankNum) {
        return true;
    }
    else if (this -> rankNum > comp.rankNum) {
        return false;
    }
    else if (this -> rankNum == comp.rankNum) {
        return true;
    }
    else {
        return false;
    }
}

string Card::cardString(){
    card = ranks[rankNum] + " of " + suits[suitNum];
    return card;
}