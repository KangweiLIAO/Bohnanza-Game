/**
 * @file Player.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class holds the player's operations 
 * 
 * Methods:
 * - Player(std::string&)
 * - Player(istream&, const CardFactory*)
 * - string getName()
 * - int getNumCoins()
 * - Player& operator+=(int)
 * - int getMaxNumChains()
 * - int getNumChains()
 * - Chain<T>& operator[](int i)
 * - void buyThirdChain()
 * - void printHand(ostream&, bool)
 * - friend ostream& operator<<(ostream&,const Player&)
 */

#ifndef PLAYER_H
#define PLAYER_H

// std libraries:

// project headers:
#include "CardFactory.h"
#include "Chain.h"
#include "Hand.h"

using namespace std;

class Player {
    private:
        Hand hand;
        int num_coins;
        int num_chains;
        const string name;
        vector<Chain_Base*> chains;
    public:
        // constructors
        Player(const string& name) : name(name) {};
        Player(istream&, const CardFactory*);
        // member functions
        void buyThirdChain(Card*);
        Chain_Base* createChain(Card*);
        string getName();
        int getNumCoins();
        int getNumChains();
        void printHand(ostream&, bool);
        // operators
        Player& operator+=(int);
        template <class T> Chain<T>& operator[](int);
        friend ostream& operator<<(ostream&,const Player&);
};

inline Player::Player(const string& name) : name(name) {
    num_coins = 0, num_chains = 0;
}

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
inline string Player::getName() {return name;}

/**
 * @brief Get the number of coins currently held by the player.
*/
inline int Player::getNumCoins() {return num_coins;}

/**
 * @brief Get the number of chains currently held by the player.
*/
inline int Player::getNumChains() {return num_chains;}

/**
 * @brief Adds an empty third chain to the player for three coins. 
 *        The functions reduces the coin count for the player by two. 
 *        If the player does not have enough coins then an exception NotEnoughCoins is thrown.
 * @param card A card that needed to be added to the new chain
*/
void Player::buyThirdChain(Card* card){
    if (num_coins >= 3) {
        num_coins -= 3;
        this->createChain(card);
    } else throw NotEnoughCoinsException();
}

/**
 * @brief Create new chain which type is base on a card, but did not add the card to it.
 * @param card A card that indicating the type of new chain.
*/
Chain_Base* Player::createChain(Card* card) {
    string type = typeid(*card).name();     // get the card's type
    if (type == typeid(Black).name()) chains.push_back(new Chain<Black>());
    else if (type == typeid(Blue).name()) chains.push_back(new Chain<Blue>());
    else if (type == typeid(Chili).name()) chains.push_back(new Chain<Chili>());
    else if (type == typeid(Garden).name()) chains.push_back(new Chain<Garden>());
    else if (type == typeid(Green).name()) chains.push_back(new Chain<Green>());
    else if (type == typeid(Red).name()) chains.push_back(new Chain<Red>());
    else if (type == typeid(Soy).name()) chains.push_back(new Chain<Soy>());
    else chains.push_back(new Chain<Stink*>());
    return chains.back();
}

/**
 * @brief Prints the top card of the player's hand (with argument false) 
 *        or all of the player's hand (with argument true) to the supplied ostream.
 * @param os An ostream
 * @param flag A boolean
*/
inline void Player::printHand(ostream& os, bool flag){
    if (!flag) os << hand.top();
    else os << hand;
}

/**
 * @brief Add a number of coins
 * @param coins Numbers of coins need to be added
*/
inline Player& Player::operator+= (int coins){
    num_coins+=coins; 
    return *this;
}

/**
 * @brief Returns the 
 * @param i index of a chain of this player
 * @return the chain at the index i
*/
template <class T>
inline Chain<T>& Player::operator[] (int i) {return *chains[i];}

/**
 * @brief Insert player to an std::ostream.
 * @param os An ostream
 * @param tradeArea A player needs to be printed
*/
ostream& operator<< (ostream& os, const Player& player) {
    return os;
}

#endif