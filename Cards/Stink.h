/**
 * File: Stink.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * @brief
 * A concrete derived card classes that instantiates from the template Chain Class.
 * 
 * Methods:
 * -int getCardsPerCoin(int)
 * -void print(ostream&) const
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

/**
 * @brief return the numbers of cards corresponding with the given numbers of coins
 * @param coins numbers of coins
*/
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

/**
 * @brief inserts the first character for the card to an std::ostream
 * @param out An ostream
*/
void Stink::print(ostream& out) const {
    out << name[0];
}

#endif