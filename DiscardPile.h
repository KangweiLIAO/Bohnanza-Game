/**
 * File: DiscardPile.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * Description:
 * This class holds the hand of a player.
 * 
 * Methods:
 *  - Hand(istream&, const CardFactory*)
 *      a constructor which accepts an istream and reconstruct the Hand from file.
 *  - Hand& operator+=(Card*)
 *      adds the card to the rear of the hand.
 *  - Card* play()
 *      returns and removes the top card from the player's hand.
 *  - Card* top()
 *      returns but does not remove the top card from the player's hand.
 *  - Card* operator[](int)
 *      returns and removes the Card at a given index.
 *  - friend ostream& operator<< (ostream&, const Hand&)
 *      insertion operator (friend) to print Hand on an std::ostream.
 */

#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

// std libraries:
#include <vector>
// project headers:
#include "Table.h"

using namespace std;

class DiscardPile {
    public:
        DiscardPile(istream&, const CardFactory*);
        Card* top();
        Card* pickUp();
        void print(std::ostream&);
        DiscardPile& operator+=(Card*);
    private:
        vector<Card> pile;      // hold cards
        int number;             // number of card in pile
};

#endif
