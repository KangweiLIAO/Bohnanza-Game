/**
 * File: Deck.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * Description:
 * This class inherit from {std::vector<Card*>} and holds the unique deck for the game. 
 * 
 * Methods: 
 *  - Deck()
 *  - Deck(istream&, const CardFactory*)
 *  - Card* draw()
 *  - friend ostream& operator<< (ostream&, const Deck&)
 */

#ifndef DECK_H
#define DECK_H

// std libraries:
#include <vector>
// project headers:
#include "CardFactory.h"
#include "MyException.h"

using namespace std;

class CardFactory;

class Deck : public vector<Card*> {
    private:
        static vector<Card*> deck;
        const CardFactory* factory; 
    public:
    /**
    @brief a default constructor which using constructor from vector.
    */
        Deck() : vector<Card*>::vector(0) {};
        Deck(istream& is, const CardFactory* f);
        int numCards() {return this->size();}
        Card* draw();
        friend ostream& operator<< (ostream& os, const Deck& deck);
};

//TODO: Implement constructor that can read from istream
/**
 * @brief A constructor which accepts an istream and reconstruct the Deck from file.
 * @param is An istream address
 * @param factory A const CardFactory
*/
Deck::Deck(istream& is, const CardFactory* f) : factory(f) {
    
}

/**
 * @brief returns and removes the top card from the deck.
*/
Card* Deck::draw() {
    // If card not found, throw:
    if (this->size() == 0) throw DeckEmptyException();
    else {
        Card* c = this->back();
        this->pop_back();
        return c;  // top card == last elem of the vector
    }
}

/**
 * @brief insert all the cards in the deck to an std::ostream.
 * @param os An ostream
 * @param tradeArea A deck needs to be printed
*/
inline ostream& operator<< (ostream& os, const Deck& deck) {
    // insert all cards to ostream
    const int size = deck.size();
    for (int i=0; i<size; i++) {
        os << *deck[i] << " ";
    }
    return os;
}

#endif