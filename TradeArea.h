/**
 * @file: TradeArea.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class holds the discard pile for a table. DiscardPile support insertion and removal 
 * but not at random locations but all at the end.
 * 
 * Methods:
 *  - TradeArea(istream&, const CardFactory*)
 *  - TradeArea& operator+=(Card*)
 *  - bool legal(Card*)
 *  - Card* trade(string)
 *  - int numCards()
 *  - friend ostream& operator<< (ostream&, const DiscardPile&)
 */

#ifndef TRADEAREA_H
#define TRADEAREA_H

// std libraries:
#include <list>
// project headers:
#include "CardFactory.h"

using namespace std;

class TradeArea{
    private:
        list<Card*> area;
    public:
        // constructors
        TradeArea() {};
        TradeArea(istream&, const CardFactory*);
        // member functions
        int numCards();
        bool legal(Card*);
        Card* trade(string);
        // operators
        TradeArea& operator+= (Card* c);
        friend ostream& operator<< (ostream&, const TradeArea&);
};

/**
 * @brief A constructor which accepts an istream and reconstruct the TradeArea from file.
 * @param is An istream address
 * @param factory A const CardFactory
 */
TradeArea::TradeArea(istream& is, const CardFactory* factory) {
    //TradeArea Garden Garden Stink Red Soy
    Deck deck = factory->getFactory()->getDeck();
    string array[128];
    string line,s;
    getline(is,line);
    istringstream buff(line);
    int i=0,k=1;
    while(buff>>s){
        array[i++]=s;
    }
    TradeArea area;
    while(array[k]!=""){
        for(int i=0;i<104;i++){
            if(typeid(deck[i]).name()==array[k]){
                area.operator+=(deck[i]);
                deck.erase(deck.begin()+i-1);
                break;
            }
        }
        k++;
    }

}

/**
 * @brief Returns true if the card can be legally added to the TradeArea, 
 *        i.e. a card of the same bean is already in the TradeArea.
 * @param c A card that will be test
 */
inline bool TradeArea::legal(Card* c) {
    for(auto& card: area)
        if(card->getName() == c->getName()) return true;
    return false;
}

inline int TradeArea::numCards() {return area.size();}

/**
 * @brief removes a card of the corresponding bean name from the trade area.
 * @param s A string which is the card name
 */
inline Card* TradeArea::trade(string s) {
    int index = 0;
    for (Card* card: area) {
        index++;
        if(card->getName() == s) {
            Card* c = card;
            list<Card*>::iterator iter = area.begin();
            advance(iter,index);
            area.erase(iter);
            return card;
        }
    }
    return nullptr;
}

/**
 * @brief Adds the card to the trade area but does not check if it is legal to place the card.
 * @param card A card needs to be added
 */
inline TradeArea& TradeArea::operator+= (Card* card) {
    area.push_back(card);
    return *this;
}

/**
 * @brief Insert all the cards of the trade area to an std::ostream.
 * @param os An ostream
 * @param tradeArea A tradeArea needs to be printed
 */
inline ostream& operator<< (ostream& os, const TradeArea& tradeArea) {
    if (tradeArea.area.size() == 0) os << "Empty";
    else {
        for(auto& card: tradeArea.area) 
            os << *card << " ";
    }
    return os;
}

#endif