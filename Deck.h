/**
 * File: Deck.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef DECK_H
#define DECK_H

// std libraries:
#include <vector>
// project headers:
#include "CardFactory.h"
#include "MyException.h"

using namespace std;

class CardFactory;

class Deck : public vector<Card*> {
    private:
        static vector<Card*> deck;
        const CardFactory* factory; 
    public:
        Deck() : vector<Card*>::vector(0) {};
        Deck(istream& is, const CardFactory* f):factory(f) {};
        int numCards() {return this->size();}
        Card* draw();
        friend ostream& operator<< (ostream& os, const Deck& deck);
};

Card* Deck::draw() {
    // If card not found, throw:
    if (this->size() == 0) throw DeckEmptyException();
    else this->pop_back();  // top card == last elem of the vector
}

inline ostream& operator<< (ostream& os, const Deck& deck) {
    // insert all cards to ostream
    const int size = deck.size();
    for (int i=0; i<size; i++) {
        os << *deck[i] << " ";
    }
    return os;
}

#endif