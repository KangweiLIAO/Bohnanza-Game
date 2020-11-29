/**
 * File: Hand.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef HAND_H
#define HAND_H

// std libraries:
#include <list>
#include <queue>
// project headers:

using namespace std;

class Hand {
    private:
        queue<Card> hand;      // hold cards
        int number;             // number of card in deck
    public:
        // constructor:
        Hand(istream&, const CardFactory*);
        // member functions:
        Card* play();
        Card* top();
        // operators:
        Hand& operator+=(Card*);
};

#endif