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
        // static CardFactory* factory;
        Deck deck;
        TradeArea* tradeArea;
        DiscardPile* discardPile;
        Player* player1;
        Player* player2;
    public:
        Table(string&,string&,const CardFactory*);
        Table(istream&,const CardFactory*);

        bool win(string&);
        void printHand(bool);

        Player* getPlayer(int);
        TradeArea* getTradeArea();
        DiscardPile* getDiscardPile();
        ostream& save(ostream&);
        
        friend ostream& operator<< (ostream&,const Table&);
};

/**
 * @brief A constructor which accepts an istream and reconstruct the Table from file.
 * @param is An istream address
 * @param factory A const CardFactory
*/
Table::Table(istream& is, const CardFactory* factory) {
    tradeArea = new TradeArea(is,factory);
    discardPile = new DiscardPile(is,factory);
    player1 = new Player(is,factory);
    player2 = new Player(is,factory);
}

Table::Table(string& name1, string& name2, const CardFactory* factory) {
    deck = factory->getFactory()->getDeck();
    player1 = new Player(name1);
    player2 = new Player(name2);
    discardPile = new DiscardPile();
    tradeArea = new TradeArea();
}

inline TradeArea* Table::getTradeArea() {return tradeArea;}

inline DiscardPile* Table::getDiscardPile() {return discardPile;}

inline Player* Table::getPlayer(int i) {
    if (i==1) return player1;
    else return player2;
}

/**
 * @brief Prints the top card of the player's hand (with argument false) 
 *        or all of the player's hand (with argument true)
 * @param flag a boolean
*/
void Table::printHand(bool flag) {
    cout << player1->getName() << ": ";
    player1->printHand(cout,flag);
    cout << endl << player2->getName() << ": ";
    player2->printHand(cout,flag);
}

/**
 * @brief Returns true when a player has won.
 * @param s The address of the name of player
*/
inline bool Table::win(string& name) {
    if (player1->getName()==name && player1->getNumCoins() >= player2->getNumCoins())
        return true;
    else if (player2->getName()==name && player2->getNumCoins() >= player1->getNumCoins())
        return true;
    return false;
}

/**
 * @brief Insert table to an std::ostream.
 * @param os An ostream
 * @param player A table needs to be printed
*/
ostream& operator<<(ostream& os, const Table& table) {
    os << "---------- Trade Area ----------\n" << *table.tradeArea << endl;
    os << "---------- Discard Pile (top) ----------\n" << *table.discardPile << endl;
    os << "---------- Player1 ----------\n" << *table.player1 << endl;
    os << "---------- Player2 ----------\n" << *table.player2 << endl;
    return os;
}

/**
 * @brief Write the table info into ostream
 * @param os An ostream
 * @param player A ostream
*/
ostream& Table::save(ostream& os){
    ostream& os2 = tradeArea->save(os);
    os2 <<"\n";
    ostream & os3 = discardPile->save(os2);
    os3 <<"\n";
    ostream & os4 = player1->save(os4);
    os4 <<"\n";
    return os4;
}



#endif