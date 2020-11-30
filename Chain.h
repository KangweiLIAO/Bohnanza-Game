/**
 * File: Chain.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * Description:
 * This class is a derived class of {Chain_Base} and holds the chains of a player.
 * 
 * Methods:
 *  - Chain(istream&, const CardFactory*)
 *      a constructor which accepts an istream and reconstructs the chain from file when a game is resumed.
 *  - Chain<T>& operator+=(Card*)
 *      adds a card to the Chain. If the run-time type does not match the template type of the chain and 
 *      exception of type IllegalType will be raised.
 *  - Card* play()
 *      returns and removes the top card from the player's hand.
 *  - int sell()
 *      counts the number cards in the current chain and returns the number coins according to the function 
 *      {{Card::getCardsPerCoin}}.
 *  - Card* operator[](int)
 *      returns and removes the Card at a given index.
 *  - friend ostream& operator<< (ostream&, const Chain&)
 *      insertion operator (friend) to print a start column with the full name of the bean on an ostream
 */

#ifndef CHAIN_H
#define CHAIN_H
#include "Chain_Base.h"

// std libraries:
#include <vector>
// project headers:
#include "Chain_Base.h"

using namespace std;

template <class T> 
class Chain : public Chain_Base {
    private:
        int num_cards;
        string name;
        int position;
        vector<Card> chain;
    public:
        Chain() {};
        Chain(istream& is, const CardFactory* f) {};
        int sell();
        Chain<T>& operator+=(Card* card);
        friend ostream& operator<< (ostream& os,const Chain& ch);

};

template <class T> int Chain<T>::sell () { 
    T bean;
    Chain ch;
    int coins = -1;
    for(int i=0; i<5; i++)){
        coins = bean.getCardsPerCoin(i)
        if (ch.num_cards>coins){
            i++;
            break;
        }
    }
    return coins;
}

template <class T> Chain<T>& Chain<T>::operator+= (Card* card){
    try{
        //compare the type of card and this chain
        if (card.getName()==chain.name){
            chain.push_back(card);
        }else{
            throw (-1)
        }
    }
    catch(-1){
        cout<<"IllegalType"<<endl;
    }
}

template <class T> ostream& operator<< (std::ostream& os,const Chain<T>& ch){
    for(int i=0; i<ch.size(); i++){
        ch[i].print(os); //call the function: print() in Card.h
    }
}

#endif