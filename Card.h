/**
 * File: Card.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <cassert> //for assert()

using namespace std;

class Card {
    private:
        string name;
    public:
        string getName() {return name;}
        // Pure virtual functions:
        virtual int getCardsPerCoin(int coins) = 0;
        virtual void print(ostream& out) = 0;
};

#endif