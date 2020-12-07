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
#include "DiscardPile.h"
#include "ReadInput.h"
#include "Chain.h"
#include "Hand.h"

using namespace std;

class Player {
    private:
        Hand* hand;
        int num_coins;
        int max_chain;
        const string name;
        vector<Chain_Base*> chains;
        void sellChain();
    public:
        // constructors
        Player(const string&);
        Player(istream&, const CardFactory*);
        // member functions
        void play();
        void buyThirdChain();
        bool cardMatch(Card*);
        void addCardToHand(Card*);
        Chain_Base* createChain(Card*);
        void discardHand(DiscardPile*);
        
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
    this->max_chain = 2;
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
    }
}

/**
 * @brief Get the name of the player
 * @return the name of player
*/
inline string Player::getName() {return name;}

/**
 * @brief Get the number of coins currently held by the player.
 * @return number of coins
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
inline void Player::addCardToHand(Card* card){*hand += card;}

/**
 * @brief Prompt user to discard a card to discard pile
 * @param pile a pile
*/
void Player::discardHand(DiscardPile* pile) {
    if (hand->size() == 0){
        cout << this->name << " don't have any card in hand." << endl;
        return;
    }
    cout << *hand << endl;
    string* card_num = new string("0");
    while (stoi(*card_num) < 1 || stoi(*card_num) > (*hand).size())
        readString("("+this->name+")Please enter a card number to discard (1-N): ", card_num);
    *pile += (*hand)[stoi(*card_num)-1];
    cout << this->name << " popped " << *card_num << " from the hand." << endl;
}

/**
 * @brief Try match the card with a existed chain and add to it.
 * @param card a specific card
 * @return true if a chain matched, false otherwise
*/
inline bool Player::cardMatch(Card* card) {
    for(auto& chain: chains)
        if(chain->match(card)) return true;
    return false;
}

/**
 * @brief Adds an empty third chain to the player for three coins. 
 *        The functions reduces the coin count for the player by two. 
 *        If the player does not have enough coins then an exception NotEnoughCoins is thrown.
 * @param card A card that needed to be added to the new chain
*/
void Player::buyThirdChain(){
    if (chains.size()+1 > max_chain) throw MaxChainReachedException();
    if (num_coins >= 3) {
        num_coins -= 3;
        max_chain++;
    } else throw NotEnoughCoinsException();
}

/**
 * @brief Prompt player to sell a chain
 * @return true if the chain is sold, false otherwise
*/
void Player::sellChain(){
    string* chain_num = new string("0");
    int count = 1;
    for(auto& chain: chains)
        cout << count++ << ": " << *chain << endl;
    while (!(stoi(*chain_num) > 0 && stoi(*chain_num) <= chains.size())) {
        readString("Please enter a chain number to sell (1-3): ", chain_num);
    }
    char chain_name = chains[stoi(*chain_num)-1]->getName();
    *this += chains[stoi(*chain_num)-1]->sell();        // add coins to player
    chains.erase(chains.begin()+stoi(*chain_num)-1);    // remove the chain just sold
    cout << "(" << this->name << ") " << chain_name << " Chain sold successfully." << endl;
}

/**
 * @brief play the topmost card in hand
 * @return topmost card in hand
*/
void Player::play(){
    if (hand->size() == 0){
        cout << this->name << " don't have any card in hand." << endl;
        return;
    }
    Card* card = hand->play();  // play the topmost card from hand
    cout << endl << this->name << " played topmost card in hand: " << *card << endl;
    if (!this->cardMatch(card)) {
        string* buff = new string();
        readString("("+this->name+") This card mismatched, do you want to create a new chain for this card? (y/n): ", buff);
        switch (chains.size()) {
        case 3:
            cout << "Currently "<< this->name <<" have 3 chains, but no one matched this card." << endl;
            this->sellChain();
            this->createChain(card);    // add the mismatched card to a new chain
            cout << "The mismatched card added to a new chain." << endl;
            break;
        case 2:
            if (num_coins >= 3) {
                // player has more than 3 coins
                if(*buff=="y") {
                    // player choose to buy a third chain
                    this->buyThirdChain();
                    this->createChain(card);
                    cout << "(" << this->name << ") Third chain created with the card added to it." << endl;
                }
            } else {
                // player has less than 3 coins
                cout << this->name << " have less than 3 coins and all 2 chains mismatched." << endl;
                this->sellChain();
            }
            break;
        case 1:
            // player has only 1 chain
            if(*buff=="y") {
                // player choose to create a second chain
                this->createChain(card);
                cout << "(" << this->name << ") Second chain created with the card added to it." << endl;
            } else {
                // player choose to sell a chain
                cout << "(" << this->name << ") Don't want to create a new chain? OK!" << endl;
                this->sellChain();
            }
            break;
        default:
            // player do not have a chain
            this->createChain(card);
            cout << this->name << "'s first chain created with the card added to it." << endl;
            break;
        }
    } else cout << "(" << this->name << ") " << *card << " added to a chain." << endl;
}

/**
 * @brief Create new chain which type is base on a card and add the card to it.
 * @param card A card that indicating the type of new chain
 * @return Returns nullptr if cannot create more chains, else return new chain pointer
*/
Chain_Base* Player::createChain(Card* card) {
    if (chains.size()+1 > max_chain) {
        cout << this->name << "'s maximum number of chain reached!" << endl;
        return nullptr;
    }
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
        for(auto& chain: player.chains) os << *chain << endl;   // call Chain_Base::operator<<()
    }
    return os;
}

#endif