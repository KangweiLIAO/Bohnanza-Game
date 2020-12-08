/**
 * @file: Black.h
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

#ifndef BLACK_H
#define BLACK_H
#include "Card.h"

class Black : public Card {
    public:
        Black() : Card("black") {};
        int getCardsPerCoin(int coins);
    protected:
        void print(ostream&) const;
};

/**
 * @brief Return the numbers of cards corresponding with the given numbers of coins
 * @param coins Numbers of coins
*/
inline int Black::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 2;
        case 2: return 4;
        case 3: return 5;
        case 4: return 6;
        default: return 0;
    }
}

/**
 * @brief Inserts the first character for the card to an std::ostream
 * @param out An ostream
*/
void Black::print(ostream& os) const {
    os << name[0];
}

#endif