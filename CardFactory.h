/**
 * @file: CardFactory.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 * Description:
 * This class is a factory class for cards.
 * 
 * Methods: 
 *  - CardFactory()
 *      a default constructor in which all the cards need to be created in the numbers needed for the game.
 *  - static CardFactory* getFactory()
 *      returns a pointer to the only instance of CardFactory.
 *  - Deck getDeck()
 *      Deck getDeck() returns a shuffled deck with all 104 bean cards.
 */

#ifndef CARDFACTORY_H
#define CARDFACTORY_H
// std libraries:
#include <random>
#include <algorithm>    // for shuffle()
// project headers:
#include "Cards/Cards.h"
#include "Deck.h"

using namespace std;

class CardFactory{
    private:
        Deck deck;
    public:
        CardFactory();      // constructor
        ~CardFactory();     // destructor
        CardFactory(const CardFactory&) = delete;
        static CardFactory* getFactory();           // TODO: Implement getFactory()
        Deck getDeck() {return deck;}
        // operators:
        void operator=(const CardFactory&) = delete;
};

/// default constructor
CardFactory::CardFactory() {
    deck = Deck();
    for (int i=0; i<20; i++) {
        deck.push_back(new Blue());
        if (i < 18) deck.push_back(new Chili());
        if (i < 16) deck.push_back(new Stink());
        if (i < 14) deck.push_back(new Green());
        if (i < 12) deck.push_back(new Soy());
        if (i < 10) deck.push_back(new Black());
        if (i < 8) deck.push_back(new Red());
        if (i < 6) deck.push_back(new Garden());
    }
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(),deck.end(),std::default_random_engine(seed));
}

/// destructor
CardFactory::~CardFactory() {
    
}

#endif