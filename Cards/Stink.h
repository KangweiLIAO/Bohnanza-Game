/**
 * @file: Stink.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * A concrete derived card class that instantiates from the template Chain Class.
 * 
 * Methods:
 * - int getCardsPerCoin(int)
 * - void print(ostream&) const
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
 * @brief Return the numbers of cards corresponding with the given numbers of coins
 * @param coins Numbers of coins
*/
inline int Stink::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 3;
        case 2: return 5;
        case 3: return 7;
        case 4: return 8;
        default: return 0;
    }
}

/**
 * @brief Inserts the first character for the card to an std::ostream
 * @param out An ostream
*/
void Stink::print(ostream& os) const {
    os << name[0];
}

#endif