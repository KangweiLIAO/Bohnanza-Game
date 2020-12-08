/**
 * File: Chain_Base.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 */

#ifndef CHAIN_BASE_H
#define CHAIN_BASE_H

// std libraries:
// project headers:
#include "CardFactory.h"

class Chain_Base {
    protected:
        string name;
        string type;
        vector<Card*> chain;
        virtual void print(ostream&) const = 0;
    public:
        const char getName();
        bool match(Card* c);
        ostream& save(ostream&);
        virtual int sell() = 0;
        virtual Chain_Base& operator+= (Card*) = 0;
        friend ostream& operator<< (ostream&, const Chain_Base&);
};

/**
 * @brief Return the name of a chain
 * @return chain's name
 */
inline const char Chain_Base::getName() {return name.at(0);}

/**
 * @brief Try match the card with this chain and add to it.
 * @return true if matched, false otherwise.
 */
inline bool Chain_Base::match(Card* card) {
    if (type==typeid(*card).name()) {
      chain.push_back(card);
      return true;
    } else return false;
}

ostream& Chain_Base::save(ostream& os) {
    os << *chain[0] << " " << chain.size();
}

ostream& operator<< (ostream& os, const Chain_Base& chain) {
    chain.print(os);
    return os;
}

#endif