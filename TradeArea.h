/**
 * File: TradeArea.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 */

#ifndef TRADEAREA_H
#define TRADEAREA_H

// std libraries:
#include <list>
// project headers:
#include "Table.h"

using namespace std;

class TradeArea{
    private:
        int num_cards;
    public:
        TradeArea();
        int numCards() {return num_cards;}
        Card* trade(string);
        bool legal(Card*);
        TradeArea& operator+= (Card*);
        friend ostream& operator<< (ostream&,const TradeArea&);
};

// constructor
TradeArea::TradeArea() {

}

inline ostream& operator<< (ostream& os, const TradeArea& t) {
    return os;
}

#endif