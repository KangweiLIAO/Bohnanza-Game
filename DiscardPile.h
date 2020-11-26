/*
Group 8:
Teammates:  Kangwei Liao: 8568800
            Langqing Zou: 300035036
*/

/*********** File : "DiscardPile.h" **********/
#include "Card.h"
#include <vector>

class DiscardPile {
    public:
        DiscardPile(): number(0) {}
        int numCards() {return number;} 
        void empty() {number = 0;}
        void newPile();
        void shuffle();
        void put();
        // Card take();
        // Card lookIn(int no);
    private :
        vector<Card> pile;      // hold cards
        int number;             // number of card in pile
};

