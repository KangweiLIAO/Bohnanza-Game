/**
 * @file: Hand.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class holds the hand of a player.
 * 
 * Methods:
 *  - Hand(istream&, const CardFactory*)
 *  - Hand& operator+=(Card*)
 *  - Card* play()
 *  - Card* top()
 *  - Card* operator[](int)
 *  - friend ostream& operator<< (ostream&, const Hand&)
 */

#ifndef HAND_H
#define HAND_H

// std libraries:
#include <list>
#include <queue>
// project headers:

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
        Card* top() {return hand.front();}  ///returns but does not remove the top card from the player's hand.
        int size() const {return hand.size();}
        // operators:
        Card* operator[] (int);
        ///adds the card to the rear of the hand.
        Hand& operator+= (Card*);
        friend ostream& operator<< (ostream&, const Hand&);
};

/**
 * @brief A constructor which accepts an istream and reconstruct the hand from file.
 * @param is An istream address
 * @param factory A const CardFactory
 */
Hand::Hand(istream& is, const CardFactory* factory){

}

/**
 * @brief Pop and return the top card in hand
 * @return A pointer to the card just popped
 */
Card* Hand::play() {
    Card* card = hand.front();
    hand.pop();
    return card;
}

/**
 * @brief Return the top card at specified index
 * @param i Index for a card in hand
 * @return  A pointer to the card at index i
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

inline Hand& Hand::operator+= (Card* card) {
    hand.push(card);
    return *this;
}

/**
 * @brief Insert hand into ostream
 * @param os An ostream
 * @param h A hand needs to be printed
 * @return Ostream with hand inserted
 */
ostream& operator<< (ostream& os, Hand& h) {
    const int size = h.size();
    for (int i=0; i<size; i++) {
        os << *h[i] << " ";     // card at position i
    }
    return os;
}

#endif