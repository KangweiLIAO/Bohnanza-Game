/**
 * File: Red.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef RED_H
#define RED_H
#include "Card.h"

class Red : public Card {
    public:
        Red() : Card("red") {};
        virtual int getCardsPerCoin(int coins);
    protected:
        virtual void print(ostream& out) const;
};

int Red::getCardsPerCoin(int coins) {
    switch (coins) {
        case 0: return 0;
        case 1: return 2;
        case 2: return 3;
        case 3: return 4;
        case 4: return 5;
        default: return -1;
    }
}

void Red::print(ostream& out) const {
    out << name[0];
}

#endif