/**
 * @file: Blue.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * A concrete derived card class that instantiates from the template Chain Class.
 * 
 * Methods:
 * -int getCardsPerCoin(int)
 * -void print(ostream&) const
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

/**
 * @brief Return the numbers of cards corresponding with the given numbers of coins
 * @param coins Numbers of coins
*/
inline int Blue::getCardsPerCoin(int coins) {
    switch (coins) {
        case 1: return 4;
        case 2: return 6;
        case 3: return 8;
        case 4: return 10;
        default: return 0;
    }
}

/**
 * @brief Inserts the first character for the card to an std::ostream
 * @param out An ostream
*/
void Blue::print(ostream& os) const {
    os << name[0];
}


#endif