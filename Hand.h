/**
 * File: Hand.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * Description:
 * This class holds the hand of a player.
 * 
 * Methods:
 *  - Hand(istream&, const CardFactory*)
 *      a constructor which accepts an istream and reconstruct the Hand from file.
 *  - Hand& operator+=(Card*)
 *      adds the card to the rear of the hand.
 *  - Card* play()
 *      returns and removes the top card from the player's hand.
 *  - Card* top()
 *      returns but does not remove the top card from the player's hand.
 *  - Card* operator[](int)
 *      returns and removes the Card at a given index.
 *  - friend ostream& operator<< (ostream&, const Hand&)
 *      insertion operator (friend) to print Hand on an std::ostream.
 */

#ifndef HAND_H
#define HAND_H

// std libraries:
#include <list>
#include <queue>
// project headers:
#include "Player.h"

using namespace std;

class Player;

class Hand {
    private:
        queue<Card*,list<Card*> > hand;   // list with queue adapter 
    public:
        // constructor:
        Hand() {};
        Hand(istream&, const CardFactory*);
        // member functions:
        Card* play();
        Card* top() {return hand.front();}
        int size() const {return hand.size();}
        // operators:
        Card* operator[] (int);
        Hand& operator+= (Card* card) {
            hand.push(card);
            return *this;
        }
        friend ostream& operator<< (ostream&, const Hand&);
};

// TODO: Read from istream and reconstruct player's hand
// Hand::Hand(istream&, const CardFactory*) {}

/**
 * Pop and return the top card in hand
 * @return a pointer to the card just popped
 */
Card* Hand::play() {
    Card* card = hand.front();
    hand.pop();
    return card;
}

/**
 * Return the top card at specified index
 * @param i index for a card in hand
 * @return a pointer to the card at index i
 */
Card* Hand::operator[] (int i) {
    int count = 0;
    Card* buffC = NULL;
    queue<Card*,list<Card*> > buff;
    buff.swap(hand);
    while (!buff.empty()) {
        Card* c = buff.front();
        if(count == i) buffC = c;
        buff.pop();
        hand.push(c);
        count++;
    }
    if (buffC == NULL) throw CardNotFoundException();
    return buffC;
}

/**
 * Insert hand into ostream
 * @return ostream with hand inserted
 */
inline ostream& operator<< (ostream& os, Hand& h) {
    const int size = h.size();
    for (int i=0; i<size; i++) {
        os << *h[i] << " ";     // card at position i
    }
    return os;
}

#endif