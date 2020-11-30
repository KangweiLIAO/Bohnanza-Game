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
#include "CardFactory.h"
// #include "Chain.h"
#include "Hand.h"

using namespace std;

class Table;

class Player {
    private:
        int num_coins;
        int num_chains;
        const string player_name;
    public:
        // constructor:
        Player(const string& name) : player_name(name) {};
        // member functions:
        int play();
        void buyThirdChain();
        string getName();
        int getNumCoins();
        int getNumChains();
        void printHand(std::ostream&, bool);
        // operators:
        Player& operator+=(int);
        // Chain<class T>& operator[](int i);
        friend ostream& operator<<(ostream&,const Player&);
};

// int Player::play() {
    
// }

// int Player::getNumCoins() {
    
// }

#endif