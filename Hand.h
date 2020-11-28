/**
 * File: Hand.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

// std libraries:
#include <list>
#include <queue>
// project headers:
#include "Card.h"

using namespace std;

class Hand {
    public:
        Hand(): number(0) {}
        int numCards() {return number;} 
        void empty() {number = 0;}
        void newHand(Deck&);
        void shuffle();
        Card take();
        Card lookIn(int no);
    private:
        queue<Card> hand;      // hold cards
        int number;             // number of card in deck
}