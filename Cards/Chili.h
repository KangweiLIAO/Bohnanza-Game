/**
 * File: Chili.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef CHILI_H
#define CHILI_H
#include "Card.h"
class Chili : public Card {
    public:
        Chili() : Card("Chili") {};
        virtual int getCardsPerCoin(int coins);
    protected:
        virtual void print(ostream& out) const;
};

int Chili::getCardsPerCoin(int coins) {
    switch (coins) {
        case 0: return 0;
        case 1: return 3;
        case 2: return 6;
        case 3: return 8;
        case 4: return 9;
        default: return -1;
    }
}

void Chili::print(ostream& out) const {
    out << name[0];
}

#endif