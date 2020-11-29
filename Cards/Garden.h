/**
 * File: Garden.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef GARDEN_H
#define GARDEN_H
#include "Card.h"

class Garden : public Card {
    public:
        Garden() : Card("garden") {};
        virtual int getCardsPerCoin(int coins);
    protected:
        virtual void print(ostream& out) const;
};

int Garden::getCardsPerCoin(int coins) {
    switch (coins) {
        case 0: return 0;
        case 1: return -1;
        case 2: return 2;
        case 3: return 3;
        case 4: return -1;
        default: return -1;
    }
}

void Garden::print(ostream& out) const {
    out << name[0];
}
#endif