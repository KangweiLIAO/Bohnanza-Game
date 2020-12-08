/**
 * @file: MyException.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class holds the user-defined exceptions
 * 
 * Exceptions:
 * - CardNotFoundException
 * - DeckEmptyException
 * - Illegal Type Exception
 * - NotEnoughCoinsException
 */

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>

using namespace std;

/**
 * @brief Rasise when a card is not found.
 * @return Return an exception
*/
struct CardNotFoundException : public std::exception {
	const char * what() const throw () {
    	return "Card Not Found Exception - The given index exceeded deck number.";
    }
};

/**
 * @brief Raise when taking a card from an empty deck.
 * @return Return an exception
*/
struct DeckEmptyException : public exception {
	const char * what() const throw () {
    	return "Deck Empty Exception - Taking card from empty deck.";
    }
};

/**
 * @brief Raise when a run-time type does not match the template type of the chain.
 * @return Return an exception
*/
struct IllegalTypeException : public exception {
	const char * what() const throw () {
    	return "Illegal Type Exception - Run-time type does not match the template type of the chain.";
    }
};

/**
 * @brief Raise when there is not enough coins.
 * @return Return an exception
*/
struct NotEnoughCoinsException : public exception {
	const char * what() const throw () {
    	return "Not Enough Coins Exception - No enough coins for new chain.";
    }
};

/**
 * @brief Raise when there is not enough coins.
 * @return Return an exception
*/
struct MaxChainReachedException : public exception {
	const char * what() const throw () {
    	return "Max Chain Reached Exception - The maximum number of chains is reached, no more new chains allowed.";
    }
};

#endif