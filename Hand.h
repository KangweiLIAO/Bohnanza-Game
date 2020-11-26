#include "Card.h"
#include "Deck.h"
#include <list>
#include <queue>

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