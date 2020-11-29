/**
 * File: CardFactory.h
 * Group 8:
 *      Kangwei Liao: 8568800; 
 *      Langqing Zou: 300035036
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
        static CardFactory* getFactory();
        Deck getDeck() {return deck;}
        // operators:
        void operator=(const CardFactory&) = delete;
};

CardFactory::CardFactory() {
    deck = Deck();
    for (int i=0; i<20; i++) {
        deck.push_back(new Black());
        if (i < 18) deck.push_back(new Blue());
        if (i < 16) deck.push_back(new Chili());
        if (i < 14) deck.push_back(new Garden());
        if (i < 12) deck.push_back(new Green());
        if (i < 10) deck.push_back(new Red());
        if (i < 8) deck.push_back(new Soy());
        if (i < 6) deck.push_back(new Stink());
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(),deck.end(),std::default_random_engine(seed));
}

CardFactory::~CardFactory() {

}

#endif