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
#include<sstream> 
// project headers:
#include "Chain.h"
#include "hand->h"

using namespace std;

class Player {
    private:
        Hand* hand;
        int num_coins;
        const string name;
        vector<Chain_Base*> chains;
    public:
        // constructors
        Player(const string&);
        Player(istream&, const CardFactory*);
        // member functions
        void buyThirdChain(Card*);
        Chain_Base* createChain(Card*);
        bool chainMatch(Card*);
        Hand* getHand();
        string getName();
        int getNumCoins();
        int getNumChains();
        void printHand(ostream&, bool);
        // operators
        Player& operator+= (int);
        Chain_Base& operator[] (int);
        friend ostream& operator<< (ostream&,const Player&);
};

/**
 * @brief A constructor which accepts new player's name to create a new player in the game.
 * @param name Name of the new player
*/
inline Player::Player(const string& name) : name(name) {
    num_coins = 0;
    hand = new Hand();
}

/**
 * @brief A constructor which accepts an istream and reconstruct the Player from file.
 * @param is An istream address
 * @param factory A const CardFactory
*/
Player::Player(istream& is, const CardFactory* factory){
    Deck deck = factory->getFactory()->getDeck();
    string line,s;
    while(getline(is,line)){
        auto delimiterPos = line.find("=");
        auto name = line.substr(0, delimiterPos);
        auto value = line.substr(delimiterPos + 1);

        if(name=="name"){
            name=value;
        }
        if(name=="coin"){
            num_coins=stol(value);
        }
        if(name=="hand"){
            string s;
            vector<string> res; //save for each word
            stringstream input(value);
            while(input>>s){
                res.push_back(s);
            }
            for(int i=0;i<res.size();i++){
                if(res[i]=="R"){
                    hand->operator+=(new Red());
                }else if(res[i]=="C"){
                    hand->operator+=(new Chili());
                }else if(res[i]=="G"){
                    hand->operator+=(new Green());
                }else if(res[i]=="B"){
                    hand->operator+=(new Blue());
                }else if(res[i]=="S"){
                    hand->operator+=(new Stink());
                }else if(res[i]=="g"){
                    hand->operator+=(new Garden());
                }else if(res[i]=="s"){
                    hand->operator+=(new Soy());
                }else if(res[i]=="b"){
                    hand->operator+=(new Black());
                }
            }
        }
        if(name=="chain1" || name=="chain2" || name=="chain3"){
            string s;
            vector<string> res; //save for each word
            stringstream input(value);
            while(input>>s){
                res.push_back(s);
            }
            if(res[0]=="R"){
                createChain(new Red());
                for(int i=0; i<stol(res[1])-1;i++){
                    chains.back()->operator+=(new Red());
                }
            }else if(res[0]=="C"){
                createChain(new Chili());
                for(int i=0; i<stol(res[1])-1;i++){
                    chains.back()->operator+=(new Chili());
                }
            }else if(res[0]=="G"){
                createChain(new Green());
                for(int i=0; i<stol(res[1])-1;i++){
                    chains.back()->operator+=(new Green());
                }
            }else if(res[0]=="B"){
                createChain(new Blue());
                for(int i=0; i<stol(res[1])-1;i++){
                    chains.back()->operator+=(new Blue());
                }
            }else if(res[0]=="S"){
                createChain(new Stink());
                for(int i=0; i<stol(res[1])-1;i++){
                    chains.back()->operator+=(new Stink());
                }
            }else if(res[0]=="g"){
                createChain(new Garden());
                for(int i=0; i<stol(res[1])-1;i++){
                    chains.back()->operator+=(new Garden());
                }
            }else if(res[0]=="s"){
                createChain(new Soy());
                for(int i=0; i<stol(res[1])-1;i++){
                    chains.back()->operator+=(new Soy());
                }
            }else if(res[0]=="b"){
                createChain(new Black());
                for(int i=0; i<stol(res[1])-1;i++){
                    chains.back()->operator+=(new Black());
                }
            }

        }
    }


}

/**
 * @brief Get the name of the player
 * @return the name of player
*/
inline string Player::getName() {return name;}

/**
 * @brief Get the number of coins currently held by the player.
 * @ return number of coins
*/
inline int Player::getNumCoins() {return num_coins;}

/**
 * @brief Get the number of chains currently held by the player.
 * @return number of chains
*/
inline int Player::getNumChains() {return chains.size();}

/**
 * @brief returns the hand object of the player
 * @return Hand of the player
*/
inline Hand* Player::getHand(){return hand;}


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
 * @brief Create new chain which type is base on a card and add the card to it.
 * @param card A card that indicating the type of new chain.
*/
Chain_Base* Player::createChain(Card* card) {
    string type = typeid(*card).name();     // get the card's type
    if (type == typeid(Black).name()) {
        Chain<Black>* chain = new Chain<Black>();
        *chain += card;
        chains.push_back(chain);
    }
    else if (type == typeid(Blue).name()) {
        Chain<Blue>* chain = new Chain<Blue>();
        *chain += card;
        chains.push_back(chain);
    }
    else if (type == typeid(Chili).name()) {
        Chain<Chili>* chain = new Chain<Chili>();
        *chain += card;
        chains.push_back(chain);
    }
    else if (type == typeid(Garden).name()) {
        Chain<Garden>* chain = new Chain<Garden>();
        *chain += card;
        chains.push_back(chain);
    }
    else if (type == typeid(Green).name()) {
        Chain<Green>* chain = new Chain<Green>();
        *chain += card;
        chains.push_back(chain);
    }
    else if (type == typeid(Red).name()) {
        Chain<Red>* chain = new Chain<Red>();
        *chain += card;
        chains.push_back(chain);
    }
    else if (type == typeid(Soy).name()) {
        Chain<Soy>* chain = new Chain<Soy>();
        *chain += card;
        chains.push_back(chain);
    }
    else {
        Chain<Stink>* chain = new Chain<Stink>();
        *chain += card;
        chains.push_back(chain);
    }
    return chains.back();
}

/**
 * @brief Try match the card with a existed chain and add to it.
 * @param card a specific card
*/
bool Player::chainMatch(Card* card) {
    for(auto& chain: chains) {
        if(chain->match(card)) return true;
    }
    return false;
}

/**
 * @brief Prints the top card of the player's hand (with argument false) 
 *        or all of the player's hand (with argument true) to the supplied ostream.
 * @param os An ostream
 * @param flag A boolean
*/
inline void Player::printHand(ostream& os, bool flag){
    if (!flag) os << hand->top();
    else os << hand;
}

/**
 * @brief Add a number of coins
 * @param coins Numbers of coins need to be added
*/
inline Player& Player::operator+= (int coins){
    num_coins += coins; 
    return *this;
}

/**
 * @brief Returns the chain at specific index
 * @param i index of a chain of this player
 * @return the chain at the index i
*/
inline Chain_Base& Player::operator[] (int i) {return *chains[i];}

/**
 * @brief Insert the player's name, the number of coins in the player's possession and 
 *        each of the chains (2 or 3, some possibly empty) to an std::ostream.
 * @param os An ostream
 * @param player A player needs to be printed
*/
ostream& operator<< (ostream& os, const Player& player) {
    os << player.name << "\t" << player.num_coins << " coins\n";
    if (player.chains.size() != 0) {
        for(auto& chain: player.chains) os << *chain;   // call Chain_Base::operator<<()
    }
    return os;
}

#endif