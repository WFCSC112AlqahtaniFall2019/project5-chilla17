#ifndef BLINDMANSBLUFF_CARD_H
#define BLINDMANSBLUFF_CARD_H
#include <string>
using namespace std;

// ranks are ordered Ace-low and Queen-high
const string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","King","Queen"};
// suits are ordered alphabetically
const string suits[] = {"Clubs","Diamonds","Hearts","Spades"};

class Card {
public:
    Card(); // default constructor
    Card(int rank, int suit); // constructor
    bool operator<(Card comp);
    string cardString();

private:
    int rankNum;
    int suitNum;
    string card;
};


#endif //BLINDMANSBLUFF_CARD_H
