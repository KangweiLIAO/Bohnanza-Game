/**
 * File: Card.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef CARD_H
#define CARD_H

// std libraries:
#include <iostream>

// project headers:

using namespace std;

class Card {
    protected:
        string name;
        virtual void print(ostream&) const = 0;
    public:
        Card(string name) : name(name) {};
        virtual ~Card(){};
        Card (const Card&) = delete;
        string getName() {return name;}
        virtual int getCardsPerCoin(int coins) = 0;
        friend ostream& operator<< (ostream& os, const Card& card);
        // operators:
        Card& operator= (const Card&) = delete;
};

inline ostream& operator<< (std::ostream& os, const Card& card)
{
  card.print(os);
  return os;
}

#endif