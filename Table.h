/**
 * @file: Table.h
 * Group 8:
 *      Kangwei Liao: 8568800
 *      Langqing Zou: 300035036
 * @brief
 * This class will hold two objects of type Player, the Deck and the 
 * DiscardPile, as well as the TradeArea.
 * 
 * Methods:
 * - Table(istream&, const CardFactory*)
 * - bool win(string&)
 * - void printHand(bool)
 * - friend ostream& operator<<(ostream&,const Table&)
 */

#ifndef TABLE_H
#define TABLE_H

// std libraries:

// project headers:
#include "DiscardPile.h"
#include "TradeArea.h"
#include "Player.h"

using namespace std;

class Table{
    private:
        static CardFactory* factory;
        Deck deck;
        Player* player1;
        Player* player2;
        TradeArea* tradeArea;
        DiscardPile* discardPile;
    public:
        Table(string, string);
        Table(istream&, const CardFactory*);
        bool win(string&);
        void printHand(bool);
        friend ostream& operator<<(ostream&,const Table&);
};

CardFactory* Table::factory {CardFactory::getFactory()};

Table::Table(string name1, string name2) {
    deck = factory->getDeck();
    player1 = new Player(name1);
    player2 = new Player(name2);
    discardPile = new DiscardPile();
    tradeArea = new TradeArea();
}

/**
 * @brief A constructor which accepts an istream and reconstruct the Table from file.
 * @param is An istream address
 * @param factory A const CardFactory
*/
Table::Table(istream& is, const CardFactory* factory) {
    Player player(is,factory);
    DiscardPile pile(is,factory);
    TradeArea area(is,factory);
}

/**
 * @brief Returns true when a player has won.
 * @param s The address of the name of player
*/
inline bool Table::win(string& name){
    if(deck.numCards() == 0) {
        if (player1->getName()==name) name = player1->getName();
        else name = player2->getName();
        return true;
    }
    return false;
}

/**
 * @brief Prints the top card of the player's hand (with argument false) 
 * or all of the player's hand (with argument true)
 * @param flag a boolean
*/

void Table::printHand(bool flag){
    cout << player1->getName() << " ";
    player1->printHand(cout,flag);
    cout << "\n" << player2->getName() << " ";
    player2->printHand(cout,flag);
}

/**
 * @brief Insert table to an std::ostream.
 * @param os An ostream
 * @param player A table needs to be printed
*/
ostream& operator<<(ostream& os, const Table& table) {
    os << *table.tradeArea << endl;
    os << *table.discardPile << endl;
    os << "Player1: " << *table.player1 << endl;
    os << "Player2: " << *table.player2 << endl;
    return os;
}

#endif