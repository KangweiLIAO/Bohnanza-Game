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
 *  - void trade(Player*)
 *  - int numCards()
 *  - void discardAll(DiscardPile*)
 *  - void ave(ostream&)
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
        void save(ostream& os);
        
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
    string line;
    while(getline(is,line)) {
        auto delimiterPos = line.find("=");
        string type;
        string key = line.substr(0, delimiterPos);
        string value = line.substr(delimiterPos + 1);
        if(key=="trade"){
            istringstream buff(line);
            while(buff>>type) {
                if (type=="R") area.push_back(new Red());
                else if (type=="C") area.push_back(new Chili());
                else if (type=="G") area.push_back(new Green());
                else if (type=="B") area.push_back(new Blue());
                else if (type=="S") area.push_back(new Stink());
                else if (type=="g") area.push_back(new Garden());
                else if (type=="s") area.push_back(new Soy());
                else if (type=="b") area.push_back(new Black());
                type.clear();
            }
        }
        break;
    } 
}

/**
 * @brief Returns number of cards in trade area
 * @return Number of cards
 */
inline int TradeArea::numCards() {return area.size();}

/**
 * @brief Returns true if the card can be legally added to the TradeArea, 
 *        i.e. a card of the same bean is already in the TradeArea.
 * @param c A card that will be tested
 * @return Legality of the card
 */
inline bool TradeArea::legal(const Card* c) {
    for(auto const& card: area)
        if (card->getName()==c->getName()) return true;
    return false;
}

/**
 * @brief Discard all cards in trade area.
 * @param pile Discard pile
 */
inline void TradeArea::discardAll(DiscardPile* pile) {
    for (auto& card: area) *pile += card;
    area.clear();
}

/**
 * @brief Removes a card of the corresponding bean name from the trade area.
 * @param s A string which is the card name
 */
Card* TradeArea::trade(string s) {
    int index = 0;
    for (Card* card: area) {
        if (card->getName()==s) {
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


/**
 * @brief Write the info of trade area to ostream.
 * @param os An ostream
 */
void TradeArea::save(ostream& os){
    os << "trade= ";
    list<Card*>::iterator iter;
    for(iter = area.begin(); iter!=area.end(); iter++) 
        os << **iter << " ";
}

#endif