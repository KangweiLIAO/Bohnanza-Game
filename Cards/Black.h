/**
 * File: Black.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef BLACK_H
#define BLACK_H
#include "Card.h"

using namespace std;

class Black : public Card {
    public:
        Black() : Card("black") {};
        virtual int getCardsPerCoin(int coins);
    protected:
        virtual void print(ostream& out) const;
};

int Black::getCardsPerCoin(int coins) {
    switch (coins) {
        case 0: return 0;
        case 1: return 2;
        case 2: return 4;
        case 3: return 5;
        case 4: return 6;
        default: return -1;
    }
}

void Black::print(ostream& out) const {
    out << name[0];
}

#endif