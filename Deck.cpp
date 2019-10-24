#include "Deck.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor
Deck::Deck(){
    arraySize = 52;
    cards = new Card[arraySize];
    cardsLeft = 52;
    current = 0;
}

// copy constructor
Deck::Deck(const Deck& deckCopy) {
    arraySize = deckCopy.arraySize;
    cards = new Card[arraySize];
    for (int i = 0; i < arraySize; i++) {
        cards[i] = deckCopy.cards[i];
    }
    current = deckCopy.current;
    cardsLeft = deckCopy.cardsLeft;
}

// destructor
Deck::~Deck() {
    delete [] cards;
}

// copy assignment operator !! BIG THREE BABY
Deck& Deck::operator=(const Deck& deck) {
    Deck temp(deck);
    this-> arraySize = temp.arraySize; // do not need to create a deep copy here, shallow copy will suffice
    this-> cardsLeft = temp.cardsLeft;
    this-> current = temp.current;
    swap(cards, temp.cards);
    return* this;
}

// populate array with 52 cards
void Deck::setDeck(){
    int p = 0;
    for (int i = 0; i < 4; i++){ // four suits
        for (int j = 0; j < 13; j++){ // thirteen per suit
            Card card = Card(j, i);
            cards[p] = Card(j, i);
            p++;
        }
    }
}

void Deck::shuffle(){
    srand(time(NULL));
    int shuffle = cardsLeft * cardsLeft;
    for (int i = 0; i < shuffle; i++) {
        int randA = rand() % cardsLeft;
        int randB = rand() % cardsLeft;
        Card temp = cards[randA];
        cards[randA] = cards[randB];
        cards[randB] = temp;
    }
}

Card Deck::remove() {
    if (current < arraySize) {
        cardsLeft--;
        return cards[current++];
    }
    else {
        cout << "There are no more cards in the deck." << endl;
        return cards[current];
    }
}

bool Deck::add(Card c) {
    if (cardsLeft == 0) {
        cout << " There is no space to return card." << endl;
        return false;
    }
    else {
        cards[current]  = c;
        current++;
        return true;
    }
}