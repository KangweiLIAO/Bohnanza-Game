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
#include "DiscardPile.h"
#include "Player.h"

using namespace std;

class TradeArea{
    private:
        list<Card*> area;
    public:
        // constructors
        TradeArea() {}
        TradeArea(istream&, const CardFactory*);

        // member functions
        int numCards();
        void trade(Player*);
        Card* trade(string);
        bool legal(const Card*);
        void discardAll(DiscardPile*);
        
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
    Deck deck = factory->getFactory()->getDeck();
    string array[104];
    string line,s;
    getline(is,line);
    istringstream buff(line);
    int i=0;
    while(buff>>s){
        array[i++]=s;
    }
    for(int k=0;k<104;k++){
        if(array[k]=="R"){
            area.push_back(new Red());
        }else if(array[k]=="C"){
            area.push_back(new Chili());
        }else if(array[k]=="G"){
            area.push_back(new Green());
        }else if(array[k]=="B"){
            area.push_back(new Blue());
        }else if(array[k]=="S"){
            area.push_back(new Stink());
        }else if(array[k]=="g"){
            area.push_back(new Garden());
        }else if(array[k]=="s"){
            area.push_back(new Soy());
        }else if(array[k]=="b"){
            area.push_back(new Black());
        }
    }

}

/**
 * @brief Returns number of cards in trade area
 * @return number of cards
 */
inline int TradeArea::numCards() {return area.size();}

/**
 * @brief Returns true if the card can be legally added to the TradeArea, 
 *        i.e. a card of the same bean is already in the TradeArea.
 * @param c A card that will be tested
 * @return legality of the card
 */
inline bool TradeArea::legal(const Card* c) {
    for(auto const& card: area)
        if(card->getName()==c->getName()) return true;
    return false;
}

/**
 * @brief Discard all cards in trade area.
 * @param pile discard pile
 */
inline void TradeArea::discardAll(DiscardPile* pile) {
    for (auto& card: area) *pile += card;
    area.clear();
}

/**
 * @brief removes a card of the corresponding bean name from the trade area.
 * @param s A string which is the card name
 */
Card* TradeArea::trade(string s) {
    int index = 0;
    for (Card* card: area) {
        if(card->getName()==s) {
            Card* c = card;
            // remove the card in area:
            list<Card*>::iterator iter = area.begin();
            advance(iter,index);
            area.erase(iter);
            return card;
        }
        index++;
    }
    return nullptr;
}

/**
 * @brief Prompt player to make decision on each card in trade area.
 * @param player A player
 */
void TradeArea::trade(Player* player) {
    string* buff = new string();
    int index = 0;
    bool erase = true;
    for (Card* card: area) {
        readStringInput("("+player->getName()+") Do you want to chain the card: "+card->getName()+" (y/n)? ", buff);
        if (*buff=="y") {
            if (!player->cardMatch(card)) {
                readStringInput("("+player->getName()+") Do you want to create a new chain to match this card? (y/n): ", buff);
                if (*buff=="y") {
                    if (player->createChain(card)==nullptr) erase = false;
                    else cout << "(" << player->getName() << ") New " << card->getName() << " chain created." << endl;
                } else erase = false;
            } else cout << "(" << player->getName() << ") Card added to a chain." << endl;
            if (erase) {
                list<Card*>::iterator iter = area.begin();
                advance(iter,index);
                area.erase(iter);
                index--;
            }
        }
        index++;
    }
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
ostream& operator<< (ostream& os, const TradeArea& tradeArea) {
    if (tradeArea.area.size()==0) os << "Empty";
    else {
        for(auto& card: tradeArea.area) 
            os << *card << " ";
    }
    return os;
}

#endif