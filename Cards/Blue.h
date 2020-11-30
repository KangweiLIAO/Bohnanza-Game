/**
 * File: Blue.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 */

#ifndef BLUE_H
#define BLUE_H
#include "Card.h"

class Blue : public Card {
    public:
        Blue() : Card("Blue") {};
        virtual int getCardsPerCoin(int coins);
    protected:
        virtual void print(ostream& out) const;
};

int Blue::getCardsPerCoin(int coins) {
    switch (coins) {
        case 0: return 0;
        case 1: return 4;
        case 2: return 6;
        case 3: return 8;
        case 4: return 10;
        default: return -1;
    }
}

void Blue::print(ostream& out) const {
    out << name[0];
}


#endif