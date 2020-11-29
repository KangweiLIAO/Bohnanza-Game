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
    if (coins < 1) return 0;
    if (coins > 4) return -1;
    else switch (coins) {
        case 1: return 4;
        case 2: return 6;
        case 3: return 8;
        case 4: return 10;
        default: return -1;
    }
}

void Black::print(ostream& out) const {
    out << name[0];
}

#endif