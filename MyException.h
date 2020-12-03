/**
 * File: MyException.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * Description:
 * This class holds the user-defined exceptions
 * 
 * Exceptions:
 * - CardNotFoundException
 * 		Rasise when a card is not found.
 * - DeckEmptyException
 * 		Raise when taking a card from an empty deck.
 * - Illegal Type Exception
 * 		Raise when a run-time type does not match the template type of the chain.
 */

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>

using namespace std;

struct CardNotFoundException : public std::exception {
	const char * what() const throw () {
    	return "Card Not Found Exception - The given index exceeded deck number.";
    }
};

// , throw:
struct DeckEmptyException : public exception {
	const char * what() const throw () {
    	return "Deck Empty Exception - Taking card from empty deck.";
    }
};

struct IllegalTypeException : public exception {
	const char * what() const throw () {
    	return "Illegal Type Exception - Run-time type does not match the template type of the chain.";
    }
};

struct NotEnoughCoinsException : public exception {
	const char * what() const throw () {
    	return "Not Enough Coins Exception - No enough coins for new chain.";
    }
};

#endif