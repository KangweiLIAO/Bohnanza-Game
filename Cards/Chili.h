/**
 * @file: Chili.h
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

/**
 * @brief Return the numbers of cards corresponding with the given numbers of coins
 * @param coins Numbers of coins
*/
inline int Chili::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 3;
        case 2: return 6;
        case 3: return 8;
        case 4: return 9;
        default: return 0;
    }
}

/**
 * @brief Inserts the first character for the card to an std::ostream
 * @param out An ostream
*/
void Chili::print(ostream& os) const {
    os << name[0];
}

#endif