/**
 * @file Chain.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class is a derived class of {Chain_Base} and holds the chains of a player.
 * 
 * Methods:
 *  - Chain(istream&, const CardFactory*)
 *  - int sell()
 *  - Chain<T>& operator+=(Card*)
 *  - size_t getSize()
 *  - friend ostream& operator<< (ostream&, const Chain&)
 */

#ifndef CHAIN_H
#define CHAIN_H

// std libraries:
#include <vector>
#include <type_traits>
// project headers:
#include "Chain_Base.h"

using namespace std;

template <class T> 
class Chain : public Chain_Base {
    protected:
        void print(ostream&) const override;
    public:
        // constructors
        Chain();
        Chain(istream&, const CardFactory*) {};
        // member functions
        int sell() override;
        size_t getSize() {return this->chain.size();}
        // operators
        Chain<T>& operator+= (Card*) override;
        Card* operator[] (int i) {return this->chain[i];}
        // friend ostream& operator<< (ostream&, const Chain<T>&) {};
};

template <class T>
Chain<T>::Chain() {
    T card; 
    this->name = card.getName();
    this->type = typeid(T).name();
}

/**
 * @brief Counts the number cards in the current chain and returns the number coins 
 *        according to the function {Card::getCardsPerCoin}. 
 * @return The price of this chain
 */
template <class T>
inline int Chain<T>::sell() {
    T card;
    for(int i=1; i<5; i++) {
        if (chain.size() < card.getCardsPerCoin(i))
            return i-1;
        else if (chain.size()==card.getCardsPerCoin(i))
            return i;
    }
    return 0;
}

/**
 * @brief Adds a card to the Chain. If the run-time type does not match the template type of the chain and 
 *        exception of type IllegalType will be raised.
 * @return A pointer of this chain
 * @throw IllegalTypeException() if type mismatched
 */
template <class T>
inline Chain<T>& Chain<T>::operator+= (Card* card){
    if (this->match(card)) return *this;
    else throw IllegalTypeException();
}

/**
 * @brief Inserts the first character for the card to an std::ostream
 * @param out An ostream
*/
template <class T>
void Chain<T>::print(ostream& os) const {
    os << chain[0]->getName() << "  ";
    for(auto& card: this->chain) 
        os << *card << " ";
}

#endif