/**
 * @file: DiscardPile.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class holds the discard pile for a table. DiscardPile support insertion and removal 
 * but not at random locations but all at the end.
 * 
 * Methods:
 *  - DiscardPile(istream&, const CardFactory*) 
 *      a constructor which accepts an istream and reconstructs the DiscardPile from file.
 *  - DiscardPile& operator+=(Card*)
 *      discards the card to the pile.
 *  - Card* pickUp()
 *      returns and removes the top card from the discard pile.
 *  - Card* top()
 *      returns but does not remove the top card from the discard pile.
 *  - void print(std::ostream&)
 *      insert all the cards in the DiscardPile to an std::ostream.
 *  - friend ostream& operator<< (ostream&, const DiscardPile&)
 *      insert only the top card of the discard pile to an std::ostream.
 */

#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

// std libraries:
#include <vector>
// project headers:
#include "Table.h"

using namespace std;

class DiscardPile {
    private:
        vector<Card*> pile;      // hold discarded cards
        const CardFactory* factory;
    public:
        // constructors:
        DiscardPile() {};
        DiscardPile(istream&, const CardFactory*);
        // member functions:
        Card* top() const {return pile.back();}
        Card* pickUp();
        void print(ostream&);
        // operators:
        DiscardPile& operator+=(Card*);
        friend ostream& operator<< (ostream&, const Hand&);
};

inline Card* DiscardPile::pickUp() {
    Card* c = pile.back();  // top card == last elem
    pile.pop_back();
    return c;
}


void DiscardPile::print(ostream& os) {
    const int size = pile.size();
    for (int i=0; i<size; i++) {
        os << *pile[i] << " ";
    }
}

inline DiscardPile& DiscardPile::operator+= (Card* card) {
    pile.push_back(card);
    return *this;
}

inline ostream& operator<< (ostream& os, const DiscardPile& pile) {
    const Card* c = pile.top();
    os << *c;
    return os;
}

#endif
