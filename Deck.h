/**
 * File: Deck.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 */

#ifndef DECK_H
#define DECK_H

// std libraries:
#include <algorithm>    // for shuffle() algorithm
#include <vector>
// project headers:
#include "CardFactory.h"

using namespace std;

class CardFactory;
class Deck : public vector<Card> {
    private :
        int num_cards;          // number of card in deck
        vector<Card> deck;      // hold cards
        const CardFactory* factory; 
        
    public:
        Deck(istream& is, const CardFactory* f):factory(f) {};
        int numCards() {return num_cards;} 
        Card* draw();
};

// When a card is not found by index, throw:
struct CardNotFoundException : public std::exception {
	const char * what() const throw () {
    	return "Card Not Found Exception - The given index exceeded deck number.";
    }
};

// When taking card from an empty deck, throw:
struct DeckEmptyException : public std::exception {
	const char * what() const throw () {
    	return "Deck Empty Exception - Taking card from empty deck.";
    }
};

Card* Deck::draw() {

    // If card not found, throw:
    throw DeckEmptyException();
}

#endif