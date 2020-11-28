/**
 * File: CardFactory.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef CARDFACTORY_H
#define CARDFACTORY_H
#include "Deck.h"
#include "Hand.h"

using namespace std;

class CardFactory{
    public:
        CardFactory();
    private:
        static CardFactory* getFactory();
        Deck getDeck();
};

#endif