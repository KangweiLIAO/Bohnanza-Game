/**
 * File: Chain.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
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
        Chain(istream& is, const CardFactory* f) {};
        int sell();
        Chain<T>& operator+=(Card* card);
        friend ostream& operator<< (ostream& os,const Chain& ch);

};

template <class T> int Chain<T>::sell () { 
    T bean;
    Chain ch;
    int coins;
    for(int i=0; i<5; i++)){
        coins = bean.getCardsPerCoin(i)
        if (ch.num_cards>coins){
            i++;
            break;
        }
    }
    return coins;
}

template <class T> Chain<T>& Chain<T>::operator+=(Card* card){
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