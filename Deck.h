#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {
public:
    Deck();
    Deck(const Deck& card);
    ~Deck();
    Deck& operator=(const Deck& deck);
    void setDeck();
    void shuffle();
    Card remove();
    bool add(Card c);


private:
    Card* cards;
    int arraySize;
    int cardsLeft;
    int current;
};


#endif //BLINDMANSBLUFF_DECK_H
