/**
 * @file: DiscardPile.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class holds the discard pile for a table. DiscardPile support insertion and removal 
 * but not at random locations but all at the end.
 * 
 * Methods:
 *  - DiscardPile(istream&, const CardFactory*) 
 *  - DiscardPile& operator+=(Card*)
 *  - Card* pickUp()
 *  - Card* top()
 *  - void print(std::ostream&)
 *  - friend ostream& operator<< (ostream&, const DiscardPile&)
 */

#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H

// std libraries:
#include <vector>
// project headers:
#include "CardFactory.h"
#include "MyException.h"

using namespace std;

class DiscardPile {
    private:
        vector<Card*> pile;      // hold discarded cards
        const CardFactory* factory;
    public:
        // constructors:
        DiscardPile() {};
        DiscardPile(istream&, const CardFactory*);
        // member functions:
        Card* pickUp();
        bool isEmpty();
        Card* top() const;
        void print(ostream&);
        // operators:
        DiscardPile& operator+=(Card*);
        friend ostream& operator<< (ostream&, const DiscardPile&);
};

/**
 * @brief A constructor which accepts an istream and reconstruct the DiscardPile from file.
 * @param is An istream address
 * @param factory A const CardFactory
 */
DiscardPile::DiscardPile(istream& is, const CardFactory* factory) {
    Deck deck = factory->getFactory()->getDeck();
    string array[104];
    string line,s;
    getline(is,line);
    istringstream buff(line);
    int i=0,k=1;
    while(buff>>s){
        array[i++]=s;
    }
    for(int k=0;k<104;k++){
        if(array[k]=="R"){
            pile.push_back(new Red());
        }else if(array[k]=="C"){
            pile.push_back(new Chili());
        }else if(array[k]=="G"){
            pile.push_back(new Green());
        }else if(array[k]=="B"){
            pile.push_back(new Blue());
        }else if(array[k]=="S"){
            pile.push_back(new Stink());
        }else if(array[k]=="g"){
            pile.push_back(new Garden());
        }else if(array[k]=="s"){
            pile.push_back(new Soy());
        }else if(array[k]=="b"){
            pile.push_back(new Black());
        }
    }
}

inline bool DiscardPile::isEmpty() {
    if (pile.size() == 0) return true;
    return false;
}

inline Card* DiscardPile::top() const {
    if (pile.size() != 0)
        return pile.back();
    else throw DeckEmptyException();
}

/**
 * @brief Returns and removes the top card from the discard pile.
 */
inline Card* DiscardPile::pickUp() {
    Card* c = pile.back();  // top card == last elem
    pile.pop_back();
    return c;
}

/**
 * @brief Insert all the cards in the DiscardPile to an std::ostream.
 * @param os An ostream address
 */
void DiscardPile::print(ostream& os) {
    const int size = pile.size();
    for (int i=0; i<size; i++) {
        os << *pile[i] << " ";
    }
}

/**
 * @brief Discards the card to the pile.
 * @param A Card needs to be discarded
 */
inline DiscardPile& DiscardPile::operator+= (Card* card) {
    pile.push_back(card);
    return *this;
}

/**
 * @brief Insert only the top card of the discard pile to an std::ostream.
 * @param os An ostream
 * @param pile A discardpileneeds to be printed
*/
inline ostream& operator<< (ostream& os, const DiscardPile& pile) {
    try {os << *(pile.top());}
    catch (DeckEmptyException e) {os << "Empty";}
    return os;
}

#endif
