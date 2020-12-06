/**
 * @file: CardFactory.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
 * 
 * @brief
 * This class is a factory class for cards.
 * 
 * Methods: 
 *  - CardFactory()
 *  - static CardFactory* getFactory()
 *  - Deck getDeck()
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
        static CardFactory* factory;
        static Deck deck;
        CardFactory();
        CardFactory(const CardFactory&);
        void operator=(const CardFactory&);
    public:
        ~CardFactory();
        static CardFactory* getFactory();
        Deck getDeck();
};

// Static variable initializations:
CardFactory* CardFactory::factory {nullptr};
Deck CardFactory::deck {Deck()};

/**
 * @brief A default constructor in which all the cards need to be created in the numbers needed for the game.
 */
CardFactory::CardFactory() {
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

/**
 * @brief The destructor of Cardfactory.
 */
CardFactory::~CardFactory() {}

/**
 * @brief Returns a pointer to the only instance of CardFactory.
 */
inline CardFactory* CardFactory::getFactory() {
    if (factory==nullptr) factory = new CardFactory();
    return factory;
}

/**
 * @brief Returns a shuffled deck with all 104 bean cards.
 */
inline Deck CardFactory::getDeck() {return deck;}

#endif