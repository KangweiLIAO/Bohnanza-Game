#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>

using namespace std;

// when a card is not found by index, throw:
struct CardNotFoundException : public std::exception {
	const char * what() const throw () {
    	return "Card Not Found Exception - The given index exceeded deck number.";
    }
};

// when taking a card from an empty deck, throw:
struct DeckEmptyException : public exception {
	const char * what() const throw () {
    	return "Deck Empty Exception - Taking card from empty deck.";
    }
};

#endif