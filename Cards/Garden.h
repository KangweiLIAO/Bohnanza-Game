/**
 * @file: Garden.h
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

/**
 * @brief Return the numbers of cards corresponding with the given numbers of coins
 * @param coins Numbers of coins
*/
inline int Garden::getCardsPerCoin(int coins) {
    switch (coins) {
        case 2: return 2;
        case 3: return 3;
        default: return 0;
    }
}

/**
 * @brief Inserts the first character for the card to an std::ostream
 * @param out An ostream
*/
void Garden::print(ostream& os) const {
    os << name[0];
}
#endif