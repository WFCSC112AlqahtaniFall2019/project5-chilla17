#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int compValue, userValue, nWin = 0, nLoss = 0, nTie = 0;
    srand(time(NULL));

    Deck unused; // cards left in the pile
    Deck used; // cards taked from the pile
    int cardsPulled= 0; // keep track of cards pulled from deck

    unused.setDeck(); // populate deck with unused cardws
    unused.shuffle(); // shuffle deck

    play = true;
    while(play) {
        // assign values to computer and user
        Card compValue = unused.remove();
        Card userValue = unused.remove();
        cardsPulled +=2; // +2 cards pulled from deck


        // get user's bet
        cout << "Computer's value is " << compValue.cardString() << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if((compValue < userValue && guessedHigher) || (userValue<compValue   && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if(( userValue<compValue  && guessedHigher) || (compValue < userValue && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
         cout<<userValue.cardString()<<endl;

        if(cardsPulled == 52) { // checks to see if all 52 cards have been pulled
            cout << "No cards left in the deck! End game." << endl;

            // output stats
            cout << "Thanks for playing!" << endl;
            cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;
        }

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                used.add(compValue); // put computer card into used card pile
                used.add(userValue); // put user card into used card pile
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                used.add(compValue); // put computer card into used card pile
                used.add(userValue); // put user card into used card pile
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;

    return 0;
}