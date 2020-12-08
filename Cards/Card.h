/**
 * @file: Card.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class is an abstract base class and includes some importnat operations.
 * 
 * Methods:
 * - virtual int getCardsPerCoin(int)
 * - virtual string getName()
 * - virtual void print(ostream&)
 * - string getName()
 * - ard& operator= (const Card&)
 * - friend ostream& operator<< (ostream&, const Card&)
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
        virtual int getCardsPerCoin(int) = 0; ///Return the numbers of cards corresponding with the given numbers of coins
        // operators:
        Card& operator= (const Card&) = delete;
        friend ostream& operator<< (ostream&, const Card&);
};

/**
 * @brief Insert the first character of the cards into an std::ostream.
 * @param os An ostream
 * @param card A card needs to be printed
*/
ostream& operator<< (ostream& os, const Card& card) {
  card.print(os);
  return os;
}

#endif