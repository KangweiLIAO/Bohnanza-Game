/**
 * File: Card.h
 * Group 8:
 *      Kangwei Liao: 8568800
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
        const string name;
        virtual void print(ostream&) const = 0;
    public:
        Card(string name) : name(name) {};  // constructor
        virtual ~Card(){};                  // destructor
        Card (const Card&) = delete;
        string getName() const {return name;}
        virtual int getCardsPerCoin(int coins) = 0;
        // operators:
        Card& operator= (const Card&) = delete;
        friend ostream& operator<< (ostream& os, const Card& card);
};

inline ostream& operator<< (ostream& os, const Card& card) {
  card.print(os);
  return os;
}

#endif