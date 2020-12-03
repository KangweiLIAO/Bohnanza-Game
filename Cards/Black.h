/**
 * File: Black.h
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

#ifndef BLACK_H
#define BLACK_H
#include "Card.h"

using namespace std;

class Black : public Card {
    public:
        Black() : Card("black") {};
        virtual int getCardsPerCoin(int coins);
    protected:
        virtual void print(ostream& out) const;
};

/**
 * @brief return the numbers of cards corresponding with the given numbers of coins
 * @param coins numbers of coins
*/
int Black::getCardsPerCoin(int coins) {
    switch (coins) {
        case 0: return 0;
        case 1: return 2;
        case 2: return 4;
        case 3: return 5;
        case 4: return 6;
        default: return -1;
    }
}

/**
 * @brief inserts the first character for the card to an std::ostream
 * @param out An ostream
*/
void Black::print(ostream& out) const {
    out << name[0];
}

#endif