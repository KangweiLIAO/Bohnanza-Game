/**
 * File: Stink.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef STINK_H
#define STINK_H
#include "Card.h"

class Stink : public Card {
    public:
        Stink() : Card("Stink") {};
        virtual int getCardsPerCoin(int coins);
    protected:
        virtual void print(ostream& out) const;
};

int Stink::getCardsPerCoin(int coins) {
    switch (coins) {
        case 0: return 0;
        case 1: return 3;
        case 2: return 5;
        case 3: return 7;
        case 4: return 8;
        default: return -1;
    }
}

void Stink::print(ostream& out) const {
    out << name[0];
}

#endif