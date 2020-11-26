/*
Group 8:
Teammates:  Kangwei Liao: 8568800
            Langqing Zou: 300035036
*/

/*********** File : "Main.h" **********/
#include "Deck.h"
#include "Hand.h"

class Player{
    public:
        Player(Deck& deck): packet(deck) {}
        int play();
    private:
        Deck inHand;
        Deck& packet;
        int countCoins();
};

int Player::play() {
    
}

int Player::countCoins() {
    
}