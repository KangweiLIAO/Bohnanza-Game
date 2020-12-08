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
#include <chrono>
#include <sstream>
#include <algorithm>    // for shuffle()
// project headers:
#include "Cards/Cards.h"
#include "Deck.h"

using namespace std;

class CardFactory{
    private:
        static CardFactory* factory;
        Deck deck;
        CardFactory();
        CardFactory(istream&);
        void operator=(const CardFactory&);
    public:
        ~CardFactory();
        static CardFactory* getFactory();
        static CardFactory* getFactory(istream&);
        Deck getDeck() {return deck;}
        void save(ostream&);
};

// Static variable initializations:
CardFactory* CardFactory::factory {nullptr};

/**
 * @brief A default constructor in which all the cards need to be created in the numbers needed for the game.
 */
CardFactory::CardFactory() {
    // construct a new deck
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

/**
 * @brief A reconstructor in which all the cards reconstruct for the saved game.
 */
CardFactory::CardFactory(istream& is) {
    deck = Deck(is,this);
    string line,type;
    getline(is,line);
    istringstream buff(line);
    while (buff >> type){
        if (type == "R") deck.push_back(new Red());
        else if (type == "C") deck.push_back(new Chili());
        else if (type == "G") deck.push_back(new Green());
        else if (type == "B") deck.push_back(new Blue());
        else if (type == "S") deck.push_back(new Stink());
        else if (type == "g") deck.push_back(new Garden());
        else if (type == "type") deck.push_back(new Soy());
        else if (type == "b") deck.push_back(new Black());
        type.clear();
    }
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
 * @brief Returns a pointer to the only instance of CardFactory.
 */
inline CardFactory* CardFactory::getFactory(istream& is) {
    if (factory==nullptr) factory = new CardFactory(is);
    return factory;
}

void CardFactory::save(ostream& os) {
    for (Card* card: deck) os << *card;
}

#endif