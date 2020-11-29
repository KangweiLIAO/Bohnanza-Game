/**
 * File: Green.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef GREEN_H
#define GREEN_H
#include "Card.h"

class Green : public Card {
    public:
        Green() : Card("Green") {};
        virtual int getCardsPerCoin(int coins);
    protected:
        virtual void print(ostream& out) const;
};

int Green::getCardsPerCoin(int coins) {
    switch (coins) {
        case 0: return 0;
        case 1: return 3;
        case 2: return 5;
        case 3: return 6;
        case 4: return 7;
        default: return -1;
    }
}

void Green::print(ostream& out) const {
    out << name[0];
}

#endif