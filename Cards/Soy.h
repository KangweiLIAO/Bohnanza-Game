/**
 * File: Soy.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef SOY_H
#define SOY_H
#include "Card.h"

class Soy : public Card {
    public:
        Soy() : Card("soy") {};
        virtual int getCardsPerCoin(int coins);
    protected:
        virtual void print(ostream& out) const;
};

int Soy::getCardsPerCoin(int coins) {
    switch (coins) {
        case 0: return 0;
        case 1: return 2;
        case 2: return 4;
        case 3: return 6;
        case 4: return 7;
        default: return -1;
    }
}

void Soy::print(ostream& out) const {
    out << name[0];
}
#endif