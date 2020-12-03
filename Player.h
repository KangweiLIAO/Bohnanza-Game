/**
 * File: Player.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class includes 
 * 
 * Methods:
 * - Player(std::string&)
 * - Player(istream&, const CardFactory*)
 * - string getName()
 * - int getNumCoins()
 * - Player& operator+=(int)
 * - int getMaxNumChains()
 * - int getNumChains()
 * - Chain& operator[](int i)
 * - void buyThirdChain()
 * - void printHand(ostream&, bool)
 * - friend ostream& operator<<(ostream&,const Player&)
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

/**
 * @brief A constructor which accepts an istream and reconstruct the Player from file.
 * @param is An istream address
 * @param factory A const CardFactory
*/
Player::Player(istream& is, const CardFactory* factory){

}

/**
 * @brief Get the name of the player
*/
string Player::getName(){return player_name;}

/**
 * @brief 
*/
int Player::play(){}

/**
 * @brief
*/
void Player::buyThirdChain(){}

/**
 * @brief Get the number of coins currently held by the player.
*/
int Player::getNumCoins(){return num_coins;}

/**
 * @brief Get the number of chains currently held by the player.
*/
int Player::getNumChains(){return num_chains;}

/**
 * @brief Prints the top card of the player's hand (with argument false) 
 * or all of the player's hand (with argument true) to the supplied ostream.
 * @param os An ostream
 * @param flag a boolean
*/
void Player::printHand(ostream& os, bool flag){}

/**
 * @brief add a number of coins
 * @param coins numbers of coins need to be added
*/
inline Player& operator+=(int coins){num_coins = num_coins + coins;}

/**
 * @brief Insert player to an std::ostream.
 * @param os An ostream
 * @param tradeArea A player needs to be printed
*/
inline ostream& operator<< (ostream& os, const Player& player) {}
#endif