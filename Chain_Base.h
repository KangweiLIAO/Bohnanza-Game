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
        vector<Card*> chain;
        virtual void print(ostream&) const = 0;
    public:
        virtual int sell() = 0;
        friend ostream& operator<< (ostream&, const Chain_Base&);
};

ostream& operator<< (ostream& os, const Chain_Base& chain) {
  chain.print(os);
  return os;
}

#endif