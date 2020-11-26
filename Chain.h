#include "Card.h"
#include <vector>

class Chain {
    public:
        Chain(): number(0) {}
        int numCards() {return number;} 
        void empty() {number = 0;}
        void newChain();
        void grow();
        // Card shrink();
        // Card lookIn(int no);
    private :
        vector<Card> chain;      // hold cards
        int number;             // number of card in deck
};

