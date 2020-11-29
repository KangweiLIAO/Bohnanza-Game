/**
 * File: CardFactory.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef CARDFACTORY_H
#define CARDFACTORY_H
// std libraries:

// project headers:
#include "Cards/Cards.h"
#include "Deck.h"

using namespace std;

class CardFactory{
    public:
        CardFactory();
    private:
        static CardFactory* getFactory();
};

#endif