/**
 * @file: TradeArea.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * @brief
 * This class holds the discard pile for a table. DiscardPile support insertion and removal 
 * but not at random locations but all at the end.
 * 
 * Methods:
 *  - TradeArea(istream&, const CardFactory*)
 *      a constructor which accepts an istream and reconstruct the TradeArea from file.
 *  - TradeArea& operator+=(Card*)
 *      adds the card to the trade area but it does not check if it is legal to place the card.
 *  - bool legal(Card*)
 *      returns true if the card can be legally added to the TradeArea, i.e., a card of the same bean is already in the TradeArea.
 *  - Card* trade(string)
 *      removes a card of the corresponding bean name from the trade area.
 *  - int numCards()
 *      returns the number of cards currently in the trade area.
 *  - friend ostream& operator<< (ostream&, const DiscardPile&)
 *      insert all the cards of the trade area to an std::ostream.
 */

#ifndef TRADEAREA_H
#define TRADEAREA_H

// std libraries:
#include <list>
// project headers:
#include "CardFactory.h"

using namespace std;

class TradeArea{
    public:
        list<Card*> area;
        // constructors
        TradeArea() {};
        TradeArea(istream&, const CardFactory*);
        // member functions
        int numCards() {return area.size();}
        bool legal(Card*);
        Card* trade(string);
        // operators
        TradeArea& operator+= (Card* c);
        friend ostream& operator<< (ostream&, const TradeArea&);
};

// constructor
TradeArea::TradeArea(istream& is, const CardFactory* factory) {

}

inline bool TradeArea::legal(Card* card) {
    for(auto& c: area)
        if(c->getName() == card->getName()) return true;
    return false;
}

inline Card* TradeArea::trade(string s) {
    for(auto& card: area)
        if(card->getName() == s) return card;
    return nullptr;
}

inline TradeArea& TradeArea::operator+= (Card* card) {
    area.push_back(card);
    return *this;
}

inline ostream& operator<< (ostream& os, const TradeArea& tradeArea) {
    for(auto& card: tradeArea.area) 
        os << *card;
    return os;
}

#endif