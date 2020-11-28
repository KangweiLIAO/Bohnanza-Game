/**
 * File: DiscardPile.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

// std libraries:
#include <vector>
// project headers:
#include "Card.h"

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
