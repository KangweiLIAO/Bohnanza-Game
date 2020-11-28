/**
 * File: Player.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef PLAYER_H
#define PLAYER_H

// std libraries:

// project headers:
#include "Deck.h"
#include "Hand.h"

using namespace std;

class Player{
    private:
        int num_coins;
        int num_chains;
        string player_name;
    public:
        Player();
        int play();
        int countCoins();
        friend ostream& operator<<(ostream&,const Player&);
};

int Player::play() {
    
}

int Player::countCoins() {
    
}

#endif